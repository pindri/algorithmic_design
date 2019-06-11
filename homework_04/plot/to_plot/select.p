reset

set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "InsertionSort: best case"

f(x) = a + b*x

fit f(x) "Select.dat" via  a, b

plot "InsertionSort_best.dat" u 1:2 w p pointtype 7 ps 0.35 t "InsertionSort", f(x) t "a+b*x"
