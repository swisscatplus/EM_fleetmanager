import json
from typing import Optional, IO

from src.nodes.RetrieveRobot import GetAvailable, GetAtStation
from src.nodes.MoveToStation import MoveToStation

from task_scheduler.nodes.base import BaseNode
from task_scheduler.orchestrator.base import BaseOrchestrator
from task_scheduler.orchestrator.enums import OrchestratorErrorCodes
from task_scheduler.workflow.core import Workflow
from task_scheduler.database import DatabaseConnector, DBWorkflow, DBStep, DBNode


class EMOrchestrator(BaseOrchestrator):
    """An example of implementation can be found in the Omnifire or Robot Scheduler repository"""
    
    def _load_workflows(self, file: IO) -> OrchestratorErrorCodes:
        """Populate the list of workflows: `self.workflows` by parsing the workflow config file"""
        
        try:
            workflows_json = json.loads(file.read()).get("workflows", [])
        except FileNotFoundError:
            return OrchestratorErrorCodes.COULD_NOT_FIND_CONFIGURATION
        except json.decoder.JSONDecodeError:
            return OrchestratorErrorCodes.COULD_NOT_PARSE_CONFIGURATION

        database = DatabaseConnector()
        for workflow in workflows_json:
            wf_name = workflow["name"]
            wf_steps_tpl = [(node_name, self._find_node_by_id(node_name)) for node_name in workflow["steps"]]
            self.logger.debug('wf_steps_tpl: {0}'.format(wf_steps_tpl))
            nodes_not_found = [node_name for (node_name, step) in wf_steps_tpl if step is None]

            # Skip workflow when some nodes do not exist
            if len(nodes_not_found) > 0:
                not_found_nodes_str = ", ".join(nodes_not_found)
                self.logger.error(f"Nodes [{not_found_nodes_str}] not found. Skipping workflow '{wf_name}'")
                continue
            
            wf_steps = [node for (_, node) in wf_steps_tpl]
            
            if not DBWorkflow.exists(database, wf_name):
                DBWorkflow.insert(database, wf_name, wf_steps[0].id, wf_steps[-1].id)

            db_workflow = DBWorkflow.get_by_name(database, wf_name)

            for pos, step in enumerate(wf_steps):
                DBStep.insert(database, db_workflow.id, step.id, pos)
                
            self.logger.debug(f"Loaded workflow: {db_workflow.name} with steps: {wf_steps} and id {db_workflow.id}")

            self.workflows.append(Workflow(db_workflow.id, db_workflow.name, wf_steps))

        return OrchestratorErrorCodes.OK
    
    def _load_nodes(self, file: IO) -> OrchestratorErrorCodes:
        """Populate the list of nodes: `self.nodes` by parsing the node config file"""
        try:
            nodes_json = json.loads(file.read()).get("nodes", [])
        except FileNotFoundError:
            return OrchestratorErrorCodes.COULD_NOT_FIND_CONFIGURATION
        except json.decoder.JSONDecodeError:
            return OrchestratorErrorCodes.COULD_NOT_PARSE_CONFIGURATION
        
        database = DatabaseConnector()

        for node in nodes_json:
            _id = node["id"]
            name = node["name"]
            _type = node["type"]

            DBNode.insert(database, _id, name)

            match _type:
                case "GET-AVAILABLE":
                    self.nodes.append(GetAvailable(_id, name))
                case "GET-AT-STATION":
                    self.nodes.append(GetAtStation(_id, name))
                case "MOVE-TO-STATION":
                    self.nodes.append(MoveToStation(_id, name))
                case _:
                    self.logger.error(f"Node type {_type} not recognized. Skipping node {_id}")

        return OrchestratorErrorCodes.OK
    
    def _find_node_by_id(self, _id: str) -> Optional[BaseNode]:
        for node in self.nodes:
            if node.id == _id:
                return node
        return None
    
    def add_task(self, workflow: Workflow, args: Optional[dict[str, any]] = None) -> TaskNoPause:
        database = DatabaseConnector()

        task = TaskNoPause(workflow, args)

        DBTask.insert(database, str(task.uuid), task.workflow.id, args)
        DBWorkflowUsageRecord.insert(database, workflow.id)

        task_thread = threading.Thread(
            name=f"task:{task.workflow.name}", target=task.run, args=(self._remove_finished_task,)
        )
        task_thread.start()
        self._running_tasks.append((task_thread, task))

        return task