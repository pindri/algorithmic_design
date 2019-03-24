#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"


void MatrixChainAux(int P[], MATRIX M, MATRIX_int S, unsigned int i, unsigned int j) {

  M.matrix[i][j] = 1.0/0.0; // Setting element to inf
  float q = 0.0;
  for (unsigned int k = i; k <= j-1; k++){

    q = M.matrix[i][k] + M.matrix[k+1][j] + P[i]*P[k+1]*P[j+1]; // Compensates the different

    if (q < M.matrix[i][j]){ // treatments for the indices
      M.matrix[i][j] = q;
      S.matrix[i][j-1] = k+1; // To compensated for the redefined indices 
    }

  }

}




MATRIX_int MatrixChain(int P[], const unsigned int n){

  MATRIX M = allocate_MATRIX(n,n);
  MATRIX_int S = allocate_MATRIX_int(n-1,n-1); // Indexes should be (1..n-1, 2..n)

  for (unsigned int i = 0; i < n; ++i){ // Set diagonal elements to zero
    M.matrix[i][i] = 0;
  }

  unsigned int j = 0;
  for (unsigned int l = 1; l < n; l++){ // l is the chain lenght
    for (unsigned int i = 0; i < n - l; i++){
      j = i + l;
      MatrixChainAux(P, M, S, i, j);
    }
  }

  for (unsigned int i = 0; i < n-1; i++){
    printf("\n");
    for(unsigned int j = 0; j < n-1; j++){
      printf("%d\t", S.matrix[i][j]);
    }
  }

  deallocate_MATRIX(M);
  
  return S;
}


// Print_Parens(S,1,n) for the optimal solution.
void Print_Parens(MATRIX_int S, unsigned int i, unsigned int j){ 
  if (i == j){
    printf("A%d", i);
  } else {
    printf("(");
    Print_Parens(S, i, S.matrix[i-1][j-2]);
    Print_Parens(S, S.matrix[i-1][j-2] + 1, j);
    printf(")");
  }
}

