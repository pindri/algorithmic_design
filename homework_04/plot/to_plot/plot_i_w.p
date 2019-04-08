reset

set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "InsertionSort: worst case"

f(x) = a + b*x**2

fit f(x) "InsertionSort_worst.dat" via  a, b

plot "InsertionSort_worst.dat" u 1:2 w p pointtype 7 ps 0.35 t "InsertionSort", f(x) t "a+b*x**2"
