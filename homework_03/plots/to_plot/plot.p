reset

set format x "%.0s*10^%S"
set key left top
set xlabel "Number of elements"
set ylabel "Execution time [s]"
set title "build_heap function: execution time vs number of elements" noenhanced

plot "benchmark.dat" u 1:2 w lp pointtype 7 ps 0.2 t ""
