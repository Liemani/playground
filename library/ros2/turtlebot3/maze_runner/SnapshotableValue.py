import time

class SnapshotableValue :
    def __init__(self) :
        self.buffer = None
        self.value = None

    def snapshot(self) :
        self.value = self.buffer

    def setup(self) :
        self.waitUntilSnapshotSuccess()

    def waitUntilSnapshotSuccess(self) :
        self.snapshot()
        while not self.isSnapshotSuccess() :
            time.sleep(1 / 1000)
            self.snapshot()

    def isSnapshotSuccess(self) :
        return self.value is not None

    def receiveNotification(self, msg) :
        self.buffer = msg
