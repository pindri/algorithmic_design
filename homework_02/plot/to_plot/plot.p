reset

set key left top
set xlabel "Number of matrices"
set ylabel "Optimized chain / naive multiplication"
set title "Chain matrix algorithm: relative number of operations."

plot "output.txt" u 1:2 w lp pointtype 7 ps 0.3 t ""
