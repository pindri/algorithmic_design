reset

set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "Select"

f(x) = a + b*x

fit f(x) "Select.dat" via  a, b

plot "Select.dat" u 1:2 w p pointtype 7 ps 0.35 t "Select", f(x) t "a+b*x"
