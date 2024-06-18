from glas.task.core import Task
from glas.database import DatabaseConnector, DBTask

class TaskNoPause(Task):
    def _run(self, step_id: int = 0) -> int:
        """
        expliquer ici pourquoi tu override
        """
        if (exit_code := self._recursion_exit(step_id)) is not None:
            return exit_code

        # fetch the step nodes (source, current, destination)
        self._current_step = step_id
        cur_node = self._workflow.steps[step_id]
        src_node = self._workflow.steps[step_id - 1] if step_id > 0 else None
        dst_node = self._workflow.steps[step_id + 1] if step_id < len(self._workflow.steps) - 1 else None

        db = DatabaseConnector()

        self._pre_step_execution(cur_node, src_node, dst_node)
        DBTask.update_active_step(db, str(self._uuid), cur_node.id)
        status, msg = cur_node.execute(db, str(self._uuid), self._workflow.name, src_node, dst_node, self._args)
        self._post_step_execution(status, msg, cur_node, src_node, dst_node)

        if status != 0:
            self.set_error()
            self.logger.error(f"Node execution error [{cur_node.name}]: {status}: {msg}")
            self._current_step = len(self._workflow.steps)

            # At this point the current node is in error state because the ROS2 task has failed. 
            # But the ROS2 server is normally still completely fine.
            # The restart is just in order to reset the node state to allow new task to be run.
            cur_node.restart()

        return self._run(self._current_step + 1)