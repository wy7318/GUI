import serial
import time
import binascii
import struct
from PyQt5.QtWidgets import QFileDialog
import sys
import serial.tools.list_ports
from PyQt5.QtWidgets import QApplication, QDialog, QMessageBox, QCompleter
import SerialGUI2
import datetime
from CommandThread import CommandCRLF, CommandCR, CommandLF, CommandNONE
from PyQt5.QtPrintSupport import QPrinter
from PyQt5.Qt import QFileInfo

class MainClass(QDialog,SerialGUI2.Ui_Dialog):

    def __init__(self):
        super().__init__()
        self.setupUi(self)

        commands = ["READ", "SETCH", "SETC", "SETP", "SET"]
        completer = QCompleter(commands)

        #Add available ports
        self.lists = self.Comport()
        for self.com in self.lists:
            self.comboBox_port.addItem(self.com)
        self.pushButton_refresh.clicked.connect(self.refresh)       #Refresh ports list
        self.pushButton_clear.clicked.connect(self.Clear)           #Clear RichTextbox
        self.pushButton_set.clicked.connect(self.connection)        #Connection check
        self.pushButton_send.clicked.connect(self.SendCom)          #Sending commands
        self.pushButton_close.clicked.connect(self.Close)
        self.lineEdit_command.returnPressed.connect(self.SendCom)
        self.lineEdit_command.setCompleter(completer)
        self.pushButton_export.clicked.connect(self.printPDF)





    def Comport(self):
        ports = serial.tools.list_ports.comports()
        available_ports = []

        for p in ports:
            available_ports.append(p.device)
        return available_ports

    def refresh(self):
        self.comboBox_port.clear()
        for comList in self.Comport():
            self.comboBox_port.addItem(comList)

    def Clear(self):
        self.plainTextEdit.clear()

    def Close(self):
        current_time = datetime.datetime.now()
        self.plainTextEdit.appendPlainText(str(current_time.year) + "-"
                                           + str(current_time.month) + "-"
                                           + str(current_time.day) + " "
                                           + str(current_time.hour) + ":"
                                           + str(current_time.minute) + ":"
                                           + str(current_time.second))
        self.comboBox_port.setEnabled(True)
        self.pushButton_refresh.setEnabled(True)
        self.comboBox_parity.setEnabled(True)
        self.comboBox_baudRate.setEnabled(True)
        self.comboBox_byteSize.setEnabled(True)
        self.comboBox_stopBits.setEnabled(True)
        self.lineEdit_timeout.setEnabled(True)
        self.pushButton_set.setEnabled(True)
        self.plainTextEdit.appendPlainText("Port closed successfully")

    #Selection for parity
    def ParitySel(self, parity):
        switcher = {
            "None" : serial.PARITY_NONE,
            "Even" : serial.PARITY_EVEN,
            "Odd" : serial.PARITY_ODD,
            "Mark" : serial.PARITY_MARK,
            "Space" : serial.PARITY_SPACE,
        }
        return switcher.get(parity, 0)

    #Selection for Stopbits
    def StopbitsSel(self, stop):
        switcher = {
            1 : serial.STOPBITS_ONE,
            2 : serial.STOPBITS_TWO,
        }
        return switcher.get(stop, 0)

    #Selection for byte size
    def ByteSel(self, byte):
        switcher = {
            5 : serial.FIVEBITS,
            6 : serial.SIXBITS,
            7 : serial.SEVENBITS,
            8 : serial.EIGHTBITS
        }
        return switcher.get(byte, 0)

    #Connec button
    def connection(self):
        current_time = datetime.datetime.now()
        self.con = serial.Serial(port=self.comboBox_port.currentText(),
                                 baudrate=int(self.comboBox_baudRate.currentText()),
                                 parity=self.ParitySel(self.comboBox_parity.currentText()),
                                 stopbits=self.StopbitsSel(int(self.comboBox_stopBits.currentText())),
                                 bytesize=self.ByteSel(int(self.comboBox_byteSize.currentText())),
                                 timeout=float(self.lineEdit_timeout.text())
                                 )
        if self.con.is_open == True:
            self.plainTextEdit.appendPlainText(str(current_time.year) + "-"
                                               + str(current_time.month) + "-"
                                               + str(current_time.day) + " "
                                               + str(current_time.hour) + ":"
                                               + str(current_time.minute) + ":"
                                               + str(current_time.second))
            self.plainTextEdit.appendPlainText("Successfully Connected to: " + self.con.portstr + "\n")
            self.comboBox_port.setEnabled(False)
            self.pushButton_refresh.setEnabled(False)
            self.comboBox_parity.setEnabled(False)
            self.comboBox_baudRate.setEnabled(False)
            self.comboBox_byteSize.setEnabled(False)
            self.comboBox_stopBits.setEnabled(False)
            self.lineEdit_timeout.setEnabled(False)
            self.pushButton_set.setEnabled(False)
            self.con.close()
        else:
            self.plainTextEdit.appendPlainText("Connection Failed. Please check your COM port and try again.")

    def SendCom(self):
        current_time = datetime.datetime.now()
        self.plainTextEdit.appendPlainText(str(current_time.year) + "-"
                                           + str(current_time.month) + "-"
                                           + str(current_time.day) + " "
                                           + str(current_time.hour) + ":"
                                           + str(current_time.minute) + ":"
                                           + str(current_time.second))
        self.plainTextEdit.appendPlainText(self.lineEdit_command.text())

        if self.comboBox_TT.currentText() == "N/A":
            self.SCn = CommandNONE(self.comboBox_port.currentText(), self.comboBox_baudRate.currentText(),
                                  self.ParitySel(self.comboBox_parity.currentText()), self.StopbitsSel(int(self.comboBox_stopBits.currentText())),
                                  self.ByteSel(int(self.comboBox_byteSize.currentText())), self.lineEdit_timeout.text(), self.lineEdit_command.text())
            self.SCn.start()
            self.SCn.response.connect(self.plainTextEdit.appendPlainText)
            self.lineEdit_command.clear()
        elif self.comboBox_TT.currentText() == "CR":
            self.SCc = CommandCR(self.comboBox_port.currentText(), self.comboBox_baudRate.currentText(),
                                  self.ParitySel(self.comboBox_parity.currentText()), self.StopbitsSel(int(self.comboBox_stopBits.currentText())),
                                  self.ByteSel(int(self.comboBox_byteSize.currentText())), self.lineEdit_timeout.text(), self.lineEdit_command.text())
            self.SCc.start()
            self.SCc.response.connect(self.plainTextEdit.appendPlainText)
            self.lineEdit_command.clear()
        elif self.comboBox_TT.currentText() == "LF":
            self.SCl = CommandLF(self.comboBox_port.currentText(), self.comboBox_baudRate.currentText(),
                                  self.ParitySel(self.comboBox_parity.currentText()), self.StopbitsSel(int(self.comboBox_stopBits.currentText())),
                                  self.ByteSel(int(self.comboBox_byteSize.currentText())), self.lineEdit_timeout.text(), self.lineEdit_command.text())
            self.SCl.start()
            self.SCl.response.connect(self.plainTextEdit.appendPlainText)
            self.lineEdit_command.clear()

        elif self.comboBox_TT.currentText() == "CR/LF":
            self.SC = CommandCRLF(self.comboBox_port.currentText(), self.comboBox_baudRate.currentText(),
                                  self.ParitySel(self.comboBox_parity.currentText()), self.StopbitsSel(int(self.comboBox_stopBits.currentText())),
                                  self.ByteSel(int(self.comboBox_byteSize.currentText())), self.lineEdit_timeout.text(), self.lineEdit_command.text())
            self.SC.start()
            self.SC.response.connect(self.plainTextEdit.appendPlainText)
            self.lineEdit_command.clear()

        else:
            QMessageBox.about(self, "Warning", "Something is wrong with program. Please select your tranmitted text option again")
            self.lineEdit_command.clear()

    # def keyPressEvent(self, event):
    #     if event.key() == QtCore.Qt.Key_Return:
    #         self.SendCom()
    #     else:
    #         super().keyPressEvent(event)


    def printPDF(self):
        fn, _ = QFileDialog.getSaveFileName(self, 'Export PDF', None, 'PDF files (.pdf);;All Files()')
        if fn != '':
            if QFileInfo(fn).suffix() == "" : fn += '.pdf'
            printer = QPrinter(QPrinter.HighResolution)
            printer.setOutputFormat(QPrinter.PdfFormat)
            printer.setOutputFileName(fn)
            self.plainTextEdit.document().print_(printer)


if __name__=='__main__':
    ll=QApplication(sys.argv)
    pen=MainClass()
    pen.show()
    ll.exec_()