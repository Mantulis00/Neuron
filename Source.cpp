#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>     
#include <time.h>  

#define N 20
#define NBrute 3
#define epsilon 0.01



double Sigmoid(double weight) // returns sigmoid activation result 
{
    double e = 2.718;
    return (1 / (1+pow(e, -weight)));
}

double Threshold(double weight) // returns threshold activation result
{
    double threshold = 0;
    if (weight >= threshold) return 1;
    return 0;
}



bool CheckConditionThreshold(double* inputs, double* weights, double* results)
{
    int count = 4;
    for (int x = 0; x < count; x ++) // 0 3 6 9
    {
        int i = x * NBrute;
        double wa = inputs[0] * weights[i] + inputs[1] * weights[(i + 1)] + inputs[2] * weights[(i + 2)];
        double a = Threshold(wa);
        double r = results[x];
        if (abs(a - r) > epsilon)
            return false;
    }
    return true;
}

bool CheckConditionSigmoid(double* inputs, double* weights, double* results)
{
    int count = 4;
    for (int x = 0; x < count; x++) // 0 3 6 9
    {
        int i = x * NBrute;
        double wa = inputs[0] * weights[i] + inputs[1] * weights[(i + 1)] + inputs[2] * weights[(i + 2)];
        double a = Sigmoid(wa);
        double r = results[x];
        if (abs(a - r) > epsilon)
            return false;
    }
    return true;
}


void BruteThreshold(double* weights, double* results)
{
    bool threshFound = false, sigmoidFound = false;
    for (double w0 = -30; w0 < 30; w0+=0.1)
    {
        //std::cout << '\n' << w0 / 100 << '\n';
        for (double w1 = -30; w1 < 30; w1+=0.1)
        {
            for (double w2 = -30; w2 < 30; w2+=0.1)
            {
                double inputs[NBrute] = {w0,w1,w2 };
                //std::cout <<  "w0 " << w0 << "w1 " << w1 << "w2 " << w2 << '\n';
                if (CheckConditionThreshold(inputs, weights, results) && !threshFound)
                {
                    std::cout << "Correct Threshold weights: " << '\n' << "w0 =" << w0 << '\n' << " " << "w1 = " << w1 << '\n' << " " << "w2 " << w2 << '\n';
                    threshFound = true;
                }
                if (CheckConditionSigmoid(inputs, weights, results) && !sigmoidFound)
                {
                    std::cout <<'\n' << "Correct Sigmoid weights: " << '\n' << "w0 =" << w0 << '\n' << " " << "w1 = " << w1 << '\n' << " " << "w2 " << w2 << '\n';
                    sigmoidFound = true;
                }
                if (sigmoidFound && threshFound) return;
            }
        }
    }
}

void BruteSigmoid(double weight, int count)
{

}



int main()
{

    double inputs[N] = { 1, -0.2, 0.5, 1, 0.2, -0.5, 1, 0.8, -0.8, 1, 0.8, 0.8 };// GenerateInputs(n);
    double results[4] = { 0, 0, 1, 1 };

    BruteThreshold(inputs, results);
}
