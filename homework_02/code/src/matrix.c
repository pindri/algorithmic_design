#include <stdlib.h>
#include <stdio.h>

#include "matrix_struct.h"

#define MAX_ELEM_VALUE 5


INT_MATRIX AllocateINT_MATRIX(const size_t rows, const size_t cols) {
  int** A = (int** )malloc(sizeof(int* ) * rows);
  for (size_t i = 0; i < rows; i++) {
    A[i] = (int* )malloc(sizeof(int) * cols);
  }
  INT_MATRIX MAT = {A, rows, cols};
  return MAT;
}



void DellocateINT_MATRIX(INT_MATRIX A) {
  for (size_t i = 0; i < A.row; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}



void RandomlyFillINT_MATRIX(INT_MATRIX A)
{
   int elem = 0;
   for (size_t i=0; i< A.row; i++) {
     for (size_t j=0; j< A.col; j++) {
       elem = rand()%(2*MAX_ELEM_VALUE)-MAX_ELEM_VALUE;
       A.matrix[i][j] = elem;
     }
   }
}



int NaiveINT_MATRIXMult(INT_MATRIX A, INT_MATRIX B, INT_MATRIX C){

  if (A.col != B.row) {
    return -1;
  }

  for (size_t i=0; i<A.row; i++) {
    for (size_t j=0; j<B.col; j++) {
      C.matrix[i][j] = 0.0;

      for (size_t k=0; k<A.col; k++) {
        C.matrix[i][j] += (A.matrix[i][k]*B.matrix[k][j]);
      }
    }
  }
  return 0;
}



int SameMATRIX(INT_MATRIX A, INT_MATRIX B) {

  if ((A.row != B.row) || (A.col != B.col)) {
    return 0;
  }

  for (size_t i=0; i<A.row; i++) {
    for (size_t j=0; j<A.col; j++) {
      if (abs(A.matrix[i][j] - B.matrix[i][j]) != 0) {
        printf("%d",abs(A.matrix[i][j] - B.matrix[i][j]));
        return 0;
      }
    }
  }

  return 1;
}



INT_MATRIX NaiveMult(INT_MATRIX L[], int P[], unsigned int n, int* n_ops) {

  // Allocates the array of partial results for the sequencial product.
  INT_MATRIX R[n-1];
  for (size_t i = 0; i < n-1; i++){
    R[i] = AllocateINT_MATRIX(P[0],P[i+2]);
  }

  // In order chain multiplication.
  NaiveINT_MATRIXMult(L[0], L[1], R[0]);
  *n_ops += L[0].row * L[0].col * L[1].col;
  for (size_t i = 0; i < n-2; i++) {
    NaiveINT_MATRIXMult(R[i], L[i+2], R[i+1]);
    *n_ops += R[i].row * R[i].col * L[i+2].col;
  }

  // Free resources.
  for (size_t i = 0; i < n-2 ; i++){
    DellocateINT_MATRIX(R[i]);
  }

  return R[n-2];
}



void CopyINT_MATRIX(INT_MATRIX A, INT_MATRIX B) {
  for (size_t i = 0; i < A.row; i++) {
    for (size_t j = 0; j < A.col; j++) {
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
}
