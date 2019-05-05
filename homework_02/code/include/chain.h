#ifndef __CHAIN__
#define __CHAIN__

void MatrixChainAux(int P[], FLOAT_MATRIX M, INT_MATRIX S, unsigned int i, unsigned int j);

INT_MATRIX MatrixChain(int P[], const unsigned int n);

void PrintParens(INT_MATRIX S, unsigned int i, unsigned int j);

FLOAT_MATRIX ChainMult(INT_MATRIX S, int i, int j, FLOAT_MATRIX L[], int* n_ops);

#endif //__CHAIN__
