# import pyrealsense2 as rs


class Realsense :
  WIDTH = 2
  HEGITH = 2

  def setup(self) :
    self.image = [
      [
        [255, 0, 0],
        [0, 255, 0],
      ],
      [
        [0, 0, 255],
        [127, 127, 127],
      ],
    ]

  def getImage(self) :
    self.update()
    return self.image

  def update(self) :
    for x in range(self.WIDTH) :
      for y in range(self.HEGITH) :
        for rgb in range(3) :
          value = self.image[y][x][rgb]
          self.image[y][x][rgb] = (value + 10) % 256
