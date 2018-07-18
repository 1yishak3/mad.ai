//yitzhaqm(Yishak Tofik Mohammed)

#ifndef __PERCEPTRON_H__
#define  __PERCEPTRON_H__

using namespace std;
class Perceptron{
    public:
        //TODO:
        // Maybe you can set the no-arguments constructor
        // as the sample runner.
        // Maybe with Iris dataset
        // Exclude for now
        //Perceptron();
        //usable constructor
        Perceptron(vector<vector<double>> data );
        //destructor
        ~Perceptron();

        void train();
        void test();
        void predict(vector<vector<double>> data);


    private:
        vector<vector<double>> data;
        double weight1;
        double weight2;
        double bias;
};