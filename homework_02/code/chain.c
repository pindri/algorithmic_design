#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void MatrixChainAux(int* P, float** M, int** S, int i, int j){
  M[i][j] = 1.0/0.0; // Setting element to inf
  float q = 0.0;
  for (int k = i; k <= j-1; k++){
    //printf("\tk = %d\n",k);
    q = M[i][k] + M[k+1][j] + P[i]*P[k+1]*P[j+1]; // Compensates the different
    if (q < M[i][j]){                             // treatments for the indices
      M[i][j] = q;
      S[i][j-1] = k+1; // To compensated for the redefined indices 
    }
  }
}

int** MatrixChain(int P[], int n){
  float** M = allocate_matrix(n,n);
  int** S = allocate_matrix_int(n-1,n-1); // Indexes should be (1..n-1, 2..n)

  for (int i = 0; i < n; ++i){ // Set diagonal elements to zero
    M[i][i] = 0;
  }

  int j = 0;
  for (int l = 1; l < n; l++){ // l is the chain lenght
    for (int i = 0; i < n - l; i++){
      j = i + l;
      //printf("i = %d, j = %d\n", i, j);
      MatrixChainAux(P, M, S, i, j);
      //Test(M,i);
    }
  }

  for (int i = 0; i < n-1; i++){
    printf("\n");
    for(int j = 0; j < n-1; j++){
      printf("%d\t", S[i][j]);
    }
  }


  //printf("\n\n");
//
  //for (int i = 0; i < n; i++){
    //printf("\n");
    //for(int j = 0; j < n; j++){
      //printf("%f\t", M[i][j]);
    //}
  //}

  deallocate_matrix(M,n);
  //deallocate_matrix_int(S,n-1);
  return S;
}


void Print_Parens(int** S, int i, int j){ // Print_Parens(S,1,n) for the optimal
  if (i == j){
    printf("A%d", i);
  } else {
    printf("(");
    Print_Parens(S, i, S[i-1][j-2]);
    Print_Parens(S, S[i-1][j-2] + 1, j);
    printf(")");
  }
}





int main(){

  int P[7] = {30,35,15,5,10,20,25};


  printf("ciaone, %d\n", P[2]);

  int** S = allocate_matrix_int(5,5); // Indexes should be (1..n-1, 2..n)

  S = MatrixChain(P,6);

  printf("\n\nPrinting optimal solution:\t");
  Print_Parens(S, 1, 6);
  printf("\n");











}
