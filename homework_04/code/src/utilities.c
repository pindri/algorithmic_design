#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "asvector.h"
#include "macro.h"



// Computes base^exp, returning an integer.
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


// Randomly fills an integer array with positive values of n digits.
void RandomNDigitsFillArray(int array[], const size_t size, const int n) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % ( IntPow(10, n) - IntPow(10, n-1) ) + IntPow(10, n-1);
  }
}


/**
 * Randomly fills an integer array with positive values drawn from a
 * uniform distribution in [0,1].
 */
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



void Swap(int array[], const int i, const int m, const size_t size) {
  if (i <= size && m <= size) {
    int tmp1 = array[i];
    int tmp2 = array[m];
    array[i] = tmp2;
    array[m] = tmp1;
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


int MaxElem(int array[], const size_t size) {
  int max = array[0];
  for(size_t i = 0; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}


int MinElem(int array[], const size_t size) {
  int min = array[0];
  for(size_t i = 0; i < size; i++) {
    if (array[i] < min) min = array[i];
  }
  return min;
}
