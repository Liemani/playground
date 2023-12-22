# movement.max min
# 기술 부채 목록 :
# 나중에 lidar와 wheel을 module의 자식으로 하고 turtleBot은 모듈배열을 갖는다
# 지금은 LiDAR가 반드시 있을 것이라고 가정하고 작성하지만, 나중에는 LiDAR 센서가 존재하는지 판단하는 로직이 필요하다
# subscribe에 Mutex class 정의해서 사용하기

from threading import Thread
import time

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from Map import Map
from TurtleBot import TurtleBot
from Transform import Transform

class MazeRunner(Node) :
    def __init__(self) :
        super().__init__("mazerunner")
        self.shouldRun = False

        self.map = Map(self)
        self.turtleBot = TurtleBot(self)
        self.transform = Transform(self)

    def run(self) :
        self.setup()

        while self.shouldRun :
            self.loop4()
            time.sleep(1)

        self.turtleBot.movement.stop()

    def setup(self) :
        self.map.setup()
        self.turtleBot.setup()
        self.transform.setup()

        self.map.setOdometryInMapSnapshotableValue(self.transform.odometryInMapSnapshotableValue)
        self.map.setAngle(self.turtleBot.odometry.angle())

    def loop1(self) :
        self.turtleBot.movement.forward()
        time.sleep(1)
        self.turtleBot.movement.stop()
        time.sleep(1)
        self.turtleBot.movement.backward()
        time.sleep(1)
        self.turtleBot.movement.stop()

    def loop2(self) :
        self.turtleBot.movement.turnLeft()
        time.sleep(1)
        self.turtleBot.movement.stop()
        #print(self.transform.getOdomToBaseFootprint())
        #print(self.transform.getMapToOdom())
        print()
        time.sleep(1)
        self.turtleBot.movement.turnRight()
        time.sleep(1)
        self.turtleBot.movement.stop()
        #print(self.transform.getOdomToBaseFootprint())
        #print(self.transform.getMapToOdom())
        print()

    def loop3(self) :
        map = self.map.snapshot()
        if map != None :
            print(map.origin())

        odomToBaseFootprint = self.transform.getOdomToBaseFootprint()
        if odomToBaseFootprint != None :
            print(odomToBaseFootprint.transform.translation)

        print()

    def loop4(self) :
        map = self.map
        odometry = self.turtleBot.odometry
        transform = self.transform

        # snapshot
        odometry.snapshot()
        map.snapshot()

        # update
        map.updateCharacterPosition(odometry.position())

        # draw
        map.debugDraw()
        map.debugDescribe()
        odometry.debugDescribe()
        transform.debugDescribe()

    def runThread(self) :
        self.shouldRun = True
        self.thread = Thread(target=self.run)
        self.thread.start()

    def terminateThread(self) :
        self.shouldRun = False
        self.thread.join()

def main(args=None):
    rclpy.init(args=args)
    node = MazeRunner()
    try:
        node.runThread()
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard Interrupt!!")
    finally:
        node.terminateThread()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__" :
    main()
