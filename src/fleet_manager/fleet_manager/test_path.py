"""
test_path.py  -  check the planner WITHOUT ROS: print all trips + plot paths on the lab map.

Run (in the same folder as path.py):
    python3 test_path.py
Needs: pip install pyyaml matplotlib pillow

Change REPO below to where EM_fleetmanager is cloned on this computer.
Change the TESTS at the bottom to try other cases.
"""

import math
import os

import matplotlib.pyplot as plt
import yaml
from PIL import Image

from path_planner import Planner

# where EM_fleetmanager is cloned (Mac:   /Users/yasminebasti/Documents/SWISSCAT/EM_fleetmanager
#                                  VM:    /home/yasmine/SwissCat/EM_fleetmanager)
REPO = os.environ.get("EM_REPO", "/home/yasmine/Documents/SwissCAT/EM_fleetmanager")

# ---------------------------------------------------------------- printed summary of all station pairs
def print_summary(planner):
    print("stations used   :", ", ".join(planner.stations))
    print("stations skipped:", ", ".join(planner.skipped) or "-")
    print()
    for a in planner.stations:
        for b in planner.stations:
            if a == b:
                continue
            r = planner.plan(a, b)
            if "points" not in r:
                print(f"{a:>18} -> {b:<18} NO PATH   {'; '.join(r['warnings'])}")
                continue
            length = sum(math.dist(p, q) for p, q in zip(r["points"][:-1], r["points"][1:]))
            print(f"{a:>18} -> {b:<18} {r['direction']:<8} {length:5.2f} m  "
                  f"heading {'OK ' if r['ok'] else 'BAD'}  {'; '.join(r['warnings'])}")
    print()


# ---------------------------------------------------------------- plot one path on the lab map
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
    ax.arrow(sx, sy, 0.4 * math.cos(syaw), 0.4 * math.sin(syaw), width=0.06, color="blue")
    ax.annotate("START", (sx, sy), fontsize=9, color="blue", weight="bold", xytext=(6, 6), textcoords="offset points")

    if "points" not in result:
        ax.set_title(f"NO PATH to {goal}\n" + "; ".join(result["warnings"]), fontsize=9, color="red")
    else:
        pts = result["points"]
        xs, ys = [p[0] for p in pts], [p[1] for p in pts]
        colour = "red" if result["ok"] else "orange"

        # 5. path + points sent to the tracker
        ax.plot(xs, ys, "-", color=colour, lw=2.5, label="path sent to the tracker")
        ax.plot(xs, ys, ".", color="black", ms=4, label="points")

        # 6. small arrows = which way the robot FACES while driving (one every 0.7 m)
        backward = result["direction"] == "backward"
        travelled, next_arrow = 0.0, 0.3
        for (x1, y1), (x2, y2) in zip(pts[:-1], pts[1:]):
            travelled += math.dist((x1, y1), (x2, y2))
            if travelled >= next_arrow:
                ang = math.atan2(y2 - y1, x2 - x1) + (math.pi if backward else 0.0)
                ax.arrow(x1, y1, 0.15 * math.cos(ang), 0.15 * math.sin(ang), width=0.025, color=colour)
                next_arrow += 0.7

        # 7. A* route nodes (circled); the temporary robot node only exists for this request: skip it
        for n in result["route"]:
            if n not in planner.nodes:
                continue
            x, y = planner.nodes[n]
            ax.plot(x, y, "o", mfc="none", mec="purple", ms=10, mew=1.5)

        length = sum(math.dist(p, q) for p, q in zip(pts[:-1], pts[1:]))
        ax.set_title((title or f"-> {goal}") + f"\n{result['direction']}, {length:.2f} m, {len(pts)} points, "
                     f"arrival heading {'OK' if result['ok'] else 'WRONG'}"
                     + ("\n" + "; ".join(result["warnings"]) if result["warnings"] else ""),
                     fontsize=9, color="black" if result["ok"] else "darkorange")
        ax.legend(loc="lower left", fontsize=8)
        ax.set_xlim(min(xs + [sx]) - 1.0, max(xs + [sx]) + 1.0)
        ax.set_ylim(min(ys + [sy]) - 1.0, max(ys + [sy]) + 1.0)

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
    start, goal = "LC MS", "Chemspeed SwingSP"
    r = planner.plan(start, goal)
    plot_trajectory(planner, r, planner.stations[start], goal, REPO,
                    title=f"{start} -> {goal}", save_as="test_station_to_station.png")

    # robot anywhere -> station   (yaw: 0 = right, pi/2 = up, -pi/2 = down)
    robot = (0.3225, 5.6, -math.pi / 2)        # left road above LC MS, facing down (first robot test)
    goal = "LC MS"
    r = planner.plan_from_pose(*robot, goal)
    plot_trajectory(planner, r, robot, goal, REPO,
                    title=f"robot {robot[:2]} -> {goal}", save_as="test_robot_to_station.png")