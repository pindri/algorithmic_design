#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heapify.h"




#define MAX_ELEM_VALUE 20
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))
#define LINE printf("\n")

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

void zero_fill_array(int array[], const size_t size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}


void InsertionSort(int array[], const size_t size) {
  
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

void QuickSort(int array[], int i, int r, const size_t size) {
  int p;
  if (i < r) {
    p = partition(array, i, r, i, size);

    QuickSort(array, i, p-1, size);
    QuickSort(array, p+1, r, size);
  }
}
    

void HeapSort(int array[], const size_t _size) {
  size_t size = _size;

  build_heap(array, size);

  for (size_t i = size - 1; i >= 1; i--) {
    swap(array, 0, i, size);
    size -= 1;
    heapify(array, 0, size);
  }
}


void CountingSort(const int A[], int B[], int bound, const size_t size) {
  int C[bound];
  zero_fill_array(C, bound);

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

int n_digit(int x, int n) {
  while (n--) {
    x /= 10;
  }
  return (x % 10);
}

int max_elem(int array[], const size_t size) {
  int max = array[0];
  for(size_t i = 0; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}

void RadixSort_aux (int A[], const size_t size, const int divider) {

  int B[size];
  int C[10] = {0}; // 10 possible digits.
  //zero_fill_array(B, size);

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

  int max = max_elem(array, size);
  int divider = 1;

  for (int exponent = 1; exponent <= digits; exponent++) {
    RadixSort_aux(array, size, divider);
    divider *= 10;
  }
}







typedef struct AsVector {
  float* data;
  size_t max_capacity;
  size_t size;
} AsVector;

int InitAsVector(AsVector* v, size_t capacity) {

  v -> data = malloc( capacity * sizeof *(v->data) );
  if (!v -> data) return -1;

  v->size = 0;
  v->max_capacity = capacity;
  return 0;
}

void ResizeAsVector(AsVector* v, size_t new_size) {
  //printf("resizing\n");
  float* tmp; // so that if realloc returns null, it's safer
  tmp = realloc(v -> data, new_size * sizeof *(v->data) );
  //v -> data = (float*)realloc(v -> data, new_size);
  // if not tmp could not realloc, else
  v -> data = tmp;
  v -> max_capacity = new_size;

}

void PushBackAsVector(AsVector* v, float value) {
  // realloc if vector is full.
  if (v -> size == v-> max_capacity) {
    ResizeAsVector(v, 2*(v->max_capacity));
  }

  //printf("some info. max_capacity = %ld, size = %ld\n", v->max_capacity, v->size);
  v -> data[v -> size] = value;
  v -> size += 1;
}

void PrintAsVector(const AsVector v) {
  if (v.size == 0) {
    printf("Empty vector\n");
  } else {
    for (int i = 0; i < v.size; i++) {
      printf("%f\t", v.data[i]);
    }
    LINE;
  }
}

void DeleteAsVector(AsVector* v) {
  free(v->data);
  v -> size = 0;
  v -> max_capacity = 0;
}


void SwapFloat(float array[], const int i, const int m, const size_t size) {
  if (i <= size && m <= size) {
    float tmp1 = array[i];
    float tmp2 = array[m];
    array[i] = tmp2;
    array[m] = tmp1;
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

  //AsVector provoh;
  //InitAsVector(&provoh, 2);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PushBackAsVector(&provoh, 2.34);
  //PrintAsVector(provoh);
  //DeleteAsVector(&provoh);
//
  //PrintAsVector(provoh);

  BucketSort(bucket, size_bucket);
  PrintFloatArray(bucket, size_bucket);

}
