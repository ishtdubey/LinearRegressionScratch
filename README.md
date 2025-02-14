# LinearRegressionScratch
Implement Linear Regression from scratch without any external libraries for itself, using C++
Linear Regression Implementation in C++

Overview
This project implements a simple linear regression algorithm in C++. It calculates the best-fit line for a set of data points using the least squares method. The implementation includes data visualization capabilities using Gnuplot.
Mathematical Background
The implementation is based on the simple regression line equation:
Copy(y - y_mean) = m*(x - x_mean) + b
where:

intercept, c = y_mean - m * x_mean
slope, m = Σ(x[i] - x_mean)(y[i] - y_mean) / Σ(x[i] - x_mean)²

Features:
Calculates slope and intercept of the regression line
Generates predictions for input data points
Outputs results to console and file
Creates visualization using Gnuplot
Modular design with separate functions for different calculations

Dependencies:
C++ compiler with C++11 support
Gnuplot (for visualization)
Standard C++ libraries: iostream, vector, fstream, cmath

File Structure
LinearRegressionScratch.cpp: Contains the complete implementation
linear_regression_data.txt: Generated output file with actual and predicted values
plot.gp: Generated Gnuplot script for visualization

Functions:
slopeNumerator(): Calculates the numerator for slope calculation
slopeDenominator(): Calculates the denominator for slope calculation
slopeCalculation(): Computes the final slope value
interceptCalculation(): Computes the y-intercept
LinearRegression(): Main function implementing the algorithm
main(): Entry point of the program

Usage:
Compile the code:
g++ LinearRegressionScratch.cpp -o linear_regression

Run the executable:
./linear_regression

The program will:
Calculate and display slope and intercept
Show actual vs predicted values
Generate a data file (linear_regression_data.txt)
Create and display a plot using Gnuplot



Output
The program generates:
Calculated slope and intercept
Table of actual vs predicted values

Data file containing:
X values
Actual Y values
Predicted Y values

Visualization showing:
Scatter plot of actual data points
Regression line

Time Frame:
Start Date: 14/02/2025
End Date: 15/02/2025

Current Limitations:
Works with integer input data only
Fixed input dataset in the code
Basic error handling
No support for multivariate regression

Future Improvements:
Add support for floating-point input data
Implement data input from files
Add error metrics (R², MSE, etc.)
Enhance error handling
Add support for multivariate regression
