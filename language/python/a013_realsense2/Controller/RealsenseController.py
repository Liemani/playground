import numpy as np
import cv2
from PySide6 import QtCore
from PySide6 import QtGui 
from Model.Camera import Realsense
import constant

class RealsenseController :
  class RealsenseThread(QtCore.QThread) :
    def __init__(self) :
      super().__init__()
      self.shouldRun = True

    def setup(self, depthImageWidget, colorImageWidget) :
      self.depthImageWidget = depthImageWidget
      self.colorImageWidget = colorImageWidget

      self.realsense = Realsense()
      self.realsense.setup()

    def run(self) :
      while self.shouldRun :
        self.update()

    def update(self) :
      depthFrame, colorFrame = self.realsense.getFrames()
      if not depthFrame or not colorFrame :
        return

      self.updateDepthImage(depthFrame)
      self.updateColorImage(colorFrame)

    def updateDepthImage(self, depthFrame) :
      image = np.asanyarray(depthFrame.get_data())
      image = cv2.applyColorMap(cv2.convertScaleAbs(image, alpha=0.5), cv2.COLORMAP_JET)
      qImage = QtGui.QImage(image, constant.INFRARED_WIDTH, constant.INFRARED_HEIGHT, QtGui.QImage.Format_RGB888)
      pixmap = QtGui.QPixmap.fromImage(qImage)
      pixmap = pixmap.scaled(constant.IMAGEWIDGET_WIDTH, constant.IMAGEWIDGET_HEIGHT, QtCore.Qt.KeepAspectRatio)
      self.depthImageWidget.setPixmap(pixmap)

    def updateColorImage(self, colorFrame) :
      image = np.asanyarray(colorFrame.get_data())
      qImage = QtGui.QImage(image, constant.COLOR_WIDTH, constant.COLOR_HEIGHT, QtGui.QImage.Format_RGB888)
      pixmap = QtGui.QPixmap.fromImage(qImage)
      pixmap = pixmap.scaled(constant.IMAGEWIDGET_WIDTH, constant.IMAGEWIDGET_HEIGHT, QtCore.Qt.KeepAspectRatio)
      self.colorImageWidget.setPixmap(pixmap)

    def stop(self) :
      self.shouldRun = False

  def __init__(self) :
    self.realsenseThread = None

  def setup(self, depthImageWidget, colorImageWidget, startButton, stopButton) :
    self.depthImageWidget = depthImageWidget
    self.colorImageWidget = colorImageWidget

    self.startButton = startButton
    self.stopButton = stopButton

  def start(self) :
    if not self.realsenseThread :
      self.startButton.setEnabled(False)
      self.stopButton.setEnabled(True)

      self.setupRealsenseThread()
      self.realsenseThread.start()

  def setupRealsenseThread(self) :
    self.realsenseThread = self.RealsenseThread()
    self.realsenseThread.setup(self.depthImageWidget, self.colorImageWidget)

  def stop(self) :
    self.startButton.setEnabled(True)
    self.stopButton.setEnabled(False)

    self.realsenseThread.stop()
    self.realsenseThread.wait()
    self.realsenseThread = None
