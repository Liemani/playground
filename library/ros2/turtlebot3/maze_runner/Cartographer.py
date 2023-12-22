from nav_msgs.msg import OccupancyGrid

class Cartographer :
    def __init__(self, characterRadius) :
        self.map = OccupancyGrid()
        self.map.info.resolution = characterRadius * 2.0

    def apply(self, laserScan) :
