#include <stdio.h>
#include <time.h>

#include "matrix.h"
#include "chain.h"
#include "matrix_struct.h"


double get_execution_time(const struct timespec b_time, const struct timespec e_time) {
  return (e_time.tv_sec-b_time.tv_sec) + (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int main() {

  // Number of matrices.
  const unsigned int n = 6;

  // Holds the dimensions of the n matrices.
  int P[] = {30,35,15,5,10,20,25};

  // Computes the S matrix for the given n matrices.
  INT_MATRIX S = MatrixChain(P,6);

  printf("\n\nPrinting optimal solution:\t");
  PrintParens(S, 1, n);
  printf("\n");

  // Allocates and fills the array of matrices with random values.
  FLOAT_MATRIX L[n];
  for (size_t i = 0; i < n; i++){
    L[i] = AllocateFLOAT_MATRIX(P[i],P[i+1]);
    RandomlyFillFLOAT_MATRIX(L[i]);
  }


  /**** NAIVE MULT AND TIMING ****/

  struct timespec b_time, e_time;
  int n_ops_naive = 0;

  clock_gettime(CLOCK_REALTIME, &b_time);
    FLOAT_MATRIX naive_result = NaiveMult(L, P, n, &n_ops_naive);
  clock_gettime(CLOCK_REALTIME, &e_time);

  printf("\nNAIVE SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_naive);


  /**** CHAIN MULT AND TIMING ****/

  int n_ops_chain = 0;

  clock_gettime(CLOCK_REALTIME, &b_time);
    FLOAT_MATRIX chain_result = ChainMult(S, 1, 6 , L, &n_ops_chain);
  clock_gettime(CLOCK_REALTIME, &e_time);

  printf("\nCHAIN SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_chain);


  /**** COMPARISON ****/

  printf("\nOperations opt/naive: %f\n", (float)n_ops_chain/(float)n_ops_naive);
  printf("\nIs the result the same? %d\n", SameMATRIX(naive_result, chain_result));


  // Freeing resources.
  DellocateFLOAT_MATRIX(chain_result);
  DellocateFLOAT_MATRIX(naive_result);

  for (unsigned int i = 0; i < n ; i++){
    DellocateFLOAT_MATRIX(L[i]);
  }

  DellocateINT_MATRIX(S);


}
