from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
import scipy.special as sc
from scipy import optimize
import csv, math
import pyqtgraph as pg
from pyqtgraph import DateAxisItem
import StockGUI
import sys
import math
import pandas_datareader as web
from yahoo_fin import stock_info as si
import numpy as np
import pandas as pd
from CAL import WindowCalendar
# from sklearn.preprocessing import MinMaxScaler
# from keras.models import Sequential
# from keras.layers import Dense, LSTM
import matplotlib.pyplot as plt
import datetime
from TrainingThread import TrainingConfig, TrainingConfig_Period
from dateutil.relativedelta import relativedelta            #TimeDelta function




class MainClass(QDialog,StockGUI.Ui_Dialog):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.listStock_ss()        #Load tickers to combobox
        self.listStock_tc()        #Load tickers to combobox


        #Pushbutton Implementation
        self.pushButton_fromCal_ss.clicked.connect(self.fromSearchStock)
        self.pushButton_toCal_ss.clicked.connect(self.toSearchStock)
        self.pushButton_fromCal_tc.clicked.connect(self.fromTrainingConfig)
        self.pushButton_toCal_tc.clicked.connect(self.toTrainingConfig)
        self.pushButton_search_ss.clicked.connect(self.showStock)
        self.pushButton_10y.clicked.connect(self.tenY)
        self.pushButton_5y.clicked.connect(self.fiveY)
        self.pushButton_3y.clicked.connect(self.threeY)
        self.pushButton_1y.clicked.connect(self.oneY)
        self.pushButton_10y_2.clicked.connect(self.tenY_tc)
        self.pushButton_5y_2.clicked.connect(self.fiveY_tc)
        self.pushButton_3y_2.clicked.connect(self.threeY_tc)
        self.pushButton_1y_2.clicked.connect(self.oneY_tc)

        self.pushButton_train.clicked.connect(self.train)

        ###################Stryling Graph###########################
        label_style = {'color': '#EEE', 'font-size': '10pt'}
        self.graph = pg.PlotWidget(title="Stock Market")
        self.graph.showGrid(x = True, y = True, alpha = 0.3)
        self.graph.setLabel('left', "USD ($)")
        self.graph.getAxis('left').setLabel(**label_style)
        self.graph.getAxis('bottom').setLabel(**label_style)
        self.graph.setLabel('bottom', "Period (Year)")
        self.graph.addLegend()      # Need this to show label of lines

        font=QtGui.QFont()
        font.setPixelSize(15)
        self.graph.getAxis("bottom").tickFont = font
        # self.graph.getAxis("bottom").setStyle(tickTextOffset=20)
        self.graph.getAxis("left").tickFont = font
        # self.graph.getAxis("left").setStyle(tickTextOffset=20)
        # self.graph.setYRange(-120,10)


        self.gridLayout_graph.addWidget(self.graph, 0, 0)
        self.plot1 = self.graph.plot(pen='r', name ='Close')
        self.plot2 = self.graph.plot(pen='b', name ='Open')
        self.plot3 = self.graph.plot(pen='y', name ='Prediction')
        self.plot4 = self.graph.plot(pen='w', name ='Actual Data')
        self.plot5 = self.graph.plot(pen='g', name ='Trained Data')
        # self.plot1.show()

        # Connect mouse cursor return function
        self.plot1.scene().sigMouseMoved.connect(self.onMouseMoved)

    # Mouse Cursor Coordinate return
    def onMouseMoved(self, point):
        p = self.graph.plotItem.vb.mapSceneToView(point)
        self.lineEdit_price.setText("{:.2f}".format(p.y()))
        self.lineEdit_date.setText("{:.0f}".format(p.x()))

    def plotClosePredict(self, train, close, predict):
        self.plot4.setData(close)
        self.plot4.show()
        self.plot3.setData(predict)
        print(predict)
        self.plot3.show()
        # self.plot5.setData(train)
        # self.plot5.show()
        self.plot1.clear()
        self.plot2.clear()


    def train(self):
        if self.checkBox_next.isChecked():      # Next Day Prediction is selected
            print("next")
            self.trainingThread = TrainingConfig(self.comboBox_ticker_2.currentText(), self.comboBox_trainingType.currentText(), self.lineEdit_from_tc.text(), self.lineEdit_toCal_tc.text(),
                                                 self.lineEdit_trainingPercentage.text(), self.lineEdit_trainingPeriod.text(), self.lineEdit_epochs.text())
            self.trainingThread.trainValidClosePredictSig.connect(self.plotClosePredict)
            self.trainingThread.countChanged.connect(self.onCountChanged_percent)
            self.trainingThread.statusChanged.connect(self.onCountChanged_message)
            self.trainingThread.PredictionSig.connect(self.predictionDisplay)
            self.trainingThread.start()
        elif self.checkBox_period.isChecked():  # Period Prediction is selected
            print("period")
        else:                                   # None Selected
            QMessageBox.about(self, "Warning", "Please select your prediction type!")



    # ProgressBar Update
    def onCountChanged_percent(self, percent):
        self.progressBar_train.setValue(percent)
    # Progress Status Wording Update
    def onCountChanged_message(self, value):
        self.label_sm.setText(value)
    # Prediction Value Display
    def predictionDisplay(self, date, value):
        self.label_prediction.setText(date)
        self.lineEdit_prediction.setText(value)

    # Display Stock Chart
    def showStock(self):
        ticker = self.comboBox_ticker.currentText()
        startD = self.lineEdit_from_ss.text()
        endD = self.lineEdit_to_ss.text()

        df = web.DataReader(ticker, data_source='yahoo', start = startD, end=endD)

        self.plot1.setData(df['Close'])
        self.plot2.setData(df['Open'])
        self.plot1.show()
        self.plot2.show()
        self.plot3.clear()
        self.plot4.clear()
        self.plot5.clear()
        self.graph.autoRange()

    # Collecting all current list of tickers from yahoo financial
    def listStock_gen(self, combobox):
        # gather stock symbols from major US exchanges
        df1 = pd.DataFrame( si.tickers_sp500() )
        df2 = pd.DataFrame( si.tickers_nasdaq() )
        df3 = pd.DataFrame( si.tickers_dow() )
        df4 = pd.DataFrame( si.tickers_other() )

        # convert DataFrame to list, then to sets
        sym1 = set( symbol for symbol in df1[0].values.tolist() )
        sym2 = set( symbol for symbol in df2[0].values.tolist() )
        sym3 = set( symbol for symbol in df3[0].values.tolist() )
        sym4 = set( symbol for symbol in df4[0].values.tolist() )

        # join the 4 sets into one. Because it's a set, there will be no duplicate symbols
        symbols = set.union( sym1, sym2, sym3, sym4 )

        # Some stocks are 5 characters. Those stocks with the suffixes listed below are not of interest.
        my_list = ['W', 'R', 'P', 'Q']
        del_set = set()
        sav_set = set()

        for symbol in symbols:
            if len( symbol ) > 4 and symbol[-1] in my_list:
                del_set.add( symbol )
            else:
                sav_set.add( symbol )
        for ticker in sav_set:
            combobox.addItem(str(ticker))
    #Listing Stocks on "Search Stock"
    def listStock_ss(self):
        self.listStock_gen(self.comboBox_ticker)

    #Listing Stocks on "Training Configuration"
    def listStock_tc(self):
        self.listStock_gen(self.comboBox_ticker_2)


    #From date setting for 'Search Stock'
    def fromSearchStock(self):
        self.calendar = WindowCalendar(self.lineEdit_from_ss)
        self.calendar.show()
    #To date setting for 'Search Stock'
    def toSearchStock(self):
        self.calendar = WindowCalendar(self.lineEdit_to_ss)
        self.calendar.show()
    #From date setting for 'Training Configuration'
    def fromTrainingConfig(self):
        self.calendar = WindowCalendar(self.lineEdit_from_tc)
        self.calendar.show()
    #To date setting for 'Training Configuration'
    def toTrainingConfig(self):
        self.calendar = WindowCalendar(self.lineEdit_toCal_tc)
        self.calendar.show()
    # To Calculate time delta
    def yearsago(self, years, from_date=None):
        if from_date is None:
            from_date = datetime.now()
        return from_date - relativedelta(years=years)

    # General function for "Years" buttons
    def YearsAuto_Gen(self, year, fromField, toField):
        current_time = datetime.datetime.now()
        todayD = str(current_time.year) + "-" + str(current_time.month) + "-" + str(current_time.day)
        toField.setText(todayD)
        u = datetime.datetime.strptime(todayD,'%Y-%m-%d')
        t = self.yearsago(year, u)
        fromField.setText(str(t.strftime('%Y-%m-%d')))
    # Searching Stock Section
    def tenY(self):                 # 10 Years from today
        self.YearsAuto_Gen(10, self.lineEdit_from_ss, self.lineEdit_to_ss)
    def fiveY(self):                # 5 Years from today
        self.YearsAuto_Gen(5, self.lineEdit_from_ss, self.lineEdit_to_ss)
    def threeY(self):               # 3 Years from today
        self.YearsAuto_Gen(3, self.lineEdit_from_ss, self.lineEdit_to_ss)
    def oneY(self):                 # 1 Year from today
        self.YearsAuto_Gen(1, self.lineEdit_from_ss, self.lineEdit_to_ss)
    # Training Configuration Section
    def tenY_tc(self):                 # 10 Years from today
        self.YearsAuto_Gen(10, self.lineEdit_from_tc, self.lineEdit_toCal_tc)
    def fiveY_tc(self):                # 5 Years from today
        self.YearsAuto_Gen(5, self.lineEdit_from_tc, self.lineEdit_toCal_tc)
    def threeY_tc(self):               # 3 Years from today
        self.YearsAuto_Gen(3, self.lineEdit_from_tc, self.lineEdit_toCal_tc)
    def oneY_tc(self):                 # 1 Year from today
        self.YearsAuto_Gen(1, self.lineEdit_from_tc, self.lineEdit_toCal_tc)

if __name__=='__main__':
    app=QApplication(sys.argv)
    ims=MainClass()
    ims.show()
    app.exec_()
