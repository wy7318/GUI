from PyQt5.QtCore import *
import math
import pandas_datareader as web
import numpy as np
import tensorflow as tf
from sklearn.preprocessing import MinMaxScaler
from keras.models import Sequential
from keras.layers import Dense, LSTM
import matplotlib.pyplot as plt
keras = tf.keras
import datetime

'''
Next Day Prediction Thread
'''
class TrainingConfig(QThread):
    trainValidClosePredictSig = pyqtSignal(object, object, object)
    countChanged = pyqtSignal(int)
    statusChanged = pyqtSignal(str)
    PredictionSig = pyqtSignal(str, str)
    # validPredictSig = pyqtSignal(object)


    def __init__(self, tickers, trainingType, fromD, toD, trainingPercentage, TrainingPeriod, Epochs, parent=None):
        self.tickers = tickers
        self.trainingType = trainingType
        self.fromD = fromD
        self.toD = toD
        self.trainingPercentage = trainingPercentage
        self.TrainingPeriod = TrainingPeriod
        self.Epochs = Epochs


        super(TrainingConfig, self).__init__(parent)
        #self.setupUi(self)

    def run(self):

        ############Status Check#####################################
        count = 1                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Start Training...")
        #############################################################


        #Get the stock quote
        df = web.DataReader(self.tickers, data_source='yahoo', start = self.fromD, end= self.toD)
        print(df)
        modified = df.reset_index()
        print(modified['Date'])

        # Get the number of rows & columns in the dataset
        print(df.shape)

        ############Status Check#####################################
        count = 5                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Reshaping...")
        #############################################################

        # Create a new datafram with only the close column
        data = df.filter([self.trainingType])
        print(data)
        # Convert the dataframe to a numpy array
        dataset = data.values
        # Get the number of rows to train the model on
        # Train 80% of the data.
        training_data_len = math.ceil(len(dataset) * (int(self.trainingPercentage)*0.01))       # math.ceil is to round up
                                                                                                # Training Day Percentage
        print("training_data_len : ", training_data_len)

        ############Status Check#####################################
        count = 10                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Rescaling data...")
        #############################################################

        # Scale the data
        scaler = MinMaxScaler(feature_range=(0,1))
        scaled_data = scaler.fit_transform(dataset)     # Now the dataset will be scaled between 0 and 1
        print(scaled_data)

        # Create the training dataset
        # Create the scaled training dataset
        train_data = scaled_data[0:training_data_len, :]        # Get from index 0 to the training len
        print("train_data : ", train_data)
        # Split the data into x_train and y_train datasets
        x_train = []        # Independent variable
        y_train = []        # Dependent variable


        # Predicting with past x days data
        for i in range(int(self.TrainingPeriod), len(train_data)):
            x_train.append(train_data[i-int(self.TrainingPeriod):i, 0])       # x_train will contain past x days closing data
            y_train.append(train_data[i, 0])            # y_train will contain the x+1 day's closing data.

            # Check result
            if i<= int(self.TrainingPeriod):
                print(x_train)
                print(y_train)
                print()

        # Convert the x_train and y_train to numpy arrays
        x_train, y_train = np.array(x_train), np.array(y_train)

        # Reshape the data to meet LSTM's requirement (3D required)
        print(x_train.shape)                        #(1908, 60) Rows & Cols
        x_train = np.reshape(x_train, (x_train.shape[0], x_train.shape[1], 1))           # reshape number of samples, number of times, number of features
        # x_train.shape[0] = 1908, x_train_shape[1] = 60, feature is 1 because we have one output


        ############Status Check#####################################
        count = 15                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Building Model...")
        #############################################################

        # Build the LSTM model
        model = Sequential()
        model.add(LSTM(50, return_sequences=True, input_shape=(x_train.shape[1], 1)))       # Create first 50 layers, return_sequences is 'True' since there will be another LSTM model.
        # Input_shape is (number of times, number of features)
        model.add(LSTM(50, return_sequences=False))                                         # return_sequence is 'False' since there will be no more LSTM model.
        model.add(Dense(25))
        model.add(Dense(1))

        # Compile the model
        model.compile(optimizer='adam', loss='mean_squared_error')                          # Loss function is to determine how well the model did
        model.save("model.h5")

        newModel = tf.keras.models.load_model('model.h5')                                #Saving Model

        ############Status Check#####################################
        count = 55                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Training Model...")
        #############################################################

        # Train the model
        newModel.fit(x_train, y_train, batch_size=1, epochs=int(self.Epochs))

        # Create the testing data set
        # Create a new array containing scaled values
        test_data = scaled_data[training_data_len - int(self.TrainingPeriod):, :]

        # Create the data sets x_test and y_test
        x_test = []
        y_test = dataset[training_data_len:, :]     #from non-trained data set to the end.
        print("y_test : ", y_test)
        for i in range(int(self.TrainingPeriod), len(test_data)):
            x_test.append(test_data[i-int(self.TrainingPeriod):i, 0])
        print("x_test : ", x_test)
        # Convert the data to a numpy array
        x_test = np.array(x_test)

        # Reshape the data
        x_test = np.reshape(x_test, (x_test.shape[0], x_test.shape[1], 1))

        ############Status Check#####################################
        count = 70                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Un-scaling Data...")
        #############################################################

        # Get the models predicted price values
        predictions = newModel.predict(x_test)
        predictions = scaler.inverse_transform(predictions)     # Un-scaling value
        print(predictions)

        # Evaluate model. Get the root mean squared error (RMSE)
        rmse = np.sqrt( np.mean(predictions - y_test )**2 )

        # Plot the data
        train = data[:training_data_len]
        valid = data[training_data_len:]
        valid['Predictions'] = predictions
        # Visualize the data
        # plt.figure(figsize=(16, 8))
        # plt.title('Model')
        # plt.xlabel('Date', fontsize = 18)
        # plt.ylabel('Close Price USD ($)', fontsize=18)
        # plt.plot(train['Close'])
        # plt.plot(valid[['Close', 'Predictions']])
        # plt.legend(['Train', 'Val', 'Predictions'], loc = 'lower right')
        # plt.show()

        ############Status Check#####################################
        count = 88                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Visualizing Data...")
        #############################################################

        # Sending curve data through pyqtSignal
        self.trainValidClosePredictSig.emit(train[self.trainingType], valid[self.trainingType], valid['Predictions'])

        print("prediction Valid : ", valid['Predictions'])

        # Show the valid and predicted prices
        print(valid)

        #Get the quote
        tesla_quote = web.DataReader(self.tickers, data_source='yahoo', start = self.fromD, end= self.toD)

        # Create a new dataframe
        new_df = tesla_quote.filter([self.trainingType])
        # Get the last 60 days closing price values and convert the dataframe to array
        last_60_days = new_df[-int(self.TrainingPeriod):].values
        print("last_60_days", last_60_days)
        #Scale the data to be values between 0 and 1
        last_60_days_scaled = scaler.transform(last_60_days)
        # Create an empty list
        X_text = []
        # Append the past 60 days
        X_text.append(last_60_days_scaled)
        print("X-test ", X_text)
        # Convert the X_test data set to a numpy array
        X_text = np.array(X_text)
        # Reshape the data
        X_text = np.reshape(X_text, (X_text.shape[0], X_text.shape[1], 1))
        # Get the predicted scaled price
        pred_price = newModel.predict(X_text)
        #undo the scaling
        pred_price = scaler.inverse_transform(pred_price)
        print("Predicted price for 10/26/21 : ", pred_price)


        # Strip date and calculate next date
        lastDate = datetime.datetime.strptime(self.toD, '%Y-%m-%d')
        addDate = datetime.timedelta(days=1)
        predictDate = lastDate + addDate

        predictionString = str(predictDate.strftime('%Y-%m-%d'))
        predictVal = str(pred_price)[2:-2]                          # Strip prediction value, only to display number

        self.PredictionSig.emit(predictionString, predictVal)

        ############Status Check#####################################
        count = 100                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Completed!")
        #############################################################



