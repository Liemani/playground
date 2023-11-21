from model import Model

# from PySide6.QtGui import QImage
from pysidegraph import ImageView
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
    cameraWidget = CameraWidget()
    cameraWidget.setup()

    updateButton = QPushButton('Update')
    updateButton.clicked.connect(Model().cameraWidget.update)

    layout = QVBoxLayout()
    layout.addWidget(cameraWidget)
    layout.addWidget(updateButton)

    self.setLayout(layout)


class CameraWidget(ImageView) :
  def setup(self) :
    self.camera = Model().camera
    Model().cameraWidget = self

  def start(self) :
    self.camera.start()

  def update(self) :
    image = self.camera.getImage()
    print("image : ", image)

  def stop(self) :
    self.camera.stop()
