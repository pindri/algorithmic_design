#ifndef UTILITES_H_
#define UTILITIES_H_

#define MAX_ELEM_VALUE 20
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))
#define LINE printf("\n")


void PrintArray(const int array[], const size_t size);

void PrintFloatArray(const float array[], const size_t size);

void RandomlyFillArray(int array[], const size_t size);

void RandomNDigitsFillArray(int array[], const size_t size, const int n);

void UniformFillArray(float array[], const size_t size);

void ZeroFillArray(int array[], const size_t size);

int IntPow(int base, int exp);

void Swap(int heap[], const int i, const int m, const size_t size);

void SwapFloat(float array[], const int i, const int m, const size_t size);


#endif // UTILITES_H_
