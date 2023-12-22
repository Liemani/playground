from sensor_msgs.msg import LaserScan
from rclpy.qos import qos_profile_sensor_data

from SnapshotableValue import SnapshotableValue

class LiDAR :
    def __init__(self, rosNode) :
        self.rosNode = rosNode

        self.snapshotableValue = SnapshotableValue()

        self.subscribe()

    def subscribe(self) :
        self.subscription = self.rosNode.create_subscription(
                LaserScan,
                "scan",
                self.snapshotableValue.receiveNotification,
                qos_profile_sensor_data)

    def setup(self) :
        self.snapshotableValue.setup()

    def snapshot(self) :
        self.snapshotableValue.snapshot()

# read method
    def value(self) :
        return self.snapshotableValue.value
