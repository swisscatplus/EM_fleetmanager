"""
move_client.py  -  send commands to the robot through the REST API (demo_rest_api.py).

Plain Python, no ROS: run it anywhere that can reach the laptop (the VM, inside or outside a container).

    python3 move_client.py status
    python3 move_client.py go OmniFire                     # one move, waits until it is over
    python3 move_client.py loop "LC MS" OmniFire           # back and forth forever (Ctrl+C = stop robot)
    python3 move_client.py loop "LC MS" OmniFire --pause 10 --laps 20
    python3 move_client.py stop
    python3 move_client.py pose                            # current pose, to measure a station

    --url http://192.168.0.104:8001   (default http://localhost:8001)

Each move: POST /api/v1/moves, then GET /api/v1/moves/<id> every second until it is over
(no long HTTP connection that could time out).
"""

import argparse
import json
import sys
import time
import urllib.error
import urllib.request


def call(url, method="GET", body=None, timeout=10):
    """HTTP request -> (status code, JSON answer)"""
    data = None if body is None else json.dumps(body).encode("utf-8")
    req = urllib.request.Request(url, data=data, method=method, headers={"Content-Type": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as r:
            return r.status, json.loads(r.read() or b"{}")
    except urllib.error.HTTPError as e:            # 4xx / 5xx still carry a JSON answer
        return e.code, json.loads(e.read() or b"{}")


def go(api, station, start=None):
    """one move, printed while it runs. Returns True if the robot arrived."""
    body = {"station_end": station}
    if start:
        body["station_start"] = start
    code, ans = call(f"{api}/moves", "POST", body)
    if code != 202:
        print(f"  refused ({code}): {ans.get('message')}")
        return False
    for w in ans.get("warnings", []):
        print("  warning:", w)
    move_id = ans["id"]
    print(f"  move {move_id} -> {station} started")
    last = None
    while True:
        time.sleep(1.0)
        code, m = call(f"{api}/moves/{move_id}")
        if code != 200:
            print(f"  lost the move ({code}): {m}")
            return False
        line = f"  {m['status']}, attempt {m['attempts']}, {m['duration_s'] or 0:.0f} s"
        if line != last:
            print(line)
            last = line
        if m["status"] in ("succeeded", "failed"):
            print(f"  -> {m['message']}")
            return m["success"]


def main():
    ap = argparse.ArgumentParser(description="send commands to the robot (demo_rest_api.py)")
    ap.add_argument("command", choices=["status", "go", "loop", "stop", "pose", "stations"])
    ap.add_argument("stations", nargs="*", help="go: 1 station   loop: 2 or more stations")
    ap.add_argument("--url", default="http://localhost:8001")
    ap.add_argument("--pause", type=float, default=5.0, help="loop: seconds at each station")
    ap.add_argument("--laps", type=int, default=0, help="loop: number of laps, 0 = forever")
    ap.add_argument("--max-failures", type=int, default=2, help="loop: stop after this many failures in a row")
    a = ap.parse_args()
    api = a.url.rstrip("/") + "/api/v1"

    if a.command in ("status", "pose", "stations"):
        code, ans = call(f"{api}/{a.command}")
        print(json.dumps(ans, indent=2))
        return
    if a.command == "stop":
        print(call(f"{api}/stop", "POST", {})[1]["message"])
        return
    if a.command == "go":
        if len(a.stations) != 1:
            sys.exit("go needs ONE station, e.g.  go OmniFire")
        sys.exit(0 if go(api, a.stations[0]) else 1)

    # loop
    if len(a.stations) < 2:
        sys.exit('loop needs 2 stations or more, e.g.  loop "LC MS" OmniFire')
    ok = failed = in_a_row = 0
    t0 = time.monotonic()
    i = 0
    try:
        while not a.laps or i < a.laps * len(a.stations):
            goal = a.stations[i % len(a.stations)]
            print(f"=== trip {i + 1} -> {goal} ===")
            if go(api, goal):
                ok, in_a_row = ok + 1, 0
                time.sleep(a.pause)                      # the arm takes the plate
                i += 1
            else:
                failed, in_a_row = failed + 1, in_a_row + 1
                if in_a_row >= a.max_failures:
                    print("too many failures in a row: demo stopped. Check the robot, then run loop again.")
                    break
                print("trying the same station again in 5 s")
                time.sleep(5.0)
    except KeyboardInterrupt:
        print("\nCtrl+C:", call(f"{api}/stop", "POST", {})[1].get("message"))
    print(f"\n{ok} trips OK, {failed} failed, {(time.monotonic() - t0) / 60:.1f} min")


if __name__ == "__main__":
    main()