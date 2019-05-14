#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utilities.h"
#include "sort.h"
#include "heapify.h"
#include "cptimer.h"
#include "macro.h"
#include "asvector.h"
#include "quicksort_best_case.h"



int main() {


#ifdef BENCHMARK

  /*************************************
   * Benchmarking best and worst cases.*
   *************************************/

  double start_timing, end_timing;

  FILE *insf_b = fopen("InsertionSort_best.dat", "a");
  FILE *quickf_b = fopen("QuickSort_best.dat", "a");
  FILE *insf_w = fopen("InsertionSort_worst.dat", "a");
  FILE *quickf_w = fopen("QuickSort_worst.dat", "a");

  for (int dim = 1000; dim < 50000; dim = dim + 1000) {

    int bench[dim];
    int bench_size = LENGTH(bench);

    // INSERTIONSORT TAKES N^2 FOR WORST CASE
    RandomlyFillArray(bench, bench_size);
    InsertionSort(bench, bench_size);
    ReverseArray(bench, bench_size); // Compute reversely order array.
    start_timing = Seconds();
      InsertionSort(bench, bench_size);
    end_timing = Seconds() - start_timing;
    fprintf(insf_w, "%d\t%f\n", dim, end_timing);


    // QUICKSORT TAKES N^2 FOR WORST CASE
    ZeroFillArray(bench, bench_size); // Compute reversely order array.
    start_timing = Seconds();
      QuickSort(bench, 0, bench_size - 1, bench_size);
    end_timing = Seconds() - start_timing;
    fprintf(quickf_w,"%d\t%f\n",dim, end_timing);


    // INSERTIONSORT TAKES N FOR BEST CASE
    RandomlyFillArray(bench, bench_size);
    InsertionSort(bench, bench_size);
    start_timing = Seconds();
      InsertionSort(bench, bench_size);
    end_timing = Seconds() - start_timing;
    fprintf(insf_b, "%d\t%f\n", dim, end_timing);


    // QUICKSORT TAKES NLOGN FOR BEST CASE
    BestQuick(bench, bench_size);
    start_timing = Seconds();
      QuickSort(bench, 0, bench_size - 1, bench_size);
    end_timing = Seconds() - start_timing;
    fprintf(quickf_b,"%d\t%f\n",dim, end_timing);

  }
    fclose(insf_b);
    fclose(quickf_b);
    fclose(insf_w);
    fclose(quickf_w);



#else


  /**************************************
   * Testing the implemented algorithms.*
   **************************************/


  int test[20];
  int size_test = LENGTH(test);

  // INSERTION SORT

  printf("Insertion Sort\n");
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  InsertionSort(test, size_test);
  PrintArray(test, size_test);


  // QUICK SORT
  LINE;

  printf("Quick Sort\n");
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  QuickSort(test, 0, size_test - 1, size_test);
  PrintArray(test, size_test);


  // HEAP SORT
  LINE;

  printf("Heap Sort\n");
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  HeapSort(test, size_test);
  PrintArray(test, size_test);


  // COUNTING SORT
  // assumes uniform distribution and bounded domain for the array values
  LINE;

  printf("Counting Sort\n");
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);
  int B[size_test]; // The sorted vector will be stored here.

  CountingSort(test, B, MAX_ELEM_VALUE, size_test);
  PrintArray(B, size_test);


  // RADIX SORT
  // Assumes n_digits to be at most 10.
  LINE;

  int n_digits = 3;

  printf("Radix Sort\n");
  RandomNDigitsFillArray(test, size_test, n_digits);
  PrintArray(test, size_test);

  RadixSort(test, size_test, n_digits);
  PrintArray(test, size_test);


  // BUCKET SORT
  LINE;

  float bucket[10];
  int size_bucket = LENGTH(bucket);

  printf("Bucket Sort\n");
  UniformFillArray(bucket, size_bucket);
  PrintFloatArray(bucket, size_bucket);

  BucketSort(bucket, size_bucket);
  PrintFloatArray(bucket, size_bucket);


  // SELECT
  LINE;

  printf("Quick Select\n");
  RandomlyFillArray(test, size_test);
  PrintArray(test, size_test);

  int position = 13;

  int prediction = Select(test, position, 0, size_test - 1, size_test);

  HeapSort(test, size_test);
  printf("The value in position %d should be %d: it is %d\n",position, prediction, test[position]);

#endif

}
