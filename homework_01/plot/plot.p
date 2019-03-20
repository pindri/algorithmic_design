reset                                                                       


set key left top
set xlabel "Matrix size"                                     
set ylabel "Time [s]"                                             
                                                                             
set title "Matrix-matrix multiplication, runtime comparison"
              
plot "mean.dat" u 1:2 w lp pointtype 7 ps 0.5 t "Naive", "" u 1:3 w lp pointtype 7 ps 0.5 t "Strassen", "" u 1:4 w lp pointtype 7 ps 0.5 t "Optimized Strassen"
