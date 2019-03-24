#ifndef __MATRIX__
#define __MATRIX__

#include <stdlib.h>
#include "matrix_struct.h"

int naive_MATRIX_mult(MATRIX A, MATRIX B, MATRIX C);

float **allocate_matrix(const size_t rows, const size_t cols);
int **allocate_matrix_int(const size_t rows, const size_t cols);

MATRIX allocate_MATRIX(const size_t rows, const size_t cols);
MATRIX_int allocate_MATRIX_int(const size_t rows, const size_t cols);

void deallocate_MATRIX(MATRIX A);
void deallocate_MATRIX_int(MATRIX_int A);

void randomly_fill_MATRIX(MATRIX A);

int same_MATRIX(MATRIX A, MATRIX B);

#endif // __MATRIX__
