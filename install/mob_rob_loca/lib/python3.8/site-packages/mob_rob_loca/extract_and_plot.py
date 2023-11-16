import rclpy
from rclpy.qos import QoSProfile
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import Odometry
import csv
import matplotlib.pyplot as plt

def extract_data(bag_path, topic_name):
    x_values = []
    y_values = []

    rclpy.init()

    node = rclpy.create_node('bag_reader')
    qos_profile = QoSProfile(depth=10)

    def callback(msg):
        nonlocal x_values, y_values
        x_values.append(msg.pose.pose.position.x)
        y_values.append(msg.pose.pose.position.y)

    subscription = node.create_subscription(
        PoseWithCovarianceStamped,
        topic_name,
        callback,
        qos_profile
    )

    try:
        rclpy.spin(node)
    finally:
        # Cleanup after subscription is done
        node.destroy_node()
        rclpy.shutdown()

    return x_values, y_values

def plot_data(x_values, y_values, label):
    plt.plot(x_values, y_values, label=label)

def save_csv(x_values, y_values, filename):
    with open(filename, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['X', 'Y'])
        writer.writerows(zip(x_values, y_values))

if __name__ == "__main__":
    bag_path = 'ekf_data_0.db3'

    # Extract data for each topic
    x_marv, y_marv = extract_data(bag_path, '/marv/pos')
    x_wheel, y_wheel = extract_data(bag_path, '/wheel/odom')
    x_odometry, y_odometry = extract_data(bag_path, '/odometry/global')

    # Plotting
    plot_data(x_marv, y_marv, label='/marv/pos')
    plot_data(x_wheel, y_wheel, label='/wheel/odom')
    plot_data(x_odometry, y_odometry, label='/odometry/global')

    plt.title('Position Data')
    plt.xlabel('X Position')
    plt.ylabel('Y Position')
    plt.legend()

    plt.show()

    # Save data to CSV files
    save_csv(x_marv, y_marv, 'marv_pos_data.csv')
    save_csv(x_wheel, y_wheel, 'wheel_odom_data.csv')
    save_csv(x_odometry, y_odometry, 'odometry_global_data.csv')

