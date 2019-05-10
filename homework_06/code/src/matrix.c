#include <stdlib.h>

#include "struct.h"

#define MAX_ELEM_VALUE 8

IntMatrix AllocateIntMatrix(const size_t size) {
  int** A = (int** )malloc(sizeof(int* ) * size);
  for (size_t i = 0; i < size; i++) {
    A[i] = (int* )malloc(sizeof(int) * size);
  }
  IntMatrix MAT = {A, size};
  return MAT;
}
void DeallocateIntMatrix(IntMatrix A) {
  for (size_t i = 0; i < A.size; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}
void SetZeroDiag(IntMatrix A) {
 for (size_t i=0; i< A.size; i++) {
     A.matrix[i][i] = 0;
 }
}
void RandomlyFillIntMatrix(IntMatrix A)
{
 int elem = 0;
 for (size_t i=0; i< A.size; i++) {
   for (size_t j=0; j< A.size; j++) {
     elem = rand()%(MAX_ELEM_VALUE);
     A.matrix[i][j] = elem;
   }
 }
 //SetZeroDiag(A);
}

void RandomlyFillSparseIntMatrix(IntMatrix A, int s) {
 for (size_t i=0; i< A.size; i++) {
   for (size_t j=0; j< A.size; j++) {
     if (rand() % s == 0) { // Encodes sparsity.
       A.matrix[i][j] = rand()%(MAX_ELEM_VALUE);
     } else {
       A.matrix[i][j] = 0;
     }
   }
 }
 //SetZeroDiag(A);
}
