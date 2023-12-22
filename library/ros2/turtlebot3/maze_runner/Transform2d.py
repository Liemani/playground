import numpy

# from geometry_msgs.msg import Point
# from geometry_msgs.msg import Vector3
# from geometry_msgs import Pose
# from geometry_msgs import Quaternion
from Topology2d import Topology2d
from Point2d import Point2d

def translateInplace(point : Point2d, vector : Point2d) :
    point.x = point.x + vector.x
    point.y = point.y + vector.y

def rotateInplace(point : Point, radian : double) :
    sin = numpy.sin(radian)
    cos = numpy.cos(radian)

    x = cos * point.x - sin * point.y
    y = sin * point.x + cos * point.y

    point.x = x
    point.y = y

def topologyInGrandParentFrameInplace(topology : Topology2d, parentTopology : Topology2d) :
    positionInGrandParentFrameInplace(topology.point, parentTopology)
    topology.angle = topology.angle + parentTopology.angle

def positionInGrandParentFrameInplace(point Point2d, parentTopology : Topology2d) :
    rotateInplace(point, parentTopology.angle)
    translateInplace(point, parentTopology.point)
