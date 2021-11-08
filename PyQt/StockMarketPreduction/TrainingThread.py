from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
import scipy.special as sc
from scipy import optimize
import csv, math

import sys
import math
import pandas_datareader as web
from yahoo_fin import stock_info as si
import numpy as np
import pandas as pd

from sklearn.preprocessing import MinMaxScaler
from keras.models import Sequential
from keras.layers import Dense, LSTM
import matplotlib.pyplot as plt
import datetime
from dateutil.relativedelta import relativedelta            #TimeDelta function

class TrainingConfig(QThread):
    serialSig = pyqtSignal(str)

    def __init__(self, trainingType, fromD, toD, trainingPercentage, TrainingPeriod, Epochs, parent=None):
        self.trainingType = trainingType
        self.fromD = fromD
        self.toD = toD
        self.trainingPercentage = trainingPercentage
        self.TrainingPeriod = TrainingPeriod
        self.Epochs = Epochs


        super(TrainingConfig, self).__init__(parent)
        #self.setupUi(self)

    def run(self):

