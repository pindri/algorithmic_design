set terminal epslatex size 8.5cm,7cm color
set output 'mytest.tex'

set xlabel '$\alpha\beta\gamma$'
plot 1/x title '$\frac{1}{x}$'
set output 
