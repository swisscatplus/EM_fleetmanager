from task_scheduler.orchestrator.base import BaseOrchestrator
from task_scheduler.orchestrator.enums import OrchestratorErrorCodes


class MyOrchestrator(BaseOrchestrator):
    """An example of implementation can be found in the Omnifire or Robot Scheduler repository"""
    
    def _load_workflows(self, path: str) -> OrchestratorErrorCodes:
        """Populate the list of workflows: `self.workflows` by parsing the workflow config file"""
        return OrchestratorErrorCodes.OK
    
    def _load_nodes(self, path: str) -> OrchestratorErrorCodes:
        """Populate the list of nodes: `self.nodes` by parsing the node config file"""
        return OrchestratorErrorCodes.OK