# reference https://realpython.com/python-multiple-constructors/

class Circle :
  def __init__(self, radius) :
    self.radius = radius

  def __repr__(self) :
    return f"{self.__class__.__name__}(radius={self.radius})"

  @classmethod
  def from_diameter(cls, diameter) :
    return cls(radius=diameter / 2)

  @classmethod
  def from_diameter2(self, diameter) :
    return self(radius=diameter / 2)

  def radius2(cls) :
    print(cls.radius)
