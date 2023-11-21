class SingletonInstane:
  _instance = None

  @classmethod
  def __getInstance(cls):
    return cls.__instance

  @classmethod
  def instance(cls, *args, **kargs):
    cls._instance = cls(*args, **kargs)
    cls.instance = cls.__getInstance
    return cls.__instance

class MyClass(SingletonInstane):
  pass

c = MyClass.instance(a)
c.value = 10
d = MyClass.instance()
print(d.value)
