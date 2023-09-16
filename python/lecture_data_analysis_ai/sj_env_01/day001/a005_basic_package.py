# 패키지(폴더), 파일(라이브러리), 함수(모듈) 활용하기

# import math_class
# math = math_class.MathLib(10, 2)

from lib_util.math_util import MathLib

math = MathLib(10, 2)
print(math.getPlus())

math.setAB(100, 20)
print(math.getPlus())
