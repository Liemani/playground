from tf2_msgs.msg import TFMessage
from rclpy.qos import QoSProfile

from SnapshotableValue import SnapshotableValue

class Transform :
    def __init__(self, rosNode) :
        self.rosNode = rosNode

        self.odometryInMapSnapshotableValue = SnapshotableValue()

        self.subscribe()

    def subscribe(self) :
        qosProfile = QoSProfile(depth=10)
        self.subscription = self.rosNode.create_subscription(
                TFMessage,
                "tf",
                self.receiveNotification,
                qosProfile)

    def receiveNotification(self, msg) :
        for transformStamped in msg.transforms :
            childFrameID = transformStamped.child_frame_id
            if childFrameID == "odom" :
                self.odometryInMapSnapshotableValue.buffer = transformStamped
            else :
                continue

    def setup(self) :
        self.odometryInMapSnapshotableValue.setup()

# read method
    def odometryInMap(self) :
        return self.odometryInMapSnapshotableValue.value

    def odometryInMapTranslation(self) :
        return self.odometryInMap().transform.translation

    def odometryInMapRotation(self) :
        return self.odometryInMap().transform.rotation

# calculated value
    def odometryInMapAngle(self) :
        rotation = self.odometryInMapRotation()
        z = rotation.z
        w = rotation.w
        return numpy.arctan2(2.0 * (w * z), w * w - z * z);

# debug method
    def debugDescribe(self) :
        print("transform.debugDescribe()")
        print("  odometryInMap")
        print("    translation : ", self.odometryInMapTranslation())
        print("    rotation : ", self.odometryInMapRotation())
