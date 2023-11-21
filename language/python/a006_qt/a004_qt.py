import sys
from PySide6.QtWidgets import (
  QApplication,
  QMainWindow,
  QPushButton,
  QVBoxLayout,
  QWidget
)


class Widget(QWidget) :
  def setup(self) :
    button1 = QPushButton('button1')
    button1.clicked.connect(self.button1Pressed)

    button2 = QPushButton('button2')
    button2.clicked.connect(self.button2Pressed)

    layout = QVBoxLayout()
    layout.addWidget(button1)
    layout.addWidget(button2)
    centralWidget.setLayout(layout)

  def button1Pressed(self) :
    print('Button1 Pressed')

  def button2Pressed(self) :
    print('Button2 Pressed')


if __name__ == '__main__' :
  application = QApplication(sys.argv)
  mainWindow = QMainWindow()

  centralWidget = Widget()
  centralWidget.setup()
  mainWindow.setCentralWidget(centralWidget)

  mainWindow.show()
  sys.exit(application.exec())
