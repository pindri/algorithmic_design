#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEM_VALUE 20



int IntPow(int base, int exp) {
  int result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp /= 2;
    base *= base;
  }
  return result;
}


void PrintArray(const int array[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}


void PrintFloatArray(const float array[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%.3f ", array[i]);
  }
  printf("\n");
}


void RandomlyFillArray(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % MAX_ELEM_VALUE;
  }
}


void RandomNDigitsFillArray(int array[], const size_t size, const int n) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % ( IntPow(10, n) - IntPow(10, n-1) ) + IntPow(10, n-1);
  }
}


void UniformFillArray(float array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = (float)rand()/(float)(RAND_MAX/1.);
  }
}


void ZeroFillArray(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}


void Swap(int heap[], const int i, const int m, const size_t size) {
  if ( i <= size && m <= size ) {
    int tmp1 = heap[i];
    int tmp2 = heap[m];
    heap[i] = tmp2;
    heap[m] = tmp1;
  }
}


void SwapFloat(float array[], const int i, const int m, const size_t size) {
  if (i <= size && m <= size) {
    float tmp1 = array[i];
    float tmp2 = array[m];
    array[i] = tmp2;
    array[m] = tmp1;
  }
}
