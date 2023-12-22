import numpy

from geometry_msgs.msg import Point
from geometry_msgs.msg import Vector3
from geometry_msgs import Pose
from geometry_msgs import Quaternion

def translateInplace(point : Point, vector : Vector3) :
    point.x = point.x + vector.x
    point.y = point.y + vector.y
    point.z = point.z + vector.z

def rotateInplace(point : Point, radian) :
    sin = numpy.sin(radian)
    cos = numpy.cos(radian)

    x = cos * point.x - sin * point.y
    y = sin * point.x + cos * point.y

    point.x = x
    point.y = y
