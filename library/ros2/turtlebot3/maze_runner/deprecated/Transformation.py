import numpy

from geometry_msgs.msg import Point
from geometry_msgs.msg import Vector3
from geometry_msgs import Pose
from geometry_msgs import Quaternion

def translate2Inplace(point : Point, vector : Vector3) :
    point.x = point.x + vector.x
    point.y = point.y + vector.y
    point.z = point.z + vector.z

def rotateRollInplace(pose : Pose, radian) :
    point = pose.position

    sin = numpy.sin(radian)
    cos = numpy.cos(radian)

    x = cos * point.x - sin * point.y
    y = sin * point.x + cos * point.y

    point.x = x
    point.y = y

def rotateRollPointInplace(point : Point, radian) :
    

def combineRollQuaternionInplace(lhs : Quaternion, rhs : Quaternion) :
    z = lhs.w * rhs.z + lhs.z * rhs.w
    w = lhs.w * rhs.w - lhs.z * rhs.z
}

def applyPoseRoll2Inplace(pose : Pose, framePose : Pose) :
    rotateRollInplace(pose.
