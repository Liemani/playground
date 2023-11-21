import sys

from model import Model
from view import MainWindow

from PySide6.QtWidgets import (
  QApplication,
)


def main() :
  application = QApplication(sys.argv)

  model = Model()
  model.setup()

  mainWindow = MainWindow()
  mainWindow.setup()

  mainWindow.show()
  sys.exit(application.exec())


if __name__ == '__main__' :
  main()
