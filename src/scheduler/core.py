from fastapi import APIRouter

from orchestrator.core import EMOrchestrator
from task_scheduler.base import BaseScheduler
from fastapi import Response, status


class EMScheduler(BaseScheduler):
    def __init__(self, orchestrator: EMOrchestrator, port: int) -> None:
        super().__init__(orchestrator, port)

        self.orchestrator: EMOrchestrator = orchestrator
        self.bind_logger_name("EM Scheduler")

    def init_extra_routes(self) -> None:
        """
        This function is empty defined in the BaseScheduler.
        Add any additional router you want to define here.
        """
        self.init_my_extra_personalized_routes()

    def init_my_extra_personalized_routes(self) -> None:
        my_personalized_router = APIRouter(prefix="/my-prefix", tags=["My Personalized tags"])

        my_personalized_router.add_api_route("/navStatus", self._get_nav_status, methods=["GET"])
        self.api.include_router(my_personalized_router)

    def _get_nav_status(self, response: Response, task_id=None):
        if not self.orchestrator.is_running():
            self.logger.error("The orchestrator is not running")
            response.status_code = status.HTTP_418_IM_A_TEAPOT
            return
        
        for task in self.orchestrator.running_tasks:
            self.logger.info(f"Task: {task}")
            state = task[1].state
            self.logger.info(f"State: {state}")
            if state == task_id:
                if state.is_active():
                    self.logger.info(f"Task {task_id} is active")
                    response.status_code = status.HTTP_102_PROCESSING
                    return
                elif state.is_pending():
                    self.logger.info(f"Task {task_id} is pending")
                    response.status_code = status.HTTP_102_PROCESSING
                    return
                elif state.is_finished():
                    self.logger.info(f"Task {task_id} is finished")
                    response.status_code = status.HTTP_200_OK
                    return
                elif state.is_error():
                    self.logger.error(f"Task {task_id} has had an error")
                    response.status_code = status.WS_1011_INTERNAL_ERROR
                    return
                
        if self.orchestrator.running_tasks is None:
            self.logger.error("No tasks are running")
            response.status_code = status.HTTP_204_NO_CONTENT
            return