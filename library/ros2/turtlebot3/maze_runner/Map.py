from nav_msgs.msg import OccupancyGrid
from rclpy.qos import QoSProfile

from SnapshotableValue import SnapshotableValue

class Map :
    def __init__(self, rosNode) :
        self.rosNode = rosNode

        self.snapshotableValue = SnapshotableValue()
        self.odometryInMapSnapshotableValue = None

        self.angle = None
        self.characterPosition = None

        self.subscribe()

    def subscribe(self) :
        self.qosProfile = QoSProfile(depth=10)
        self.subscription = self.rosNode.create_subscription(
                OccupancyGrid,
                "map",
                self.snapshotableValue.receiveNotification,
                self.qosProfile)

    def setup(self) :
        self.snapshotableValue.setup()

    def setOdometryInMapSnapshotableValue(self, odometryInMapSnapshotableValue) :
        self.odometryInMapSnapshotableValue = odometryInMapSnapshotableValue

    def setAngle(self, angle) :
        self.angle = angle

    def snapshot(self) :
        self.snapshotableValue.snapshot()
        self.odometryInMapSnapshotableValue.snapshot()

# read method
    def value(self) :
        return self.snapshotableValue.value

    def odometryInMap(self) :
        return self.odometryInMapSnapshotableValue.value

    def resolution(self) :
        return self.value().info.resolution

    def width(self) :
        return self.value().info.width

    def height(self) :
        return self.value().info.height

    def position(self) :
        return self.value().info.origin.position

    def orientation(self) :
        return self.value().info.origin.orientation

    def data(self) :
        return self.value().data

    def dataAt(self, row, column) :
        return self.data()[self.width() * row + column]

# write method
    def updateCharacterPosition(self, characterPosition) :
        self.characterPosition = characterPosition

    def setDataAt(self, value, row, column) :
        self.data()[self.width() * row + column] = value

# debug method
    def debugDescribe(self) :
        print("map.debugDescribe()")
        print("  origin")
        print("    position : ", self.position())
        print("    orientation : ", self.orientation())
        print("  odometryInMap")
        print("    translation : ", self.odometryInMap().transform.translation)
        print("    rotation : ", self.odometryInMap().transform.rotation)

    def debugDraw(self) :
        self.debugDraw_drawCharacter()

        print("- Map --------------------------")
        data = self.data()
        for row in range(self.height()) :
            for column in range(self.width()) :
                dataAt = data[self.width() * (self.height() - row - 1) + column]
                character = "$" if dataAt == -2 else "." if dataAt == -1 else "#" if dataAt > 50 else " "
                print(character, end='')
            print()

    def debugDraw_drawCharacter(self) :
        if self.characterPosition is None :
            return

        data = self.data()
        position = self.position()

        dx = self.characterPosition.x - position.x
        dy = self.characterPosition.y - position.y

        sin = numpy.sin(-self.angle)
        cos = numpy.cos(-self.angle)

        x = cos * dx - sin * dy
        y = sin * dx + cos * dy

        gridX = int(x / self.resolution())
        gridY = int(y / self.resolution())

        self.setDataAt(-2, (self.height() - gridY - 1), gridX)
