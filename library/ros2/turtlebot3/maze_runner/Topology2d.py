from Point2d import Point2d

class Topology2d :
    def __init__(self, x=0.0 : double, y=0.0 : double, orientation=0.0 : double) :
        self.position = Point2d(x, y)
        self.orientation = orientation

    def x(self) -> double :
        return self.position.x

    def y(self) -> double :
        return self.position.y
