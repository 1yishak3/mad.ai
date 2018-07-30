//yitzhaqm(Yishak Tofik Mohammed)

#ifndef __PERCEPTRON_H__
#define  __PERCEPTRON_H__

using namespace std;
class Perceptron{
    public:
        // TODO:
        // Maybe you can set the no-arguments constructor
        // as the sample runner.
        // Maybe with Iris dataset
        // Exclude for now
        //Perceptron();
        // usable constructor
        Perceptron(vector<vector<double>> data );
        //destructor
        ~Perceptron();

        void train();
        void test();
        void predict(vector<vector<double>> *data);
        double sigmoid(double x);
        double sigmoid_p(double x);
        double getWeight1(){return weight1;}
        double getWeight2(){return weight2;}
        double getBias(){return bias;}
        void setBias(double x){bias=x;}
        void setWeight1(double x){weight1=x;}
        void setWeight2(double x){weight2=x;}
        vector<vector<double>> train_data;
        vector<vector<double>> test_data;
        double learningRate;


    private:

        double weight1;
        double weight2;
        double bias;

};