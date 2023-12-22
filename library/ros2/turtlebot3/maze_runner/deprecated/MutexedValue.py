# resolve magic number with int enum class
# 0 : none
# 1 : read only
# 2 : write only
# 3 : readwrite

from threading import Lock

class MutexedValue :
    def __init__(self) :
        self.mutex = Lock()

        self.buffer = None
        self.value = None

    def read(self) :
        with self.mutex :
            return self.buffer

    def write(self, value) :
        with self.mutex :
            self.buffer = value

    def snapshot(self) :
        self.value = self.buffer.read()
        return self if self.value is not None else None

    def setup(self) :
        while True :
            value = self.snapshot()
            if value is not None :
                break
            time.sleep(1 / 1000)
