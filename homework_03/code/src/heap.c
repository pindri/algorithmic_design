#include <stdio.h>
#include <stdlib.h>
#include "cptimer.h"


#define MAX_ELEM_VALUE 1000000
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))

#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=
#define HEAP_ORDERING MIN_HEAP_ORDERING // Change this to change the ordering.


int GetRoot(const int heap[]) {
  return heap[0];
}


int RightChild(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return heap[2*(i+1)];
  } else {
    return 1./0.;
  }
}


int LeftChild(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return heap[2*(i+1)-1];
  } else {
    return 1./0.;
  }
}


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


void Swap(int heap[], const int i, const int m, const size_t size) {
  if ( i <= size && m <= size ) {
    int tmp1 = heap[i];
    int tmp2 = heap[m];
    heap[i] = tmp2;
    heap[m] = tmp1;
  }
}


void Heapify(int heap[], const int i, const size_t size) {
  int m = i;

  int j[2] = {GetLeftIndex(heap, i, size), GetRightIndex(heap, i, size)};

  for (int k = 0; k <= 1; ++k) {
    if (j[k] <= size && heap[j[k]] HEAP_ORDERING heap[m]) {
      m = j[k];
    }
  }

  if ( i != m ) {
    Swap(heap, i, m, size);
    Heapify(heap, m, size);
  }

}


void RemoveMinimum(int heap[], int* size) {
  heap[0] = heap[*size - 1];
  *size = *size -1;
  Heapify(heap, 0, *size);
}



void BuildHeap(int array[], const size_t size) {
  for (int i = (size/2 - 1); i >= 0; i--) { // Bottom up on each subtree.
    Heapify(array, i, size);
  }
}


int IsMinHeap(const int array[], const size_t size) {
  for (size_t i = 0; i <= (size-2)/2; i++) { // From root untill last internal node.
    if (LeftChild(array, i, size) < array[i]) return 0; // If left child is smaller.
    if ( GetRightIndex(array, i, size) != -1 && array[2*(i+1)] < array[i] ) return 0;
  }
  return 1;
}


int IsMaxHeap(const int array[], const size_t size) {
  for (size_t i = 0; i <= (size-2)/2; i++) { // From root untill last internal node.
    if (LeftChild(array, i, size) > array[i]) return 0; // If left child is greater.
    if ( GetRightIndex(array, i, size) != -1 && array[2*(i+1)] > array[i] ) return 0;
  }
  return 1;
}


void RandomlyFillArray(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % MAX_ELEM_VALUE;
  }
}



