#!/bin/bash


module load openmpi/1.8.3/gnu/4.9.2 
> InsertionSort_worst.dat
> InsertionSort_best.dat
> QuickSort_worst.dat
> QuickSort_best.dat

make benchmark
./benchmark.x

