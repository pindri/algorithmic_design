#ifndef __CHAIN__
#define __CHAIN__

void MatrixChainAux(int P[], INT_MATRIX M, INT_MATRIX S, unsigned int i, unsigned int j);

INT_MATRIX MatrixChain(int P[], const unsigned int n);

void PrintParens(INT_MATRIX S, unsigned int i, unsigned int j);

INT_MATRIX ChainMult(INT_MATRIX S, int i, int j, INT_MATRIX L[], int* n_ops);

#endif //__CHAIN__
