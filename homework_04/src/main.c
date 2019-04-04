#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utilities.h"
#include "sort.h"
#include "heapify.h"


int main() {

  int test[10];
  int size_test = LENGTH(test);


  // INSERTION SORT

  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  InsertionSort(test, size_test);
  PrintArray(test, size_test);


  // QUICK SORT
  LINE;

  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  QuickSort(test, 0, size_test - 1, size_test);
  PrintArray(test, size_test);


  // HEAP SORT
  LINE;

  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  HeapSort(test, size_test);
  PrintArray(test, size_test);


  // COUNTING SORT
  // assumes uniform distribution and bounded domain for the array values
  LINE;
  
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);
  int B[size_test]; // The sorted vector will be stored here.

  CountingSort(test, B, MAX_ELEM_VALUE, size_test);
  PrintArray(B, size_test);


  // RADIX SORT
  LINE;

  int n_digits = 3;
  
  RandomNDigitsFillArray(test, size_test, n_digits);
  PrintArray(test, size_test);

  RadixSort(test, size_test, n_digits);
  PrintArray(test, size_test);


  // BUCKET SORT
  LINE;

  float bucket[10];
  int size_bucket = LENGTH(bucket);

  UniformFillArray(bucket, size_bucket); 
  PrintFloatArray(bucket, size_bucket);

  BucketSort(bucket, size_bucket);
  PrintFloatArray(bucket, size_bucket);

}
