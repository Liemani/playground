from geometry_msgs.msg import Twist
from rclpy.qos import QoSProfile

from LiDAR import LiDAR
from BaseFootprintInOdometry import BaseFootprintInOdometry

from Topology2d import Topology2d

class Movement :
    def __init__(self, rosNode) :
        self.rosNode = rosNode
        self.createPublisher()

    def createPublisher(self) :
        qosProfile = QoSProfile(depth=10)
        self.publisher = self.rosNode.create_publisher(
            Twist,
            "cmd_vel",
            qosProfile)

    def move(self, linear=0.0, angular=0.0) :
        msg = Twist()

        msg.linear.x = linear;
        msg.angular.z = angular;

        self.publisher.publish(msg);

    def stop(self) :
        self.move(0.0, 0.0)

    def forward(self) :
        self.move(linear=0.1)

    def backward(self) :
        self.move(linear=-0.1)

    def turnLeft(self) :
        self.move(angular=-0.1)

    def turnRight(self) :
        self.move(angular=0.1)

class TurtleBot :
    radius = 0.1

    def __init__(self, rosNode) :
        self.lidar = LiDAR(rosNode)
        self.baseFootprintInOdometry = BaseFootprintInOdometry(rosNode)
        # 여기에 baseFootprintInOdometry 를 topology 로 바꿔야 한다
        # 변환 함수도 만들자
        self.topology = Topology2d()

        self.movement = Movement(rosNode)

    def setup(self) :
        self.lidar.setup()
        self.odometry.setup()

    def moveTo(self, point) :
        point.x
        point.y
