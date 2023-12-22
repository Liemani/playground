import numpy

import nav_msgs
from rclpy.qos import QoSProfile

from SnapshotableValue import SnapshotableValue

class BaseFootprintInOdometry :
    def __init__(self, rosNode) :
        self.rosNode = rosNode

        self.snapshotableValue = SnapshotableValue()

        self.subscribe()

    def subscribe(self) :
        self.qosProfile = QoSProfile(depth=10)
        self.subscription = self.rosNode.create_subscription(
                nav_msgs.msg.Odometry,
                "odom",
                self.snapshotableValue.receiveNotification,
                self.qosProfile)

    def setup(self) :
        self.snapshotableValue.setup()

    def snapshot(self) :
        self.snapshotableValue.snapshot()

# read method
    def value(self) :
        return self.snapshotableValue.value

    def position(self) :
        return self.value().pose.pose.position

    def orientation(self) :
        return self.value().pose.pose.orientation

    def linearVelocity(self) :
        return self.value().twist.twist.linear

    def angularVelocity(self) :
        return self.value().twist.twist.angular

# calculated value
    def angle(self) :
        orientation = self.orientation()
        z = orientation.z
        w = orientation.w
        return numpy.arctan2(2.0 * (w * z), w * w - z * z);

# debug method
    def debugDescribe(self) :
        print("odometry.debugDescribe()")
        print("  position : ", self.position())
        print("  orientation : ", self.orientation())
        print("  angle : ", self.angle())
        print("  velocity")
        print("    linear : ", self.linearVelocity())
        print("    angular : ", self.angularVelocity())
