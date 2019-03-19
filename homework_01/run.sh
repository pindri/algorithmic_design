#!/bin/bash
make
> strassen_output.dat
for j in {1..10}
do
  echo "Performing iteration $j"
  ./strassen_test.x >> strassen_output.dat;
done
