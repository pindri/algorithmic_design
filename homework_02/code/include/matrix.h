#ifndef __MATRIX__
#define __MATRIX__

#include "matrix_struct.h"

FLOAT_MATRIX AllocateFLOAT_MATRIX(const size_t rows, const size_t cols);

INT_MATRIX AllocateINT_MATRIX(const size_t rows, const size_t cols);

void DellocateFLOAT_MATRIX(FLOAT_MATRIX A);

void DellocateINT_MATRIX(INT_MATRIX A);

void RandomlyFillFLOAT_MATRIX(FLOAT_MATRIX A);

int NaiveFLOAT_MATRIXMult(FLOAT_MATRIX A, FLOAT_MATRIX B, FLOAT_MATRIX C);

int SameMATRIX(FLOAT_MATRIX A, FLOAT_MATRIX B);

FLOAT_MATRIX NaiveMult(FLOAT_MATRIX L[], int P[], int n, int* n_ops);

void CopyFLOAT_MATRIX(FLOAT_MATRIX A, FLOAT_MATRIX B);


#endif //__MATRIX__
