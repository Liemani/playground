from realsense import Realsense

class Singleton :
  instance = None
  def __new__(cls, *args, **kwargs) :
    if not isinstance(cls.instance, cls) :
      cls.instance = super().__new__(cls, *args, **kwargs)
    return cls.instance


class Model(Singleton) :
  def setup(self) :
    self.setupCamera()

  def setupCamera(self) :
    camera = Realsense()
    camera.setup()
    self.camera = camera
