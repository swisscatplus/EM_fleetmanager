import json
from typing import Optional

from nodes.EMRetrieve import GetAvailableEM, GetStationEM
from nodes.StationMovement import GoToStation, StationToStation

from task_scheduler.nodes.base import BaseNode
from task_scheduler.orchestrator.base import BaseOrchestrator
from task_scheduler.orchestrator.enums import OrchestratorErrorCodes
from task_scheduler.workflow.core import Workflow


class EMOrchestrator(BaseOrchestrator):
    """An example of implementation can be found in the Omnifire or Robot Scheduler repository"""
    
    def _load_workflows(self, path: str) -> OrchestratorErrorCodes:
        """Populate the list of workflows: `self.workflows` by parsing the workflow config file"""
        try:
            data = json.load(open(path, "r"))
            workflows = data.get("workflows", [])
        except FileNotFoundError:
            return OrchestratorErrorCodes.COULD_NOT_FIND_CONFIGURATION
        except json.decoder.JSONDecodeError:
            return OrchestratorErrorCodes.COULD_NOT_PARSE_CONFIGURATION

        for fake_id, workflow in enumerate(workflows):
            wf_name = workflow["name"]
            wf_steps_tpl = [(node_name, self._find_node_by_id(node_name)) for node_name in workflow["steps"]]
            nodes_not_found = [node_name for (node_name, step) in wf_steps_tpl if step is None]

            # Skip workflow when some nodes do not exist
            if len(nodes_not_found) > 0:
                not_found_nodes_str = ", ".join(nodes_not_found)
                self.logger.error(f"Nodes [{not_found_nodes_str}] not found. Skipping workflow '{wf_name}'")
                continue
                
        wf_steps = [node for (_, node) in wf_steps_tpl]

        self.logger.debug(f"Loaded workflow: {0} with following name: {1} and steps: {2}".format(fake_id, wf_name, wf_steps))

        self.workflows.append(Workflow(fake_id, wf_name, wf_steps))

        return OrchestratorErrorCodes.OK
    
    def _load_nodes(self, path: str) -> OrchestratorErrorCodes:
        """Populate the list of nodes: `self.nodes` by parsing the node config file"""
        try:
            data = json.load(open(path, "r"))
            nodes = data.get("nodes", [])
        except FileNotFoundError:
            return OrchestratorErrorCodes.COULD_NOT_FIND_CONFIGURATION
        except json.decoder.JSONDecodeError:
            return OrchestratorErrorCodes.COULD_NOT_PARSE_CONFIGURATION
        
        for node in nodes:
            _id = node["id"]
            name = node["name"]
            _type = node["type"]

        match _type:
            case "GetAvailableEM":
                self.nodes.append(GetAvailableEM(_id, name, node["ip"], node["args"]))
            case "GetStationEM":
                self.nodes.append(GetStationEM(_id, name, node["ip"], node["args"]))
            case "GoToStation":
                self.nodes.append(GoToStation(_id, name, node["ip"], node["args"]))
            case "StationToStation":
                self.nodes.append(StationToStation(_id, name, node["ip"], node["args"]))
            case _:
                self.logger.error(f"Node type {_type} not recognized. Skipping node {_id}")

        return OrchestratorErrorCodes.OK
    
    def _find_node_by_id(self, _id: str) -> Optional[BaseNode]:
        for node in self.nodes:
            if node.id == _id:
                return node
        return None