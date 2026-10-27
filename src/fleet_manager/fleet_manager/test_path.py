"""
test_path.py  -  check the planner WITHOUT ROS: print all trips + plot paths on the lab map.

Run (in the same folder as path_planner.py):
    python3 test_path.py
Needs: pyyaml matplotlib pillow

Change REPO below to where EM_fleetmanager is cloned on this computer.
Change the TESTS at the bottom to try other cases.

On the plots:
    red line   = drive FORWARD     blue line = drive BACKWARD
    small arrows on the line = which way the robot's FRONT points
    orange circle = turn in place (with the target angle)
"""

import math
import os

import matplotlib.pyplot as plt
import yaml
from PIL import Image

from path_planner import Planner, describe

# where EM_fleetmanager is cloned
REPO = os.environ.get("EM_REPO", "/home/yasmine/Documents/SwissCAT/EM_fleetmanager")

COLOURS = {"forward": "red", "backward": "blue"}


# ---------------------------------------------------------------- printed summary of all station pairs
def print_summary(planner):
    print("stations used   :", ", ".join(planner.stations))
    print("stations skipped:", ", ".join(planner.skipped) or "-")
    print("turns allowed at:", ", ".join(sorted(planner.junctions)))
    print()
    for a in planner.stations:
        for b in planner.stations:
            if a == b:
                continue
            r = planner.plan(a, b)
            length = sum(math.dist(p, q) for p, q in zip(r["points"][:-1], r["points"][1:]))
            print(f"{a:>18} -> {b:<18} {'OK ' if r['ok'] else 'BAD'} {length:5.2f} m   {r['direction']}")
            for line in describe(r):
                print(f"{'':>24}{line}")
            for w in r["warnings"]:
                print(f"{'':>24}! {w}")
    print()


