import sys
from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton

class MyWidget(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        vbox = QVBoxLayout()
        hbox = QHBoxLayout()

        label1 = QLabel("레이아웃 1")
        hbox.addWidget(label1)

        button1 = QPushButton("버튼 1")
        hbox.addWidget(button1)

        vbox.addLayout(hbox)

        label2 = QLabel("레이아웃 2")
        vbox.addWidget(label2)

        self.setLayout(vbox)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('중첩된 레이아웃 예제')
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    widget = MyWidget()
    widget.show()
    sys.exit(app.exec())
