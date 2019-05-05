#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heapify.h"
#include "utilities.h"
#include "asvector.h"
#include "asvector_methods.h"
#include "macro.h"


void InsertionSort(int array[], const size_t size) {
  
  size_t j = 0;

  for (size_t i = 1; i < size; i++) {
    j = i;
    while (j > 0 && array[j] < array[j-1]) {
      Swap(array, j-1, j, size);
      j -= 1;
    }
  }
}



int Partition(int array[], int i, int j, int p, const size_t size) {

  Swap(array, i, p, size);
  p = i;
  i = i+1;

  while (i <= j) {
    if (array[i] > array[p]) {
      Swap(array, i, j, size);
      j -= 1;
    } else {
      i += 1;
    }
  }
  Swap(array, p, j, size);
  return j;
}



void QuickSort(int array[], int i, int r, const size_t size) {
  int p;
  if (i < r) {
    p = Partition(array, i, r, i, size);

    QuickSort(array, i, p-1, size);
    QuickSort(array, p+1, r, size);
  }
}
  
  

void HeapSort(int array[], const size_t _size) {
  size_t size = _size;

  BuildHeap(array, size);

  for (size_t i = size - 1; i >= 1; i--) {
    Swap(array, 0, i, size);
    size -= 1;
    Heapify(array, 0, size);
  }
}



void CountingSort(const int A[], int B[], int bound, const size_t size) {
  int C[bound];
  ZeroFillArray(C, bound);

  for (size_t i = 0; i < size; i++) {
    C[A[i]-1] += 1;
  } // C[j] is now the number of j in A[].

  for (size_t j = 1; j < bound; j++) {
    C[j] += C[j-1];
  } // C[j] is now the number of A's values <= j.

  for (int i = size - 1; i >= 0; i--) {
    B[C[A[i]-1]-1] = A[i];
    C[A[i]-1] -= 1;
  }
}



void RadixSort_aux (int A[], const size_t size, const int divider) {

  int B[size];
  int C[10] = {0}; // 10 possible digits.
  //ZeroFillArray(B, size);

  for (size_t i = 0; i < size; i++) {
    C[ (A[i]/divider) % 10 ] += 1;
  } // C[j] is now the number of j in A[].

  for (size_t j = 1; j < 10; j++) {
    C[j] += C[j-1];
  } // C[j] is now the number of A's values <= j.

  for (int i = size - 1; i >= 0; i--) {
    B[C[ (A[i]/divider) % 10 ]-1] = A[i];
    C[ (A[i]/divider) % 10 ] -= 1;
  }

  for (size_t i = 0; i < size; i++) {
    A[i] = B[i];
  }
}
  


void RadixSort (int array[], const size_t size, const int digits) {

  int max = MaxElem(array, size);
  int divider = 1;

  for (int exponent = 1; exponent <= digits; exponent++) {
    RadixSort_aux(array, size, divider);
    divider *= 10;
  }
}


void BucketSort_aux(float array[], const size_t size) {
  // basically insertion sort with doubles.
  
  size_t j = 0;

  for (size_t i = 1; i < size; i++) {
    j = i;
    while (j > 0 && array[j] < array[j-1]) {
      SwapFloat(array, j-1, j, size);
      j -= 1;
    }
  }
}



void BucketSort (float array[], const size_t size) {
  AsVector B[size];
  for (size_t i = 0; i < size; i++) {
    InitAsVector(&B[i], 2);
  }

  for (size_t i = 0; i < size; i++) {
    //printf(" the index is: %d\n", (int)(array[i]*size));
    PushBackAsVector( &( B[ (int)(array[i]*size) ] ), array[i] );
  } // B contains the buckets.

  int i = 0;

  for (size_t j = 0; j < size; j++) {
    BucketSort_aux(B[j].data, B[j].size);
    for (size_t s = 0; s < B[j].size; s++) {
      array[i] = B[j].data[s];
      i += 1;
    }
    DeleteAsVector(&B[j]);
  }
 
}



int SelectPivot(int l, int r) {

  if (l == r) return l;

 // srand(time(NULL)); // requires time.h
  int mid[3] = { l + rand()%(r - l), l + rand()%(r - l), l + rand()%(r - l) };
  int max = MaxElem(mid, 3);
  int min = MinElem(mid, 3);

  return mid[0] + mid[1] + mid[2] - max - min;
}



int Select(int array[], int i, int l, int r, const size_t size) {

  int j = SelectPivot(l, r);
//  printf("mid = %d\n", j);

  int k = Partition(array, l, r, j, size);

  if (i == k) {
    return array[k];
  } else { 
    if (i < k) {
      return Select(array, i, l, k-1, size);
    } else {
      return Select(array, i, k+1, r, size);
    }
  }

  return 0;
}



