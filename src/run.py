from dotenv import load_dotenv

from orchestrator.core import MyOrchestrator
from scheduler.core import MyScheduler
from task_scheduler.logger import LoggingManager
from task_scheduler.parser import parse_args


def main():
    args = parse_args()

    load_dotenv()

    LoggingManager(args.logs, args.debug)

    orchestrator = MyOrchestrator(
        args.path_to_nodes, args.path_to_workflows, args.verbose, args.emulate
    )
    app = MyScheduler(orchestrator, args.port)

    app.run()


if __name__ == "__main__":
    main()