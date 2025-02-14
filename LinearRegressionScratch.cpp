/*
Start date: 14/02/2025
End date: 15/02/2025
A scratch implemetation of linear regression in C++.
==========================================================================================
simple regression line:
(y-y_mean) = m*(x-x_mean)+b
b = intercept
b = y_mean - m * x_mean 
m = slope
m = (x[i]-x`)(y[i]-y`)/(x[i]-x`)(x[i]-x`)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

double slopeNumerator(const std::vector<int>& X, const std::vector<int>& y, double x_mean, double y_mean) {
    double numerator = 0.0;
    for (size_t i = 0; i < X.size(); i++)
        numerator += (X[i] - x_mean) * (y[i] - y_mean);
    return numerator;
}

double slopeDenominator(const std::vector<int>& X, double x_mean) {
    double denominator = 0.0;
    for (size_t i = 0; i < X.size(); i++)
        denominator += (X[i] - x_mean) * (X[i] - x_mean);
    return denominator;
}

double slopeCalculation(double numerator, double denominator) {
    return numerator / denominator; 
}

double interceptCalculation(double x_mean, double y_mean, double slope) {
    return y_mean - slope * x_mean;
}

void LinearRegression() {
    std::vector<int> X = {1, 2, 3, 4, 5};
    std::vector<int> y = {2, 4, 1, 6, 5};
    double x_sum = 0.0, y_sum = 0.0;
    for (size_t i = 0; i < X.size(); i++) {
        x_sum += X[i];
        y_sum += y[i];
    }

    double x_mean = x_sum / X.size();
    double y_mean = y_sum / y.size();
    double numerator = slopeNumerator(X, y, x_mean, y_mean);
    double denominator = slopeDenominator(X, x_mean);
    double m = slopeCalculation(numerator, denominator);
    double c = interceptCalculation(x_mean, y_mean, m);

    std::vector<double> predictions;
    for (size_t i = 0; i < X.size(); i++) {
        double y_pred = m * X[i] + c;
        predictions.push_back(y_pred);
    }

    std::cout << "Slope (m): " << m << std::endl;
    std::cout << "Intercept (c): " << c << std::endl;
    std::cout << "Data and Predictions:" << std::endl;
    for (size_t i = 0; i < X.size(); i++) {
        std::cout << "x = " << X[i] << ", actual y = " << y[i]
             << ", predicted y = " << predictions[i] << std::endl;
    }
    std::ofstream outFile("linear_regression_data.txt");
    outFile << "# x  actual_y  predicted_y\n";
    for (size_t i = 0; i < X.size(); i++) {
        outFile << X[i] << " " << y[i] << " " << predictions[i] << "\n";
    }
    outFile.close();

     // Create a Gnuplot script file for vizualization
    std::ofstream gpFile("plot.gp");
     gpFile << "set title 'Linear Regression'\n";
     gpFile << "set xlabel 'X'\n";
     gpFile << "set ylabel 'Y'\n";
     gpFile << "plot 'linear_regression_data.txt' using 1:2 with points pt 7 title 'Actual Data', \\\n";
     gpFile << "     'linear_regression_data.txt' using 1:3 with lines title 'Regression Line'\n";
     gpFile.close();
 
     // Call Gnuplot to display the plot
     system("gnuplot -p plot.gp");
 }


int main() {
    LinearRegression();
    return 0;
}
