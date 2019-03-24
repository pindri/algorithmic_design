#include <stdio.h>
#include <time.h>

#include "chain.h"
#include "matrix.h"
#include "matrix_struct.h"



double get_execution_time(const struct timespec b_time, const struct timespec e_time) {
  return (e_time.tv_sec-b_time.tv_sec) + (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int main(){

  // Number of matrices.
  const unsigned int n = 6;

  // Holds the dimensions of the n matrices.
  int P[] = {30,35,15,5,10,20,25};

  // Computes the S matrix for the given n matrices.
  MATRIX_int S = MatrixChain(P,6);

  printf("\n\nPrinting optimal solution:\t");
  Print_Parens(S, 1, 6);
  printf("\n");


  MATRIX L[n];
  // Allocates and fills the array of matrices with random values.
  for (size_t i = 0; i < n; i++){
    L[i] = allocate_MATRIX(P[i],P[i+1]);
    randomly_fill_MATRIX(L[i]);
  }



  MATRIX R[n-1];
  // Allocates the array of partial results for the sequencial product.
  for (size_t i = 0; i < n-1; i++){
    R[i] = allocate_MATRIX(P[0],P[i+2]);
  }


  struct timespec b_time, e_time;

  int n_ops_naive = 0;

  clock_gettime(CLOCK_REALTIME, &b_time);
    // In order chain multiplication.
    naive_MATRIX_mult(L[0], L[1], R[0]);
    n_ops_naive += L[0].row * L[0].col * L[1].col;
    for (size_t i = 0; i < n-2; i++) {
      naive_MATRIX_mult(R[i], L[i+2], R[i+1]);
      n_ops_naive += R[i].row * R[i].col * L[i+2].col;
    }
  clock_gettime(CLOCK_REALTIME, &e_time);

  printf("\nNAIVE SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_naive);


  // Writing a general procedure to compute the optimal solution is non-trivial.
  // It requires a non easibily predictible sequence of allocations to hold
  // the partial results. Since the computation itself is not the focus of the
  // assignment, I decided to compute by hand the 5 products for the chain
  // I considered, considering the optimal solution ((A1(A2A3))((A4A5)A6)).


  MATRIX O[n-1];
  // Allocates the array of partial results for the sequencial product.
  O[0] = allocate_MATRIX(P[1],P[3]);
  O[1] = allocate_MATRIX(P[0],P[3]);
  O[2] = allocate_MATRIX(P[3],P[5]);
  O[3] = allocate_MATRIX(P[3],P[6]);
  O[4] = allocate_MATRIX(P[0],P[6]);


  int n_ops_opt = 0;
  // Computes the optimal chain multiplication.
  clock_gettime(CLOCK_REALTIME, &b_time);
    naive_MATRIX_mult(L[1],L[2],O[0]);
    n_ops_opt += L[1].row * L[1].col * L[2].col;
    naive_MATRIX_mult(L[0],O[0],O[1]);
    n_ops_opt += L[0].row * L[0].col * O[0].col;
    naive_MATRIX_mult(L[3],L[4],O[2]);
    n_ops_opt += L[3].row * L[3].col * L[4].col;
    naive_MATRIX_mult(O[2],L[5],O[3]);
    n_ops_opt += O[2].row * O[2].col * L[5].col;
    naive_MATRIX_mult(O[1],O[3],O[4]);
    n_ops_opt += O[1].row * O[1].col * O[3].col;
  clock_gettime(CLOCK_REALTIME, &e_time);

  printf("\nOPTIMAL SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_opt);


  printf("\nOperations opt/naive: %f\n", (float)n_ops_opt/(float)n_ops_naive);
  printf("\nIs the result the same? %d\n", same_MATRIX(O[4], R[4]));


  // Freeing resources.
  
  for (unsigned int i = 0; i < n ; i++){
    deallocate_MATRIX(L[i]);
  }

  for (unsigned int i = 0; i < n-1 ; i++){
    deallocate_MATRIX(R[i]);
    deallocate_MATRIX(O[i]);
  }

  deallocate_MATRIX_int(S);



}
