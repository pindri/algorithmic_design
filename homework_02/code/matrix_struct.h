#ifndef __MATRIXSTRUCT__
#define __MATRIXSTRUCT__

typedef struct MATRIX {
  float** matrix;
  size_t row;
  size_t col;
} MATRIX;

typedef struct MATRIX_int {
  int** matrix;
  const size_t row;
  const size_t col;
} MATRIX_int;

#endif
