#ifndef UTILITES_H_
#define UTILITIES_H_


void PrintArray(const int array[], const size_t size);

void PrintFloatArray(const float array[], const size_t size);

void RandomlyFillArray(int array[], const size_t size);

void RandomNDigitsFillArray(int array[], const size_t size, const int n);

void UniformFillArray(float array[], const size_t size);

void ZeroFillArray(int array[], const size_t size);

int IntPow(int base, int exp);

void Swap(int array[], const int i, const int m, const size_t size);

void SwapFloat(float array[], const int i, const int m, const size_t size);

int MaxElem(int array[], const size_t size);

int MinElem(int array[], const size_t size);


#endif // UTILITES_H_
