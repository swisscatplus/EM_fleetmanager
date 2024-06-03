from fastapi import APIRouter

from orchestrator.core import MyOrchestrator
from task_scheduler.base import BaseScheduler


class MyScheduler(BaseScheduler):
    def __init__(self, orchestrator: MyOrchestrator, port: int) -> None:
        super().__init__(orchestrator, port)

        self.orchestrator: MyOrchestrator = orchestrator
        self.bind_logger_name("My Scheduler")

    def init_extra_routes(self) -> None:
        """
        This function is empty defined in the BaseScheduler.
        Add any additional router you want to define here.
        """
        self.init_my_extra_personalized_routes()

    def init_my_extra_personalized_routes(self) -> None:
        my_personalized_router = APIRouter(prefix="/my-prefix", tags=["My Personalized tags"])

        my_personalized_router.add_api_route("/hello", self.hello_route_handler)

    def hello_route_handler(self):
        return {"message": "Hello World!"}