#ifndef __MATRIX__
#define __MATRIX__

#include "matrix_struct.h"

INT_MATRIX AllocateINT_MATRIX(const size_t rows, const size_t cols);

void DellocateINT_MATRIX(INT_MATRIX A);

void RandomlyFillINT_MATRIX(INT_MATRIX A);

int NaiveINT_MATRIXMult(INT_MATRIX A, INT_MATRIX B, INT_MATRIX C);

int SameMATRIX(INT_MATRIX A, INT_MATRIX B);

INT_MATRIX NaiveMult(INT_MATRIX L[], int P[], int n, int* n_ops);

void CopyINT_MATRIX(INT_MATRIX A, INT_MATRIX B);


#endif //__MATRIX__
