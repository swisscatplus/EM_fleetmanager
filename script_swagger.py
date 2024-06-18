import hmac
import hashlib
import json
import requests

def generate_signature(path: str, body: bytes) -> str:
    message = path.encode("utf-8") + body
    secret_key = b"sonofedi"
    return hmac.new(secret_key, message, hashlib.sha256).hexdigest()

headers={}
body = {  
    "workflow_name": "Station-To-Station",
    "args": {"station_start": "ur5-sfc", "station_end": "ur5-omni"}
        }
path="/task/"
headers["Content-Type"] = "application/json"
body_bytes = json.dumps(body).encode("utf-8") if body else b''
headers["X-Signature"] = generate_signature(path, body_bytes)

response = requests.post(f"http://localhost:3000{path}", headers=headers, json=body)

print(response)