//
// Created by yitzhaq_m on 7/17/18.
//
// Current implementation assumes just 3 columns per row. 2 features and their result.
// Uses linear sum
// This is a non-gpu implementation, BEWARE the processing power consumption of a hundred million for loops on a single thread
#include "Perceptron.h"
#include <math.h>
#include <stdio.h>
#include <ctime>

// TODO: Implement using the GPU, especially the for-loop
// TODO: perhaps keep a hashset record of already visited data points in the train data

Perceptron::Perceptron(vector < vector<double>> train_data, vector < vector<double>> test_data) {
    this.learningRate = 0.2;
    this->train_data=train_data;
    this->test_data=test_data
    srand(time(0));
    this->setWeight1(rand());
    srand(time(0));
    this->setWeight2(rand());
    srand(time(0));
    this->setBias(rand());

}
double Perceptron::sigmoid(double x) {
    return 1/(1+exp(-1*x));
}
double Perceptron::sigmoid_p(double x) {
    return sigmoid(x)*(1-sigmoid(x));
}
void Perceptron::setLearningRate(double x){
    this.learningRate=x;

}
void Perceptron::train() {
    int i  = 0;

    
    while(i<100000000){
        srand(time(0));
        double tmp  = rand();
        vector<double> vict= this.train_data[tmp];
        double propy = (vict[0]*this.getWeight1())+(vict[1]*this.getWeight2())+this.getBias();
        double pred = this->sigmoid(propy);
        double targ = vict[2];
        double costp=2*(pred-targ);
        double predp=this->sigmoid_p(propy);
        double cost = pow(pred-targ, 2.0);
        double sc = costp*predp;
        //these two are because the derivative fo w1 & w2 would be their coefficients
        double scw1 = sc*point[0];
        double scw1 = sc*point[1];
        double scb = sc*this->getBias();
        this->setWeight1(this->getWeight1()-(this->learningRate*scw1));
        this->setWeight2(this->getWeight2()-(this->learningRate*scw2));
        this->setBias((this->getBias())-(this->learningRate*scb));
        i++;
    }

}
void Perceptron::test() {
    for(int i=0;i<(this->test_data).size(); i++){
        vector<double> datum=(this->test_data)[i];
        double propy=(datum[0]*this->getWeight1())+(datum[1]+this->getWeight2())+this->getBias();
        double predi=this->sigmoid(propy);
        printf("Actual:\t[%d, %d] =>%d", datum[0], datum[1], datum[2]);
        printf("Prediction:\t[%d, %d] =>%d", datum[0], datum[1], predi);
    }
}
double Perceptron::predict(vector<double> data) {
    double z =  this->getWeight1()*data[0] + this->getWeight2()*data[1] + this->getBias();
    double pred = this->sigmoid(z);
    return pred;
}


