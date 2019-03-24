#include <stdlib.h>
#include <stdio.h>
#include "matrix_struct.h"

#define MAX_ELEM_VALUE 5


int naive_MATRIX_mult(MATRIX A, MATRIX B, MATRIX C){

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



float **allocate_matrix(const size_t rows, const size_t cols) {

  float **A=(float **)malloc(sizeof(float *)*rows);
  for (size_t i=0; i<rows; i++) {
    A[i]=(float *)malloc(sizeof(float)*cols);
  }

  return A;

}



int **allocate_matrix_int(const size_t rows, const size_t cols) {

  int **A=(int **)malloc(sizeof(int *)*rows);
  for (size_t i=0; i<rows; i++) {
    A[i]=(int *)malloc(sizeof(int)*cols);
  }

  return A;

}



MATRIX allocate_MATRIX(const size_t rows, const size_t cols) {

  MATRIX A = {allocate_matrix(rows, cols), rows, cols};  
  return A;
}


MATRIX_int allocate_MATRIX_int(const size_t rows, const size_t cols) {

  MATRIX_int A = {allocate_matrix_int(rows, cols), rows, cols};
  return A;
}



void deallocate_MATRIX(MATRIX A) {

  for (size_t i=0; i<A.row; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}



void deallocate_MATRIX_int(MATRIX_int A) {
  for (size_t i=0; i<A.row; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}



void randomly_fill_MATRIX(MATRIX A) 
{ 
   for (size_t i=0; i< A.row; i++) { 
     for (size_t j=0; j< A.col; j++) { 
       A.matrix[i][j]=rand()%(2*MAX_ELEM_VALUE)-MAX_ELEM_VALUE; 
     } 
   } 
} 


int same_MATRIX(MATRIX A, MATRIX B) {
  
  if ((A.row != B.row) || (A.col != B.col)) {
    return 0;
  }
  
  for (size_t i=0; i<A.row; i++) {
    for (size_t j=0; j<A.col; j++) {
      if (abs(A.matrix[i][j] - B.matrix[i][j]) > 10) {
        printf("[%ld][%ld]",i,j);
        return 0;
      }
    }
  }

  return 1;
}
