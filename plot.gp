set title 'Linear Regression'
set xlabel 'X'
set ylabel 'Y'
plot 'linear_regression_data.txt' using 1:2 with points pt 7 title 'Actual Data', \
     'linear_regression_data.txt' using 1:3 with lines title 'Regression Line'
