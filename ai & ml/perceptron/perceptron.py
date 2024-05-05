import numpy as np
import sklearn
from sklearn import datasets
from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import random
from sklearn.preprocessing import StandardScaler


# load the data set
img, label = sklearn.datasets.load_breast_cancer(return_X_y=True)
# split the data set
TRAIN_SIZE = 511
label = 2*label-1  # convert labels to -1 and 1
train_img, test_img = img[:TRAIN_SIZE], img[TRAIN_SIZE:]
train_label, test_label = label[:TRAIN_SIZE], label[TRAIN_SIZE:]


class Perceptron(object):
    def __init__(self, dim_input=30, dim_out=2, learning_rate=1):
        # model parameters
        self.w = np.zeros(dim_input)
        self.bias = 0.0

        # learning rate
        self.learning_rate = learning_rate

    def predict(self, input_array):
        # See the "Perceptron learning rule" slides: w * x
        # Calculate dot product of weights and the input array, add the bias
        output = np.dot(self.w, input_array) + self.bias
        # Apply the step function
        return np.where(output >= 0, 1, -1)

    def train(self, training_inputs, labels):
        for inputs, label in zip(training_inputs, labels):
            prediction = self.predict(inputs)
            # Update weights and bias
            self.w += self.learning_rate * (label - prediction) * inputs
            self.bias += self.learning_rate * (label - prediction)

    def test(self, testing_inputs, labels):
        # number of correct predictions
        count_correct = 0
        # a list of the predicted labels the same order as the input 
        pred_list = []
        for test_array, label in zip(testing_inputs,labels):
            prediction = self.predict(test_array)
            if prediction == label:
                count_correct += 1
            pred_list.append(prediction)
        accuracy = float(count_correct)/len(test_label)
        print('Accuracy is '+str(accuracy))
        return np.asarray(pred_list)


# Feature scaling
scaler = StandardScaler()
train_img = scaler.fit_transform(train_img)
test_img = scaler.transform(test_img)

np.random.seed(42)

# Number of epochs (iterations over the training set)
NUM_EPOCH = 500

perceptron = Perceptron(learning_rate=0.5)
for ii in range(NUM_EPOCH):
    # Shuffle the training data
    permutation = np.random.permutation(len(train_img))
    train_img, train_label = train_img[permutation], train_label[permutation]
    
    perceptron.train(train_img, train_label)
    print(str(ii) + ' epochs')
    pred_array = perceptron.test(test_img, test_label)
