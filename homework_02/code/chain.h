#ifndef __CHAIN__
#define __CHAIN__

#include "matrix_struct.h"

void MatrixChainAux(int P[], MATRIX M, MATRIX_int S, unsigned int i, unsigned int j);

MATRIX_int MatrixChain(int P[], const unsigned int n);

void Print_Parens(MATRIX_int S, unsigned int i, unsigned int j);

#endif // __CHAIN__
