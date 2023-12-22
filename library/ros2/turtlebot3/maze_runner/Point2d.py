class Point2d :
    def __init__(self, x=0.0 : double, y=0.0 : double) :
        self.x = x
        self.y = y

    def __invert__(self) :
        self.x = -self.x
        self.y = -self.y