# ---------------------------------------------------------------- plot one plan on the lab map
def plot_trajectory(planner, result, start_pose, goal, repo, title=None, save_as=None):
    """
    planner    : the Planner object
    result     : what planner.plan(...) or planner.plan_from_pose(...) returned
    start_pose : (x, y, yaw) of the start (robot or station)
    goal       : name of the goal station
    repo       : EM_fleetmanager folder (to find the map image)
    """
    # 1. map image, placed in metres with circuit.yaml (resolution + origin)
    map_info = yaml.safe_load(open(repo + "/src/fleet_manager/maps/circuit.yaml"))
    img = Image.open(repo + "/src/fleet_manager/maps/" + map_info["image"])
    res = map_info["resolution"]
    ox, oy = map_info["origin"][0], map_info["origin"][1]
    w, h = img.size
    extent = [ox, ox + w * res, oy, oy + h * res]

    fig, ax = plt.subplots(figsize=(8, 11))
    ax.imshow(img, extent=extent, cmap="gray")

    # 2. road graph (blue dashed) + node names
    for a, b in planner.edges:
        (x1, y1), (x2, y2) = planner.nodes[a], planner.nodes[b]
        ax.plot([x1, x2], [y1, y2], "--", color="steelblue", lw=1, alpha=0.6)
    for name, (x, y) in planner.nodes.items():
        ax.plot(x, y, "o", color="steelblue", ms=4)
        ax.annotate(name, (x, y), fontsize=6, color="steelblue", xytext=(3, 3), textcoords="offset points")

    # 3. stations (green arrow = docking position + yaw)
    for name, (x, y, yaw) in planner.stations.items():
        ax.arrow(x, y, 0.3 * math.cos(yaw), 0.3 * math.sin(yaw), width=0.04, color="green")
        ax.annotate(name, (x, y), fontsize=8, color="darkgreen", xytext=(6, -12), textcoords="offset points")

    # 4. start (blue arrow = position + heading)
    sx, sy, syaw = start_pose
    ax.arrow(sx, sy, 0.4 * math.cos(syaw), 0.4 * math.sin(syaw), width=0.06, color="black")
    ax.annotate("START", (sx, sy), fontsize=9, color="black", weight="bold", xytext=(6, 6), textcoords="offset points")

    xs_all, ys_all = [sx], [sy]
    if not result["steps"]:
        ax.set_title(f"-> {goal}: nothing to drive\n" + "; ".join(result["warnings"]), fontsize=9, color="red")
    else:
        n_turn = 0
        for st in result["steps"]:
            if st["type"] == "turn":
                # 5a. turn in place: orange circle + target angle
                n_turn += 1
                tx, ty = planner.nodes[st["at"]] if st["at"] in planner.nodes else (sx, sy)
                ax.plot(tx, ty, "o", mfc="none", mec="orange", ms=22, mew=3)
                ax.annotate(f"turn {n_turn}: to {math.degrees(st['yaw']):.0f} deg", (tx, ty), fontsize=8,
                            color="darkorange", weight="bold", xytext=(14, -4), textcoords="offset points")
                continue
            # 5b. drive leg: line + points + arrows showing where the FRONT points
            pts = st["points"]
            xs, ys = [p[0] for p in pts], [p[1] for p in pts]
            xs_all += xs
            ys_all += ys
            colour = COLOURS[st["direction"]]
            ax.plot(xs, ys, "-", color=colour, lw=2.5, label=f"drive {st['direction']}")
            ax.plot(xs, ys, ".", color="black", ms=4)
            backward = st["direction"] == "backward"
            travelled, next_arrow = 0.0, 0.3
            for (x1, y1), (x2, y2) in zip(pts[:-1], pts[1:]):
                travelled += math.dist((x1, y1), (x2, y2))
                if travelled >= next_arrow:
                    ang = math.atan2(y2 - y1, x2 - x1) + (math.pi if backward else 0.0)
                    ax.arrow(x1, y1, 0.15 * math.cos(ang), 0.15 * math.sin(ang), width=0.025, color=colour)
                    next_arrow += 0.7

        length = sum(math.dist(p, q) for p, q in zip(result["points"][:-1], result["points"][1:]))
        ax.set_title((title or f"-> {goal}") + f"\n{result['direction']}  ({length:.2f} m)"
                     + ("\n" + "; ".join(result["warnings"]) if result["warnings"] else ""),
                     fontsize=9)
        handles, labels = ax.get_legend_handles_labels()
        unique = dict(zip(labels, handles))                     # one legend entry per direction
        ax.legend(unique.values(), unique.keys(), loc="lower left", fontsize=8)
    ax.set_xlim(min(xs_all) - 1.0, max(xs_all) + 1.0)
    ax.set_ylim(min(ys_all) - 1.0, max(ys_all) + 1.0)

    ax.set_aspect("equal")
    ax.set_xlabel("x [m]")
    ax.set_ylabel("y [m]")
    ax.grid(alpha=0.3)
    plt.tight_layout()
    if save_as:
        plt.savefig(save_as, dpi=120)
        print("saved", save_as)
    plt.show()


# ---------------------------------------------------------------- TESTS (change these)
if __name__ == "__main__":
    planner = Planner(REPO + "/src/tracker/config/map_pois.yaml",
                      REPO + "/src/fleet_manager/config/stations.yaml")

    print_summary(planner)

    # station -> station
    start, goal = "Chemspeed SwingSP", "Battery"
    r = planner.plan(start, goal)
    plot_trajectory(planner, r, planner.stations[start], goal, REPO,
                    title=f"{start} -> {goal}", save_as="test_station_to_station.png")

    # robot anywhere -> station   (yaw: 0 = right, pi/2 = up, -pi/2 = down)
    pi = math.pi
    tests = [
        ("A centre, facing up",        (4.3525, 3.0,   pi / 2),  "Battery"),
        ("B centre, facing down",      (4.3525, 3.0,  -pi / 2),  "Battery"),
        ("C centre, crooked 45 deg",   (4.3525, 3.0,   pi / 4),  "Battery"),
        ("D docked at Chemspeed",      (4.18,   0.885, pi / 2),  "Battery"),
        ("E middle road",              (2.3375, 3.0,   pi / 2),  "Battery"),
        ("F at Battery, wrong way",    (4.52,   7.201, pi / 2),  "LC MS"),
    ]
    for name, robot, goal in tests:
        r = planner.plan_from_pose(*robot, goal)
        print(f"{name} -> {goal}: {r['direction']}")
        for line in describe(r):
            print("    " + line)
        for w in r["warnings"]:
            print("    ! " + w)
        plot_trajectory(planner, r, robot, goal, REPO, title=f"{name} -> {goal}")