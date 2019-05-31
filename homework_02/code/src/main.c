#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "matrix.h"
#include "chain.h"
#include "matrix_struct.h"


// Timing function.
double get_execution_time(const struct timespec b_time, const struct timespec e_time) {
  return (e_time.tv_sec-b_time.tv_sec) + (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int main(int argc, char* argv[]) {

  if (argc != 2) {
    printf("The code must be run with the length of the chain as only argument!\n");
    return 1;
  }

  // Number of matrices.
  const unsigned int n = atoi(argv[1]);

  if (n > 40) {
    printf("WARNING, the chain length excedes the default maximum!\n");
  }

#ifndef BENCHMARK
  printf("\nNumber of matrices in the chain, n = %d\n", n);
#endif

  // Open file containing the sequence of dimensions.
  FILE *f;
  f = fopen("input.txt", "r");

  // Holds the dimensions of the n matrices.
  int P[n+1];

  // Reads chain sizes from file.
  if (f == NULL) {
    printf("Error Reading File\n");
    return 0;
  }

  for (size_t i = 0; i < n+1; i++) {
    fscanf(f, "%d", &P[i]);
  }

  // Computes the S matrix for the given n matrices.
  INT_MATRIX S = MatrixChain(P,n);

#ifndef BENCHMARK
  printf("\n\nPrinting optimal solution:\t");
  PrintParens(S, 1, n);
  printf("\n");
#endif

  // Allocates and fills the array of matrices with random values.
  INT_MATRIX L[n];
  for (size_t i = 0; i < n; i++){
    L[i] = AllocateINT_MATRIX(P[i],P[i+1]);
    RandomlyFillINT_MATRIX(L[i]);
  }



  /**** NAIVE MULT AND TIMING ****/

  struct timespec b_time, e_time;
  int n_ops_naive = 0;

  clock_gettime(CLOCK_REALTIME, &b_time);
    INT_MATRIX naive_result = NaiveMult(L, P, n, &n_ops_naive);
  clock_gettime(CLOCK_REALTIME, &e_time);

#ifndef BENCHMARK
  printf("\nNAIVE SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_naive);
#endif



  /**** CHAIN MULT AND TIMING ****/

  int n_ops_chain = 0;

  clock_gettime(CLOCK_REALTIME, &b_time);
    INT_MATRIX chain_result = ChainMult(S, 1, n , L, &n_ops_chain);
  clock_gettime(CLOCK_REALTIME, &e_time);

#ifndef BENCHMARK
  printf("\nCHAIN SOLUTION\nExecution time: %lfs\n", get_execution_time(b_time, e_time));
  printf("Number of operations: %d\n", n_ops_chain);
#endif



  /**** COMPARISON ****/

#ifndef BENCHMARK
  printf("\nOperations opt/naive: %f\n", (float)n_ops_chain/(float)n_ops_naive);
  printf("\nIs the result the same? %d\n\n", SameMATRIX(naive_result, chain_result));
#else
  printf("%d\t%f\t%d\n", n, (float)n_ops_chain/(float)n_ops_naive, SameMATRIX(naive_result, chain_result));
#endif



  // Freeing resources.
  DellocateINT_MATRIX(chain_result);
  DellocateINT_MATRIX(naive_result);

  for (unsigned int i = 0; i < n ; i++){
    DellocateINT_MATRIX(L[i]);
  }

  DellocateINT_MATRIX(S);

  fclose(f);

}
