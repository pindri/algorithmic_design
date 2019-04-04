#ifndef SORT_H_
#define SORT_H_



void InsertionSort(int array[], const size_t size);


int partition(int array[], int i, int j, int p, const size_t size);



void QuickSort(int array[], int i, int r, const size_t size);
  
  

void HeapSort(int array[], const size_t _size);


void CountingSort(const int A[], int B[], int bound, const size_t size);


int MaxElem(int array[], const size_t size);

void RadixSort_aux (int A[], const size_t size, const int divider);
  
void RadixSort (int array[], const size_t size, const int digits);







typedef struct AsVector {
  float* data;
  size_t max_capacity;
  size_t size;
} AsVector;

int InitAsVector(AsVector* v, size_t capacity);

void ResizeAsVector(AsVector* v, size_t new_size);

void PushBackAsVector(AsVector* v, float value);

void PrintAsVector(const AsVector v);

void DeleteAsVector(AsVector* v);

void SwapFloat(float array[], const int i, const int m, const size_t size);

void BucketSort_aux(float array[], const size_t size);

void BucketSort (float array[], const size_t size);


#endif // SORT_H_

