from model import Model
import numpy as np

from PySide6 import QtCore
from PySide6 import QtGui 
# from pysidegraph import ImageView
from PySide6.QtWidgets import (
  QLabel,
  QMainWindow,
  QPushButton,
  QWidget,
  QVBoxLayout,
)


class MainWindow(QMainWindow) :
  def setup(self) :
    self.setupCentralWidget()

  def setupCentralWidget(self) :
    centralWidget = CentralWidget()
    centralWidget.setup()
    self.setCentralWidget(centralWidget)

class CentralWidget(QWidget) :
  def setup(self) :
    cameraLabel = CameraLabel()
    cameraLabel.setup()
    Model().cameraLabel = cameraLabel

    startButton = QPushButton('Start')
    startButton.clicked.connect(Model().cameraLabel.start)
    Model().startButton = startButton

    stopButton = QPushButton('Stop')
    stopButton.setEnabled(False)
    stopButton.clicked.connect(Model().cameraLabel.stop)
    Model().stopButton = stopButton

    layout = QVBoxLayout()
    layout.addWidget(cameraLabel)
    layout.addWidget(startButton)
    layout.addWidget(stopButton)

    self.setLayout(layout)

class CameraLabel(QLabel, QtCore.QThread) :
  class CameraThread(QtCore.QThread) :
    def setup(self, camera, label) :
      self.camera = camera
      self.label = label

    def run(self) :
      while True :
        image = self.camera.getImage()
        qImage = QtGui.QImage(image, 3, 3, QtGui.QImage.Format_RGB888)
        pixmap = QtGui.QPixmap.fromImage(qImage)
        pixmap = pixmap.scaled(200, 200, QtCore.Qt.KeepAspectRatio)
        self.label.setPixmap(pixmap)

  def setup(self) :
    self.cameraThread = None
    self.camera = Model().camera
    self.resize(200, 200)

  def start(self) :
    if not self.cameraThread :
      Model().startButton.setEnabled(False)
      Model().stopButton.setEnabled(True)
      self.cameraThread = self.CameraThread()
      self.cameraThread.setup(Model().camera, self)
      self.cameraThread.start()

  def stop(self) :
    Model().startButton.setEnabled(True)
    Model().stopButton.setEnabled(False)
    self.cameraThread.terminate()
    self.cameraThread = None
