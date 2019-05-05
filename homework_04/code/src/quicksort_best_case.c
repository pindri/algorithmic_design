#include <stdlib.h>
#include "utilities.h"
#include "sort.h"



void ReverseArray(int array[], const size_t size) {
  int i = size - 1;
  int j = 0;

  while(i > j) {
    Swap(array, i, j, size);
    i--;
    j++;
  }
}

void OrderFill(int array[], const size_t size) {
  for(size_t i = 0; i < size; i++) {
    array[i] = i+1;
  }
}

void GenerateBest(int array[], size_t begin, size_t end, const size_t size) {
  int count = end - begin;
  if(count<3) return;
  int middle = begin + (count-1)/2;
  GenerateBest(array, begin, middle, size);
  Swap(array, begin, middle, size);
  GenerateBest(array, middle + 1, end, size);
}

void BestQuick(int array[], const size_t size) {
  OrderFill(array, size);
  GenerateBest(array, 0, size-1, size);
} 

