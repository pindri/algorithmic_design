#ifndef SORT_H_
#define SORT_H_

#include "asvector.h"

void InsertionSort(int array[], const size_t size);

int Partition(int array[], int i, int j, int p, const size_t size);

void QuickSort(int array[], int i, int r, const size_t size);
  
void HeapSort(int array[], const size_t _size);

void CountingSort(const int A[], int B[], int bound, const size_t size);

void RadixSort_aux (int A[], const size_t size, const int divider);
  
void RadixSort (int array[], const size_t size, const int digits);

void BucketSort_aux(float array[], const size_t size);

void BucketSort (float array[], const size_t size);

int SelectPivot(int l, int r);

int Select(int array[], int i, int l, int r, const size_t size);


#endif // SORT_H_

