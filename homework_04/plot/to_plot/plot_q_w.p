reset

set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "QuickSort: worst case"

f(x) = a + b*x**2

fit f(x) "QuickSort_worst.dat" via  a, b

plot "QuickSort_worst.dat" u 1:2 w p pointtype 7 ps 0.35 t "QuickSort", f(x) t "a+b*x**2"
