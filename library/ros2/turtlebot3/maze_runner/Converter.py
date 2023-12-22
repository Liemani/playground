import numpy

from geometry_msgs.msg import Quaternion

# suppose : x == 0, y == 0
def quaternionToOrientation2d(quaternion : Quaternion) -> double :
    z = quaternion.z
    w = quaternion.w
    return numpy.arctan2(2.0 * (w * z), w * w - z * z)
