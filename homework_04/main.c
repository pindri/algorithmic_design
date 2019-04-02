#include <stdio.h>
#include <stdlib.h>
#include "heapify.h"



#define MAX_ELEM_VALUE 20
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))
#define LINE printf("\n")


void print_array(const int array[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void randomly_fill_array(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % MAX_ELEM_VALUE;
  }
}

void zero_fill_array(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}


void insertion_sort(int array[], const size_t size) {
  
  size_t j = 0;

  for (size_t i = 1; i < size; i++) {
    j = i;
    while (j > 0 && array[j] < array[j-1]) {
      swap(array, j-1, j, size);
      j -= 1;
    }
  }
}


int partition(int array[], int i, int j, int p, const size_t size) {

  swap(array, i, p, size);
  p = i;
  i = i+1;

  while (i <= j) {
    if (array[i] > array[p]) {
      swap(array, i, j, size);
      j -= 1;
    } else {
      i += 1;
    }
  }
  swap(array, p, j, size);
  return j;
}

void quicksort(int array[], int i, int r, const size_t size) {
  int p;
  if (i < r) {
    p = partition(array, i, r, i, size);

    quicksort(array, i, p-1, size);
    quicksort(array, p+1, r, size);
  }
}
    

void heapsort(int array[], const size_t _size) {
  size_t size = _size;

  build_heap(array, size);

  for (size_t i = size - 1; i >= 1; i--) {
    swap(array, 0, i, size);
    size -= 1;
    heapify(array, 0, size);
  }
}


void countingsort(const int A[], int B[], int bound, const size_t size) {
  int C[bound];
  zero_fill_array(C, bound);

  for (size_t i = 0; i < size; i++) {
    C[A[i]-1] += 1;
  } // C[j] is now the number of j in A[].

  int tmp;

  for (size_t j = 1; j < bound; j++) {
    tmp = C[j-1] + C[j];
    C[j] = tmp;
  } // C[j] is now the number of A's values <= j.

  for (int i = size - 1; i >= 0; i--) {
    B[C[A[i]-1]-1] = A[i];
    C[A[i]-1] -= 1;
  }
}



int main() {

  int test[10];
  int size_test = LENGTH(test);

  // INSERTION SORT

  randomly_fill_array(test, size_test);
  print_array(test, size_test);

  insertion_sort(test, size_test);
  print_array(test, size_test);

  // QUICK SORT
  LINE;

  randomly_fill_array(test, size_test);
  print_array(test, size_test);

  quicksort(test, 0, size_test - 1, size_test);
  print_array(test, size_test);

  // HEAP SORT
  LINE;

  randomly_fill_array(test, size_test);
  print_array(test, size_test);

  heapsort(test, size_test);
  print_array(test, size_test);


  // COUNTING SORT
  // assumes uniform distribution and bounded domain for the array values
  LINE;
  
  randomly_fill_array(test, size_test);
  print_array(test, size_test);
  int B[size_test]; // The sorted vector will be stored here.

  countingsort(test, B, MAX_ELEM_VALUE, size_test);
  print_array(B, size_test);


}
