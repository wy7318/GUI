from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
import scipy.special as sc
from scipy import optimize
import csv, math
import pyqtgraph as pg
import StockGUI
import sys
import math
import pandas_datareader as web
import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from keras.models import Sequential
from keras.layers import Dense, LSTM
import matplotlib.pyplot as plt



class MainClass(QDialog,StockGUI.Ui_Dialog):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        
        ###################Stryling Graph###########################
        label_style = {'color': '#EEE', 'font-size': '10pt'}
        self.graph = pg.PlotWidget(title="Stock Market")
        self.graph.showGrid(x = True, y = True, alpha = 0.3)
        self.graph.setLabel('left', "USD ($)")
        self.graph.getAxis('left').setLabel(**label_style)
        self.graph.getAxis('bottom').setLabel(**label_style)
        self.graph.setLabel('bottom', "Period (Year)")

        font=QtGui.QFont()
        font.setPixelSize(15)
        self.graph.getAxis("bottom").tickFont = font
        # self.graph.getAxis("bottom").setStyle(tickTextOffset=20)
        self.graph.getAxis("left").tickFont = font
        # self.graph.getAxis("left").setStyle(tickTextOffset=20)
        # self.graph.setYRange(-120,10)

        self.gridLayout_graph.addWidget(self.graph, 0, 0)
        self.plot1 = self.graph.plot(pen='r')
        self.plot2 = self.graph.plot(pen='b')
        self.plot3 = self.graph.plot()
        self.plot1.show()


        self.pushButton_search_ss.clicked.connect(self.showStock)

    def showStock(self):
        df = web.DataReader('TSLA', data_source='yahoo', start = '2020-01-01', end='2021-10-28')
        print(df.index)
        self.plot1.setData(df['Close'])
        self.plot2.setData(df['Open'])
        self.plot1.show()
        self.plot2.show()
        # listdate2 = pd.date_range(start="2020-01-01",end="2021-10-25")
        # print(listdate2)





if __name__=='__main__':
    app=QApplication(sys.argv)
    ims=MainClass()
    ims.show()
    app.exec_()
