#include <stdio.h>

#include "matrix.h"



void MatrixChainAux(int P[], INT_MATRIX M, INT_MATRIX S, unsigned int i, unsigned int j) {

  M.matrix[i][j] = 10000000; // Setting element to inf
  int q = 0;
  for (unsigned int k = i; k <= j-1; k++){

    q = M.matrix[i][k] + M.matrix[k+1][j] + P[i]*P[k+1]*P[j+1]; // Compensates the different

    if (q < M.matrix[i][j]){ // treatments for the indices
      M.matrix[i][j] = q;
      S.matrix[i][j-1] = k+1; // To compensated for the redefined indices
    }

  }

}



INT_MATRIX MatrixChain(int P[], const unsigned int n){

  INT_MATRIX M = AllocateINT_MATRIX(n,n);
  INT_MATRIX S = AllocateINT_MATRIX(n-1,n-1); // Indexes should be (1..n-1, 2..n)

  for (unsigned int i = 0; i < n; ++i){ // Set diagonal elements to zero
    M.matrix[i][i] = 0;
  }

  // Initialise matrix S, to avoid complains from valgrind.
  for (unsigned int i = 0; i < n-1; i++){
    for(unsigned int j = 0; j < n-1; j++){
      S.matrix[i][j] = 0;
    }
  }

  unsigned int j = 0;
  for (unsigned int l = 1; l < n; l++){ // l is the chain lenght
    for (unsigned int i = 0; i < n - l; i++){
      j = i + l;
      MatrixChainAux(P, M, S, i, j);
    }
  }

#ifndef BENCHMARK
  printf("\nMatrix S:\n");
  for (unsigned int i = 0; i < n-1; i++){
    printf("\n");
    for(unsigned int j = 0; j < n-1; j++){
      printf("%d\t", S.matrix[i][j]);
    }
  }
#endif

  DellocateINT_MATRIX(M);

  return S;
}



// PrintParens(S,1,n) for the optimal solution.
void PrintParens(INT_MATRIX S, unsigned int i, unsigned int j){
  if (i == j){
    printf("A%d", i);
  } else {
    printf("(");
    PrintParens(S, i, S.matrix[i-1][j-2]);
    PrintParens(S, S.matrix[i-1][j-2] + 1, j);
    printf(")");
  }
}



// ChainMult(S,1,n) for the optimal solution.
INT_MATRIX ChainMult(INT_MATRIX S, int i, int j, INT_MATRIX L[], int* n_ops) {

  if (i == j) {
    INT_MATRIX result_ = AllocateINT_MATRIX(L[i-1].row, L[i-1].col);
    CopyINT_MATRIX(L[i-1], result_);
    return result_;  // Return the i-th matrix.
  } else {
    int k = S.matrix[i-1][j-2];

    INT_MATRIX X = ChainMult(S, i, k, L, n_ops);
    INT_MATRIX Y = ChainMult(S, k + 1, j, L, n_ops);
    INT_MATRIX result = AllocateINT_MATRIX(X.row, Y.col);

    NaiveINT_MATRIXMult(X,Y,result);
    *n_ops += X.row * X.col * Y.col; // Update number of operations.

    DellocateINT_MATRIX(X);
    DellocateINT_MATRIX(Y);

    return result;
  }
}
