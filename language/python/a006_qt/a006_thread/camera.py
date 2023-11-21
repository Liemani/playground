import time
import numpy as np

# import pyrealsense2 as rs

import constant


class Camera :
  timeinterval = 1 / constant.fps

  def setup(self) :
    pass

  def getImage(self) :
    pass

class VirtualCamera(Camera) :
  WIDTH = 3
  HEIGHT = 3

  blackImage = [
    [ [0, 0, 0], [0, 0, 0], ],
    [ [0, 0, 0], [0, 0, 0], ],
  ]

  startImage = [
    [ [127, 0, 0], [0, 127, 0], [0, 0, 127], ],
    [ [0, 127, 0], [0, 0, 127], [127, 0, 0], ],
    [ [0, 0, 127], [127, 0, 0], [0, 127, 0], ],
  ]

  greyImage = [
    [ [127, 127, 127, 127], [127, 127, 127, 127], ],
    [ [127, 127, 127, 127], [127, 127, 127, 127], ],
  ]

  def __init__(self) :
    super().__init__()

    self.image = None

  def setup(self) :
    self.image = np.array(VirtualCamera.startImage, dtype=np.uint8)
    print(type(self.image), len(self.image))
    print(type(self.image[0]), len(self.image[0]))
    print(type(self.image[0][0]), len(self.image[0][0]))
    print(type(self.image[0][0][0]), self.image[1][0][1])

  def update(self) :
    time.sleep(self.timeinterval)
#     for x in range(VirtualCamera.WIDTH) :
#       for y in range(VirtualCamera.HEIGHT) :
#         for rgb in range(3) :
#           value = self.image[y][x][rgb]
#           self.image[y][x][rgb] = (value + 10) % 256

  def getImage(self) :
    self.update()
    return self.image
