#!/bin/bash

make benchmark

> output.txt

for lenght in {2..40..1}
do
  ./benchmark.x $lenght >> output.txt
done


