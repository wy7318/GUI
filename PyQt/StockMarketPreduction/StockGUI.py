# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\Bruce Ko\Desktop\Minsub Lee\Development\Git\Sups Stock\StockGUI.ui'
#
# Created by: PyQt5 UI code generator 5.15.0
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(1250, 802)
        self.gridLayout_4 = QtWidgets.QGridLayout(Dialog)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.verticalLayout_9 = QtWidgets.QVBoxLayout()
        self.verticalLayout_9.setObjectName("verticalLayout_9")
        self.groupBox_6 = QtWidgets.QGroupBox(Dialog)
        self.groupBox_6.setStyleSheet("QGroupBox {\n"
"background-color: white;\n"
"border: 2px solid gray;\n"
" border-radius: 5px;\n"
"\n"
" }\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
" color: black;\n"
"}")
        self.groupBox_6.setTitle("")
        self.groupBox_6.setObjectName("groupBox_6")
        self.gridLayout = QtWidgets.QGridLayout(self.groupBox_6)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout_8 = QtWidgets.QVBoxLayout()
        self.verticalLayout_8.setObjectName("verticalLayout_8")
        self.label_33 = QtWidgets.QLabel(self.groupBox_6)
        font = QtGui.QFont()
        font.setFamily("MS Sans Serif")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label_33.setFont(font)
        self.label_33.setObjectName("label_33")
        self.verticalLayout_8.addWidget(self.label_33)
        self.verticalLayout_7 = QtWidgets.QVBoxLayout()
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.comboBox = QtWidgets.QComboBox(self.groupBox_6)
        self.comboBox.setObjectName("comboBox")
        self.verticalLayout_7.addWidget(self.comboBox)
        self.label_35 = QtWidgets.QLabel(self.groupBox_6)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        font.setBold(False)
        font.setWeight(50)
        self.label_35.setFont(font)
        self.label_35.setObjectName("label_35")
        self.verticalLayout_7.addWidget(self.label_35)
        self.lineEdit_sn_3 = QtWidgets.QLineEdit(self.groupBox_6)
        self.lineEdit_sn_3.setText("")
        self.lineEdit_sn_3.setObjectName("lineEdit_sn_3")
        self.verticalLayout_7.addWidget(self.lineEdit_sn_3)
        self.verticalLayout_8.addLayout(self.verticalLayout_7)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_37 = QtWidgets.QLabel(self.groupBox_6)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        font.setBold(False)
        font.setWeight(50)
        self.label_37.setFont(font)
        self.label_37.setObjectName("label_37")
        self.verticalLayout_2.addWidget(self.label_37)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.lineEdit_sn_4 = QtWidgets.QLineEdit(self.groupBox_6)
        self.lineEdit_sn_4.setText("")
        self.lineEdit_sn_4.setObjectName("lineEdit_sn_4")
        self.horizontalLayout_4.addWidget(self.lineEdit_sn_4)
        self.pushButton_disconnect_3 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_disconnect_3.setObjectName("pushButton_disconnect_3")
        self.horizontalLayout_4.addWidget(self.pushButton_disconnect_3)
        self.verticalLayout_2.addLayout(self.horizontalLayout_4)
        self.verticalLayout_8.addLayout(self.verticalLayout_2)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label_40 = QtWidgets.QLabel(self.groupBox_6)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        font.setBold(False)
        font.setWeight(50)
        self.label_40.setFont(font)
        self.label_40.setObjectName("label_40")
        self.verticalLayout_3.addWidget(self.label_40)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.lineEdit_sn_5 = QtWidgets.QLineEdit(self.groupBox_6)
        self.lineEdit_sn_5.setText("")
        self.lineEdit_sn_5.setObjectName("lineEdit_sn_5")
        self.horizontalLayout_5.addWidget(self.lineEdit_sn_5)
        self.pushButton_disconnect_4 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_disconnect_4.setObjectName("pushButton_disconnect_4")
        self.horizontalLayout_5.addWidget(self.pushButton_disconnect_4)
        self.verticalLayout_3.addLayout(self.horizontalLayout_5)
        self.verticalLayout_8.addLayout(self.verticalLayout_3)
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.pushButton_connect_4 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_connect_4.setObjectName("pushButton_connect_4")
        self.horizontalLayout_7.addWidget(self.pushButton_connect_4)
        self.pushButton_connect_3 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_connect_3.setObjectName("pushButton_connect_3")
        self.horizontalLayout_7.addWidget(self.pushButton_connect_3)
        self.verticalLayout_8.addLayout(self.horizontalLayout_7)
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.pushButton_connect_5 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_connect_5.setObjectName("pushButton_connect_5")
        self.horizontalLayout_6.addWidget(self.pushButton_connect_5)
        self.pushButton_connect_6 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_connect_6.setObjectName("pushButton_connect_6")
        self.horizontalLayout_6.addWidget(self.pushButton_connect_6)
        self.verticalLayout_8.addLayout(self.horizontalLayout_6)
        self.pushButton_connect_7 = QtWidgets.QPushButton(self.groupBox_6)
        self.pushButton_connect_7.setObjectName("pushButton_connect_7")
        self.verticalLayout_8.addWidget(self.pushButton_connect_7)
        self.gridLayout.addLayout(self.verticalLayout_8, 0, 0, 1, 1)
        self.verticalLayout_9.addWidget(self.groupBox_6)
        self.groupBox_4 = QtWidgets.QGroupBox(Dialog)
        self.groupBox_4.setStyleSheet("QGroupBox {\n"
"background-color: white;\n"
"border: 2px solid gray;\n"
" border-radius: 5px;\n"
"\n"
" }\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
" color: black;\n"
"}")
        self.groupBox_4.setTitle("")
        self.groupBox_4.setObjectName("groupBox_4")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.groupBox_4)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.verticalLayout_6 = QtWidgets.QVBoxLayout()
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.label_31 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Sans Serif")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label_31.setFont(font)
        self.label_31.setObjectName("label_31")
        self.verticalLayout_6.addWidget(self.label_31)
        self.horizontalLayout_12 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.label_30 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_30.setFont(font)
        self.label_30.setObjectName("label_30")
        self.horizontalLayout_12.addWidget(self.label_30)
        self.comboBox_2 = QtWidgets.QComboBox(self.groupBox_4)
        self.comboBox_2.setObjectName("comboBox_2")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.horizontalLayout_12.addWidget(self.comboBox_2)
        self.verticalLayout_6.addLayout(self.horizontalLayout_12)
        self.label_21 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_21.setFont(font)
        self.label_21.setObjectName("label_21")
        self.verticalLayout_6.addWidget(self.label_21)
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.lineEdit_sn_6 = QtWidgets.QLineEdit(self.groupBox_4)
        self.lineEdit_sn_6.setText("")
        self.lineEdit_sn_6.setObjectName("lineEdit_sn_6")
        self.horizontalLayout_9.addWidget(self.lineEdit_sn_6)
        self.pushButton_disconnect_5 = QtWidgets.QPushButton(self.groupBox_4)
        self.pushButton_disconnect_5.setObjectName("pushButton_disconnect_5")
        self.horizontalLayout_9.addWidget(self.pushButton_disconnect_5)
        self.verticalLayout_6.addLayout(self.horizontalLayout_9)
        self.label_23 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_23.setFont(font)
        self.label_23.setObjectName("label_23")
        self.verticalLayout_6.addWidget(self.label_23)
        self.horizontalLayout_10 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_10.setObjectName("horizontalLayout_10")
        self.lineEdit_sn_7 = QtWidgets.QLineEdit(self.groupBox_4)
        self.lineEdit_sn_7.setText("")
        self.lineEdit_sn_7.setObjectName("lineEdit_sn_7")
        self.horizontalLayout_10.addWidget(self.lineEdit_sn_7)
        self.pushButton_disconnect_6 = QtWidgets.QPushButton(self.groupBox_4)
        self.pushButton_disconnect_6.setObjectName("pushButton_disconnect_6")
        self.horizontalLayout_10.addWidget(self.pushButton_disconnect_6)
        self.verticalLayout_6.addLayout(self.horizontalLayout_10)
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.label_28 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_28.setFont(font)
        self.label_28.setObjectName("label_28")
        self.horizontalLayout_11.addWidget(self.label_28)
        self.lineEdit_freqS_sg_1 = QtWidgets.QLineEdit(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.lineEdit_freqS_sg_1.setFont(font)
        self.lineEdit_freqS_sg_1.setStyleSheet("QLineEdit{ background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit:focus { background-color:rgb(255, 255, 255);}")
        self.lineEdit_freqS_sg_1.setObjectName("lineEdit_freqS_sg_1")
        self.horizontalLayout_11.addWidget(self.lineEdit_freqS_sg_1)
        self.label_freqS_sg_1 = QtWidgets.QLabel(self.groupBox_4)
        self.label_freqS_sg_1.setObjectName("label_freqS_sg_1")
        self.horizontalLayout_11.addWidget(self.label_freqS_sg_1)
        self.verticalLayout_6.addLayout(self.horizontalLayout_11)
        self.verticalLayout_5 = QtWidgets.QVBoxLayout()
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.label_22 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_22.setFont(font)
        self.label_22.setObjectName("label_22")
        self.verticalLayout_5.addWidget(self.label_22)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.lineEdit_amp_sg_3 = QtWidgets.QLineEdit(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.lineEdit_amp_sg_3.setFont(font)
        self.lineEdit_amp_sg_3.setStyleSheet("QLineEdit{ background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit:focus { background-color:rgb(255, 255, 255);}")
        self.lineEdit_amp_sg_3.setObjectName("lineEdit_amp_sg_3")
        self.horizontalLayout_3.addWidget(self.lineEdit_amp_sg_3)
        self.label_span_3 = QtWidgets.QLabel(self.groupBox_4)
        self.label_span_3.setObjectName("label_span_3")
        self.horizontalLayout_3.addWidget(self.label_span_3)
        self.verticalLayout_5.addLayout(self.horizontalLayout_3)
        self.verticalLayout_6.addLayout(self.verticalLayout_5)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_29 = QtWidgets.QLabel(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_29.setFont(font)
        self.label_29.setObjectName("label_29")
        self.horizontalLayout_2.addWidget(self.label_29)
        self.lineEdit_amp_sg_1 = QtWidgets.QLineEdit(self.groupBox_4)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.lineEdit_amp_sg_1.setFont(font)
        self.lineEdit_amp_sg_1.setStyleSheet("QLineEdit{ background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit:focus { background-color:rgb(255, 255, 255);}")
        self.lineEdit_amp_sg_1.setObjectName("lineEdit_amp_sg_1")
        self.horizontalLayout_2.addWidget(self.lineEdit_amp_sg_1)
        self.verticalLayout_6.addLayout(self.horizontalLayout_2)
        self.pushButton_set_sg_1 = QtWidgets.QPushButton(self.groupBox_4)
        self.pushButton_set_sg_1.setMinimumSize(QtCore.QSize(0, 27))
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.pushButton_set_sg_1.setFont(font)
        self.pushButton_set_sg_1.setStyleSheet("QPushButton{     background:rgb(230, 230, 230);\n"
"\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-color: rgb(43, 43, 43);\n"
"\n"
"\n"
"}\n"
"QPushButton:disabled{background-color :rgb(206, 207, 216);}\n"
"\n"
"QPushButton:focus:pressed{ background-color: black; }\n"
"\n"
"QPushButton:hover{    background:rgb(221, 237, 255);\n"
"color : black; }\n"
"")
        self.pushButton_set_sg_1.setObjectName("pushButton_set_sg_1")
        self.verticalLayout_6.addWidget(self.pushButton_set_sg_1)
        self.groupBox_5 = QtWidgets.QGroupBox(self.groupBox_4)
        self.groupBox_5.setStyleSheet("QGroupBox {\n"
"background-color: white;\n"
"border: 2px solid gray;\n"
" border-radius: 5px;\n"
"\n"
" }\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
" color: black;\n"
"}")
        self.groupBox_5.setTitle("")
        self.groupBox_5.setObjectName("groupBox_5")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.groupBox_5)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label_32 = QtWidgets.QLabel(self.groupBox_5)
        font = QtGui.QFont()
        font.setFamily("MS Sans Serif")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label_32.setFont(font)
        self.label_32.setObjectName("label_32")
        self.gridLayout_2.addWidget(self.label_32, 0, 0, 1, 1)
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_34 = QtWidgets.QLabel(self.groupBox_5)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_34.setFont(font)
        self.label_34.setObjectName("label_34")
        self.verticalLayout.addWidget(self.label_34)
        self.label_36 = QtWidgets.QLabel(self.groupBox_5)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.label_36.setFont(font)
        self.label_36.setObjectName("label_36")
        self.verticalLayout.addWidget(self.label_36)
        self.verticalLayout_4.addLayout(self.verticalLayout)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_span_4 = QtWidgets.QLabel(self.groupBox_5)
        self.label_span_4.setObjectName("label_span_4")
        self.horizontalLayout.addWidget(self.label_span_4)
        self.lineEdit_amp_sg_4 = QtWidgets.QLineEdit(self.groupBox_5)
        font = QtGui.QFont()
        font.setFamily("MS Reference Sans Serif")
        font.setPointSize(10)
        self.lineEdit_amp_sg_4.setFont(font)
        self.lineEdit_amp_sg_4.setStyleSheet("QLineEdit{ background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit:focus { background-color:rgb(255, 255, 255);}")
        self.lineEdit_amp_sg_4.setObjectName("lineEdit_amp_sg_4")
        self.horizontalLayout.addWidget(self.lineEdit_amp_sg_4)
        self.verticalLayout_4.addLayout(self.horizontalLayout)
        self.gridLayout_2.addLayout(self.verticalLayout_4, 1, 0, 1, 1)
        self.verticalLayout_6.addWidget(self.groupBox_5)
        self.gridLayout_3.addLayout(self.verticalLayout_6, 0, 0, 1, 1)
        self.verticalLayout_9.addWidget(self.groupBox_4)
        self.horizontalLayout_8.addLayout(self.verticalLayout_9)
        self.groupBox_7 = QtWidgets.QGroupBox(Dialog)
        self.groupBox_7.setStyleSheet("QGroupBox {\n"
"background-color: white;\n"
"border: 2px solid gray;\n"
" border-radius: 5px;\n"
"\n"
" }\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
" color: black;\n"
"}")
        self.groupBox_7.setTitle("")
        self.groupBox_7.setObjectName("groupBox_7")
        self.gridLayout_13 = QtWidgets.QGridLayout(self.groupBox_7)
        self.gridLayout_13.setObjectName("gridLayout_13")
        self.gridLayout_graph = QtWidgets.QGridLayout()
        self.gridLayout_graph.setObjectName("gridLayout_graph")
        self.gridLayout_13.addLayout(self.gridLayout_graph, 0, 0, 1, 1)
        self.horizontalLayout_8.addWidget(self.groupBox_7)
        self.horizontalLayout_8.setStretch(0, 1)
        self.horizontalLayout_8.setStretch(1, 3)
        self.gridLayout_4.addLayout(self.horizontalLayout_8, 0, 0, 1, 1)

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.label_33.setText(_translate("Dialog", "Search Stock"))
        self.label_35.setText(_translate("Dialog", "Or"))
        self.label_37.setText(_translate("Dialog", "From (YYYY-MM-DD)"))
        self.pushButton_disconnect_3.setText(_translate("Dialog", "Calendar"))
        self.label_40.setText(_translate("Dialog", "To  (YYYY-MM-DD)"))
        self.pushButton_disconnect_4.setText(_translate("Dialog", "Calendar"))
        self.pushButton_connect_4.setText(_translate("Dialog", "10 Years"))
        self.pushButton_connect_3.setText(_translate("Dialog", "5 Years"))
        self.pushButton_connect_5.setText(_translate("Dialog", "3 Years"))
        self.pushButton_connect_6.setText(_translate("Dialog", "1 Years"))
        self.pushButton_connect_7.setText(_translate("Dialog", "Search"))
        self.label_31.setText(_translate("Dialog", "Training Configuration"))
        self.label_30.setText(_translate("Dialog", "Training Type"))
        self.comboBox_2.setItemText(0, _translate("Dialog", "Open"))
        self.comboBox_2.setItemText(1, _translate("Dialog", "Close"))
        self.label_21.setText(_translate("Dialog", "Training From (YYYY-MM-DD)"))
        self.pushButton_disconnect_5.setText(_translate("Dialog", "Calendar"))
        self.label_23.setText(_translate("Dialog", "Training To (YYYY-MM-DD)"))
        self.pushButton_disconnect_6.setText(_translate("Dialog", "Calendar"))
        self.label_28.setText(_translate("Dialog", "Training Percentage"))
        self.lineEdit_freqS_sg_1.setText(_translate("Dialog", "80"))
        self.label_freqS_sg_1.setText(_translate("Dialog", "%"))
        self.label_22.setText(_translate("Dialog", "Training Period (Last XX days)"))
        self.lineEdit_amp_sg_3.setText(_translate("Dialog", "60"))
        self.label_span_3.setText(_translate("Dialog", "Days"))
        self.label_29.setText(_translate("Dialog", "Epochs"))
        self.lineEdit_amp_sg_1.setText(_translate("Dialog", "5"))
        self.pushButton_set_sg_1.setText(_translate("Dialog", "Train"))
        self.label_32.setText(_translate("Dialog", "Prediction"))
        self.label_34.setText(_translate("Dialog", "Predicted Price for "))
        self.label_36.setText(_translate("Dialog", "XXXX-XX-XX"))
        self.label_span_4.setText(_translate("Dialog", "$"))
        self.lineEdit_amp_sg_4.setText(_translate("Dialog", "5"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())
