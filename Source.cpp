#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>     
#include <time.h>  

#define N 20


double* InputWeights(int n)
{
    static double weights[N];

    for (int x = 0; x < n; x++)
    {
        std::cin >> weights[x];
    }
    
    return weights;
}

double* GenerateInputs()
{
    static double inputs[N];

    for (int x = 0; x < N; x++)
    {
        inputs[x] = (rand() % 20000) / 10000.0 - 1;
    }
    return inputs;
}

double Sigmoid(double weight)
{
    double e = 2.718;
    return (1 / (1+pow(e, -weight)));
}

double Threshold(double weight)
{
    double threshold = 0;
    if (weight >= threshold) return 1;
    return 0;
}

double GetWeight(int n, double w0, double* weights, double* inputs)
{
    double weight = w0;
    for (int x = 0; x < n; x++)
    {
        weight += inputs[x] * weights[x];
        std::cout << '\n' << "Weight: " << inputs[x] << " * " << weights[x] << '\n';
    }
    return weight;
}

void PrintInputs(int n, double* weights, double* inputs)
{
    std::cout << '\n' << "Inputs: " << '\n' << '\n';

    std::cout << "w" << 0 << " = " << 0 << " x" << 0 << " = " << 1 << '\n';
    for (int x = 0; x < n; x++)
    {
        std::cout << "w" << x+1 << " = " << weights[x] << " x" << x+1 << " = " << inputs[x] << '\n';
    }
}

void PrintResults(double weight)
{
    std::cout << '\n' << "Results: " << '\n' ;
    std::cout << '\n' << "Weight: " << weight << '\n';
    std::cout << '\n' << "Sigmoid: " << Sigmoid(weight) << '\n';
    std::cout << '\n' << "Threshold: " << Threshold(weight) << '\n';
}



int main()
{
    int n;
    std::cin >> n;

    double* inputs = GenerateInputs();
    double* weights;
    weights = InputWeights(n);

    double w0 = 1;
    double weight = GetWeight(n, w0, weights, inputs);

    PrintInputs(n, weights, inputs);
    PrintResults(weight);
}
