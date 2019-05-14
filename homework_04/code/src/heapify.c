#include <stdio.h>
#include <stdlib.h>

#include "cptimer.h"
#include "utilities.h"

#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=


int GetRightIndex(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return 2*(i+1);
  } else {
    return -1;
  }
}



int GetLeftIndex(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return 2*(i+1)-1;
  } else {
    return -1;
  }
}



void Heapify(int heap[], const int i, const size_t size) {
  int m = i;

  int j[2] = {GetLeftIndex(heap, i, size), GetRightIndex(heap, i, size)};

  for (int k = 0; k <= 1; ++k) {
    if (j[k] <= size && heap[j[k]] MAX_HEAP_ORDERING heap[m]) {
      m = j[k];
    }
  }

  if ( i != m ) {
    Swap(heap, i, m, size);
    Heapify(heap, m, size);
  }

}



void BuildHeap(int array[], const size_t size) {
  for (int i = (size/2 - 1); i >= 0; i--) { // Bottom up on each subtree.
    Heapify(array, i, size);
  }
}


