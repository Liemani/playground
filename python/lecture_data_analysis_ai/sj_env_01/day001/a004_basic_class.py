class Math:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def getPlus(self):
        return self.a + self.b

    def setAB(self, a, b):
        self.a = a
        self.b = b

math = Math(10, 2)
print(math.getPlus())

math.setAB(100, 20)
print(math.getPlus())
