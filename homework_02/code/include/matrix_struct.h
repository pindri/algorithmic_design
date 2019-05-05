#ifndef __MATRIXSTRUCT__
#define __MATRIXSTRUCT__

typedef struct FLOAT_MATRIX {
  float** matrix;
  size_t row;
  size_t col;
} FLOAT_MATRIX;

typedef struct INT_MATRIX {
  int** matrix;
  const size_t row;
  const size_t col;
} INT_MATRIX;

#endif // __MATRICSTRUCT__
