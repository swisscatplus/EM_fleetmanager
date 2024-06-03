from pydantic import BaseModel
from datetime import datetime


class DBNodePropertyModel(BaseModel):
    id: int
    node_id: int
    name: str
    value: str


class DBNodeModel(BaseModel):
    id: str
    name: str
    static: bool
    critical: bool
    source_node: str | None
    destination_node: str | None


class DBTaskModel(BaseModel):
    id: str
    workflow_id: int
    active_step: int | None
    task_state_id: int
    created_at: datetime
    updated_at: datetime


class DBWorkflowModel(BaseModel):
    id: int
    name: str
    source_node_id: str
    destination_node_id: str


class DBStepModel(BaseModel):
    id: int
    node_id: str
    worflow_id: int
    postion: int


class DBNodeCallRecordModel(BaseModel):
    id: int
    node_id: str
    endpoint: str | None
    message: str | None
    timestamp: datetime
    duration: float
    outcome: str


class DBWorkflowUsageRecordModel(BaseModel):
    id: int
    workflow_id: int
    timestamp: str


class TasksStatisticsEntry(BaseModel):
    uuid: str
    workflow: str
    state: str
    created_at: datetime
    execution_time_seconds: int
