# resolve magic number with int enum class
# 0 : none
# 1 : read only
# 2 : write only
# 3 : readwrite
class MutexedValue :
    def __init__(self) :
        self.value = None
        self.isReading = False
        self.isWriting = False

    def isReadable(self) :
        return (self.mode & 1) != 0

    def isWritable(self) :
        return (self.mode & 2) != 0

    def setReadable(self) :
        self.mode = (self.mode | 1)

    def setWritable(self) :
        self.mode = (self.mode | 2)

    def setReadonly(self) :
        self.mode = 1

    def setWriteonly(self) :
        self.mode = 2

    def setReadWrite(self) :
        self.mode = 3

    def read(self) :
        self.isReading = True
        while self.isWriting :
            time.sleep(1 / 1000)

        value = self.value
        self.isReading = False

    def write(self) :
