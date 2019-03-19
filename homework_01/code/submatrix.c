#include <stdlib.h>

#include "matrix.h"

void sum_matrix_blocks(float **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       float ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       float ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n)
{
  // for all the rows in the blocks
  for (size_t i=0; i<n; i++) {

    // for all the cols in the blocks
    for (size_t j=0; j<n; j++) {
      C[C_f_row+i][C_f_col+j] = A[A_f_row+i][A_f_col+j] +
                                B[B_f_row+i][B_f_col+j];
    }
  }
}

void sub_matrix_blocks(float **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       float ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       float ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n)
{
  // for all the rows in the blocks
  for (size_t i=0; i<n; i++) {

    // for all the cols in the blocks
    for (size_t j=0; j<n; j++) {
      C[C_f_row+i][C_f_col+j] = A[A_f_row+i][A_f_col+j] -
                                B[B_f_row+i][B_f_col+j];
    }
  }
}

void naive_aux(float **C, const size_t C_f_row, const size_t C_f_col,
               float **A, const size_t A_f_row, const size_t A_f_col,
               float **B, const size_t B_f_row, const size_t B_f_col,
               const size_t n)
{
   for (size_t i=0; i<n; i++) {
     for (size_t j=0; j<n; j++) {
       C[C_f_row+i][C_f_col+j] = 0.0;
       for (size_t k=0; k<n; k++) {
         C[C_f_row+i][C_f_col+j] += (A[A_f_row+i][A_f_col+k]*
                                     B[B_f_row+k][B_f_col+j]);
       }
     }

   }
}

