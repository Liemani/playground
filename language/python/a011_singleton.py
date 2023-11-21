class Singleton :
  instance = None
  def __new__(cls, *args, **kwargs) :
    if not isinstance(cls.instance, cls) :
      cls.instance = super().__new__(cls, *args, **kwargs)
    return cls.instance

class MyClass(Singleton) :
  pass
   
singleton1 = MyClass()
singleton1.value = 10
singleton2 = MyClass()
print(singleton2.value)
