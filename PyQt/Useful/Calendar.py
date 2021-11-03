from PyQt5.QtWidgets import QApplication, QDialog, \
    QVBoxLayout, QCalendarWidget, QLabel, QPushButton
import sys
from PyQt5.QtGui import QIcon, QFont

class WindowCalendar(QDialog):
    def __init__(self, date):
        self.date = date
        super().__init__()


        #window requrements like geometry,icon and title
        self.setGeometry(200,200,400,200)
        self.setWindowTitle("Calendar")
        # self.setWindowIcon(QIcon("python.png"))

        vbox = QVBoxLayout()
        self.calendar = QCalendarWidget()
        self.calendar.setGridVisible(True)
        self.calendar.selectionChanged.connect(self.calendar_date)

        self.label =QPushButton("Confirm")
        self.label.setFont(QFont("Sanserif", 12))
        # self.label.setStyleSheet('color:red')

        vbox.addWidget(self.calendar)
        vbox.addWidget(self.label)

        self.setLayout(vbox)

        self.label.clicked.connect(self.hide)

    def calendar_date(self):
        dateselected = self.calendar.selectedDate()
        date_in_string = str(dateselected.toPyDate())

        self.date.setText(date_in_string)
