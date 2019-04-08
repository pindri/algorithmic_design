reset

set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "QuickSort: best case"
f(x) = 1.733804029574472E-03 +4.385397344262704E-07*x*log(1.883245480330791E-04*x)

plot "QuickSort_best.dat" u 1:2 w p pointtype 7 ps 0.35 t "QuickSort", f(x) t "a+b*xlog(c*x)"
