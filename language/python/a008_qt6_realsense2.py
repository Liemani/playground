import sys
from enum import Enum
import cv2
import pyrealsense2 as rs
import numpy as np

from PySide6.QtCore import QTimer, Slot
from PySide6 import QtGui
from PySide6.QtWidgets import (
  QApplication,
  QGridLayout,
  QHBoxLayout,
  QLabel,
  QMainWindow,
  QVBoxLayout,
  QWidget,
)


class MainWindow(QMainWindow) :
  def setup(self) :
    self.setWindowTitle("Realsense example")

    self.constraint()

    self.setTimer()

    centralWidget = CentralWidget()
    centralWidget.setup()
    self.setCentralWidget(centralWidget)

  def constraint(self) :
    self.setFixedSize(Realsense.WIDTH * 1.5, Realsense.HEIGHT * 2)

  def setTimer(self) :
    self.timer = QTimer(self)
    self.timer.timeout.connect(self.update)

  def start(self) :
    self.update()
    self.timer.start()

  def show(self) :
    self.start()
    QMainWindow.show(self)

  @Slot()
  def update(self) :
    self.centralWidget().update()


class CentralWidget(QWidget) :
  def setup(self) :
    layout = QVBoxLayout()
    self.setLayout(layout)

    infraredCellLayout = QHBoxLayout()
    self.setupInfraredImageLayout(infraredCellLayout)
    layout.addLayout(infraredCellLayout)

    colorCellLayout = QHBoxLayout()
    self.setupColorImageLayout(colorCellLayout)
    layout.addLayout(colorCellLayout)

  def setupInfraredImageLayout(self, horizontalLayout) :
    self.infraredImageWidget = QLabel()
    self.infraredImageWidget.resize(Realsense.WIDTH, Realsense.HEIGHT)
    horizontalLayout.addWidget(self.infraredImageWidget)

    self.depthLabel = QLabel()
    horizontalLayout.addWidget(self.depthLabel)

  def setupColorImageLayout(self, horizontalLayout) :
    self.colorImageWidget = QLabel()
    self.colorImageWidget.resize(Realsense.WIDTH, Realsense.HEIGHT)
    horizontalLayout.addWidget(self.colorImageWidget)

    labelVerticalLayout = QVBoxLayout()
    self.colorRLabel = QLabel()
    self.colorGLabel = QLabel()
    self.colorBLabel = QLabel('a')
    labelVerticalLayout.addWidget(self.colorRLabel)
    labelVerticalLayout.addWidget(self.colorGLabel)
    labelVerticalLayout.addWidget(self.colorBLabel)
    horizontalLayout.addLayout(labelVerticalLayout)

  def update(self) :
    ( depthFrame, infraredFrame, colorFrame ) = realsense.getFrames()
    if not depthFrame or not infraredFrame or not colorFrame :
      return

    self.updateInfraredImage(infraredFrame)
    self.updateColorImage(colorFrame)
    self.updateDepthAverage(depthFrame)
    self.updateRGBAverage(colorFrame)

  def updateInfraredImage(self, infraredFrame) :
    infraredData = np.asanyarray(infraredFrame.get_data())
    infraredImage = cv2.applyColorMap(cv2.convertScaleAbs(infraredData, alpha=0.5), cv2.COLORMAP_BONE)
    infraredQImage = QtGui.QImage(infraredImage, Realsense.WIDTH, Realsense.HEIGHT, QtGui.QImage.Format_RGB888)
    infraredPixmap = QtGui.QPixmap.fromImage(infraredQImage)
    self.infraredImageWidget.setPixmap(infraredPixmap)

  def updateColorImage(self, colorFrame) :
    colorImage = np.asanyarray(colorFrame.get_data())
    colorQImage = QtGui.QImage(colorImage, Realsense.WIDTH, Realsense.HEIGHT, QtGui.QImage.Format_RGB888)
    colorPixmap = QtGui.QPixmap.fromImage(colorQImage)
    self.colorImageWidget.setPixmap(colorPixmap)

  def updateDepthAverage(self, depthFrame) :
    sum = 0
    for y in range(Realsense.HEIGHT):
      for x in range(Realsense.WIDTH):
        sum += depthFrame.get_distance(x, y)
    average = sum / Realsense.WIDTH / Realsense.HEIGHT
    self.depthLabel.setText(str(average))

  def updateRGBAverage(self, colorFrame) :
    colorImage = np.asanyarray(colorFrame.get_data())
    redSum = 0
    greenSum = 0
    blueSum = 0
    for y in range(Realsense.HEIGHT):
      for x in range(Realsense.WIDTH):
        redSum += colorImage[y][x][0]
        greenSum += colorImage[y][x][1]
        blueSum += colorImage[y][x][2]
    redAverage = redSum / Realsense.WIDTH / Realsense.HEIGHT
    greenAverage = greenSum / Realsense.WIDTH / Realsense.HEIGHT
    blueAverage = blueSum / Realsense.WIDTH / Realsense.HEIGHT
    self.colorRLabel.setText(str(redAverage))
    self.colorGLabel.setText(str(greenAverage))
    self.colorBLabel.setText(str(blueAverage))

class Realsense :
  WIDTH = 640
  HEIGHT = 480
  FPS = 15

  def __init__(self) :
    self.setupConfig()

  def setupConfig(self) :
    self.pipeline = rs.pipeline()

    config = rs.config()
    config.enable_stream(rs.stream.depth, self.WIDTH, self.HEIGHT, rs.format.z16, self.FPS)
    config.enable_stream(rs.stream.infrared, 1, self.WIDTH, self.HEIGHT, rs.format.y8, self.FPS)
    config.enable_stream(rs.stream.color, self.WIDTH, self.HEIGHT, rs.format.bgr8, self.FPS)

    self.pipeline.start(config)

  def getFrames(self) :
    frames = self.pipeline.wait_for_frames()
    depthFrame = frames.get_depth_frame()
    infraredFrame = frames.get_infrared_frame()
    colorFrame = frames.get_color_frame()

    return ( depthFrame, infraredFrame, colorFrame )


realsense = Realsense()

if __name__ == "__main__":
  application = QApplication(sys.argv)
  mainWindow = MainWindow()
  mainWindow.setup()
  mainWindow.show()
  sys.exit(application.exec())
