#ifndef MATRIX_H
#define MATRIX_H

IntMatrix AllocateIntMatrix(const size_t size);
void DeallocateIntMatrix(IntMatrix A);
void SetZeroDiag(IntMatrix A);
void RandomlyFillIntMatrix(IntMatrix A);
void RandomlyFillSparseIntMatrix(IntMatrix A, int s);

#endif // MATRIX_H
