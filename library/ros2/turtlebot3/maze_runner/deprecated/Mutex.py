# 이거도 만들어야 한다
from enum import Enum

class Mutex(Enum) :
    ReadOnly = 1 << 0
    WriteOnly = 1 << 1
    ReadWrite = ReadOnly & WriteOnly

    def isReadable(self) :
        self
