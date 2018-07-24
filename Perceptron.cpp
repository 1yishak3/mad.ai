//
// Created by yitzhaq_m on 7/17/18.
//
#include "Perceptron.h"
#include <math.h>
#include <stdio.h>
#include <ctime>


Perceptron::Perceptron(vector < vector<double>> data) {
    this.learningRate = 0.2;
    this->data=data;
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
        float vict[]= this.data[tmp];
        double propy = (vict[0]*this.getWeight1())+(vict[1]*this.getWeight2())+this.getBias();
        double pred = this->sigmoid(propy);
        double targ = vict[2];
        costp=2*(pred-targ);
        predp=this->sigmoid_p(propy);
        i++;
    }

}
void Perceptron::test() {

}
void Perceptron::predict(vector< vector<double> > data) {

}


