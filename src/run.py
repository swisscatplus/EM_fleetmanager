from dotenv import load_dotenv

from orchestrator.core import EMOrchestrator
from scheduler.core import EMScheduler
from glas.logger import LoggingManager
from glas.parser import parse_args

def main():
    args = parse_args()

    load_dotenv()

    LoggingManager(args.logs, args.verbose, args.debug)

    orchestrator = EMOrchestrator(args.path_to_nodes, args.path_to_workflows, args.emulate)
    app = EMScheduler(orchestrator, args.port)

    app.run()


if __name__ == "__main__":
    main()