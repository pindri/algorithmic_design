reset

set key left top
set xlabel "Number of Vertices"
set ylabel "Execution time [s]"
set title "Dijkstra algorithm, array and heap implementation"


plot "output.dat" u 1:2 w p pointtype 7 ps 0.35 t "Array qyeye", "" u 1:3 w p pointtype 7 ps 0.35 t "Heap queue"
