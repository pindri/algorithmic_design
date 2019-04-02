#include <stdio.h>
#include <stdlib.h>
#include "cptimer.h"

#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=

int get_root(const int heap[]) {
  return heap[0];
}

int right_child(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return heap[2*(i+1)];
  } else {
    return 1./0.;
  }
}

int left_child(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return heap[2*(i+1)-1];
  } else {
    return 1./0.;
  }
}

int get_right_index(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return 2*(i+1);
  } else {
    return -1;
  }
}

int get_left_index(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return 2*(i+1)-1;
  } else {
    return -1;
  }
}


void swap(int heap[], const int i, const int m, const size_t size) {
  if ( i <= size && m <= size ) {
    int tmp1 = heap[i];
    int tmp2 = heap[m];
    heap[i] = tmp2;
    heap[m] = tmp1;
  }
}


void heapify(int heap[], const int i, const size_t size) {
  int m = i;

  int j[2] = {get_left_index(heap, i, size), get_right_index(heap, i, size)};

  for (int k = 0; k <= 1; ++k) {
    if (j[k] <= size && heap[j[k]] MAX_HEAP_ORDERING heap[m]) {
      m = j[k];
    }
  }

  if ( i != m ) {
    swap(heap, i, m, size);
    heapify(heap, m, size);
  }

}


void remove_minimum(int heap[], int* size) {
  heap[0] = heap[*size - 1]; 
  *size = *size -1;
  heapify(heap, 0, *size);
}



void build_heap(int array[], const size_t size) {
  for (int i = (size/2 - 1); i >= 0; i--) { // Bottom up on each subtree.
    heapify(array, i, size);
  }
}

int is_heap(const int array[], const size_t size) {
  for (size_t i = 0; i <= (size-2)/2; i++) { // From root untill last internal node.
    if (left_child(array, i, size) < array[i]) return 0; // If left child is greater.
    if ( get_right_index(array, i, size) != -1 && array[2*(i+1)] < array[i] ) return 0;
  }
  return 1;
}