'''
Period Prediction Thread
'''
class TrainingConfig_Period(QThread):
    trainValidClosePredictSig = pyqtSignal(object, object, object)
    countChanged = pyqtSignal(int)
    statusChanged = pyqtSignal(str)
    PredictionSig = pyqtSignal(str, str)
    # validPredictSig = pyqtSignal(object)


    def __init__(self, tickers, trainingType, fromD, toD, TrainingPeriod, PredictionPeriod, Epochs, parent=None):
        self.tickers = tickers
        self.trainingType = trainingType
        self.fromD = fromD
        self.toD = toD
        self.TrainingPeriod = TrainingPeriod
        self.PredictionPeriod = PredictionPeriod
        self.Epochs = Epochs


        super(TrainingConfig_Period, self).__init__(parent)
        #self.setupUi(self)

    def run(self):

        ############Status Check#####################################
        count = 1                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Start Training...")
        #############################################################


        #Get the stock quote
        df = web.DataReader(self.tickers, data_source='yahoo', start = self.fromD, end= self.toD)
        print(df)

        # Get the number of rows & columns in the dataset
        print(df.shape)

        ############Status Check#####################################
        count = 5                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Reshaping...")
        #############################################################

        # Create a new datafram with only the close column
        data = df.filter([self.trainingType])
        print(data)
        # Convert the dataframe to a numpy array
        dataset = data.values
        # Get the number of rows to train the model on
        # Train 100% of the data.
        training_data_len = math.ceil(len(dataset))       # math.ceil is to round up
        # Training Day Percentage
        print(training_data_len)

        ############Status Check#####################################
        count = 10                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Rescaling data...")
        #############################################################

        # Scale the data
        scaler = MinMaxScaler(feature_range=(0,1))
        scaled_data = scaler.fit_transform(dataset)     # Now the dataset will be scaled between 0 and 1
        print(scaled_data)

        # Create the training dataset
        # Create the scaled training dataset
        train_data = scaled_data[0:training_data_len, :]        # Get from index 0 to the training len
        print(train_data)
        # Split the data into x_train and y_train datasets
        x_train = []        # Independent variable
        y_train = []        # Dependent variable


        # Predicting with past x days data
        for i in range(int(self.TrainingPeriod), len(train_data)):
            x_train.append(train_data[i-int(self.TrainingPeriod):i, 0])       # x_train will contain past x days closing data
            y_train.append(train_data[i, 0])            # y_train will contain the x+1 day's closing data.

            # Check result
            if i<= int(self.TrainingPeriod):
                print(x_train)
                print(y_train)
                print()

        # Convert the x_train and y_train to numpy arrays
        x_train, y_train = np.array(x_train), np.array(y_train)

        # Reshape the data to meet LSTM's requirement (3D required)
        print(x_train.shape)                        #(1908, 60) Rows & Cols
        x_train = np.reshape(x_train, (x_train.shape[0], x_train.shape[1], 1))           # reshape number of samples, number of times, number of features
        # x_train.shape[0] = 1908, x_train_shape[1] = 60, feature is 1 because we have one output


        ############Status Check#####################################
        count = 15                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Building Model...")
        #############################################################

        # Build the LSTM model
        model = Sequential()
        model.add(LSTM(50, return_sequences=True, input_shape=(x_train.shape[1], 1)))       # Create first 50 layers, return_sequences is 'True' since there will be another LSTM model.
        # Input_shape is (number of times, number of features)
        model.add(LSTM(50, return_sequences=False))                                         # return_sequence is 'False' since there will be no more LSTM model.
        model.add(Dense(25))
        model.add(Dense(1))

        # Compile the model
        model.compile(optimizer='adam', loss='mean_squared_error')                          # Loss function is to determine how well the model did
        model.save("model.h5")

        newModel = tf.keras.models.load_model('model.h5')                                #Saving Model

        ############Status Check#####################################
        count = 55                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Training Model...")
        #############################################################

        # Train the model
        newModel.fit(x_train, y_train, batch_size=1, epochs=int(self.Epochs))

        # Create the testing data set
        # Create a new array containing scaled values
        test_data = scaled_data[training_data_len - int(self.TrainingPeriod):, :]

        # Create the data sets x_test and y_test
        x_test = []
        y_test = dataset[training_data_len:, :]     #from non-trained data set to the end.

        for i in range(int(self.TrainingPeriod), len(test_data)):
            x_test.append(test_data[i-int(self.TrainingPeriod):i, 0])

        # Convert the data to a numpy array
        x_test = np.array(x_test)

        # Reshape the data
        x_test = np.reshape(x_test, (x_test.shape[0], x_test.shape[1], 1))

        ############Status Check#####################################
        count = 70                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Un-scaling Data...")
        #############################################################

        # Get the models predicted price values
        predictions = newModel.predict(x_test)
        predictions = scaler.inverse_transform(predictions)     # Un-scaling value
        print(predictions)

        # Evaluate model. Get the root mean squared error (RMSE)
        rmse = np.sqrt( np.mean(predictions - y_test )**2 )

        # Plot the data
        train = data[:training_data_len]
        valid = data[training_data_len:]
        valid['Predictions'] = predictions
        # Visualize the data
        # plt.figure(figsize=(16, 8))
        # plt.title('Model')
        # plt.xlabel('Date', fontsize = 18)
        # plt.ylabel('Close Price USD ($)', fontsize=18)
        # plt.plot(train['Close'])
        # plt.plot(valid[['Close', 'Predictions']])
        # plt.legend(['Train', 'Val', 'Predictions'], loc = 'lower right')
        # plt.show()

        ############Status Check#####################################
        count = 88                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Visualizing Data...")
        #############################################################

        # Sending curve data through pyqtSignal
        self.trainValidClosePredictSig.emit(train[self.trainingType], valid[self.trainingType], valid['Predictions'])

        # Show the valid and predicted prices
        print(valid)

        #Get the quote
        tesla_quote = web.DataReader(self.tickers, data_source='yahoo', start = self.fromD, end= self.toD)

        # Create a new dataframe
        new_df = tesla_quote.filter([self.trainingType])
        # Get the last 60 days closing price values and convert the dataframe to array
        last_60_days = new_df[-int(self.TrainingPeriod):].values
        #Scale the data to be values between 0 and 1
        last_60_days_scaled = scaler.transform(last_60_days)
        # Create an empty list
        X_text = []
        # Append the past 60 days
        X_text.append(last_60_days_scaled)
        # Convert the X_test data set to a numpy array
        X_text = np.array(X_text)
        # Reshape the data
        X_text = np.reshape(X_text, (X_text.shape[0], X_text.shape[1], 1))
        # Get the predicted scaled price
        pred_price = newModel.predict(X_text)
        #undo the scaling
        pred_price = scaler.inverse_transform(pred_price)
        print("Predicted price for 10/26/21 : ", pred_price)


        # Strip date and calculate next date
        lastDate = datetime.datetime.strptime(self.toD, '%Y-%m-%d')
        addDate = datetime.timedelta(days=1)
        predictDate = lastDate + addDate

        predictionString = str(predictDate.strftime('%Y-%m-%d'))
        predictVal = str(pred_price)

        self.PredictionSig.emit(predictionString, predictVal)

        ############Status Check#####################################
        count = 100                       # Start counting for progressBar
        self.countChanged.emit(count)
        self.statusChanged.emit("Completed!")
        #############################################################