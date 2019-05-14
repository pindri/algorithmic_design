#ifndef HEAP_H
#define HEAP_H

int GetRoot(const int heap[]);
int RightChild(const int heap[], const int i, const size_t size);
int LeftChild(const int heap[], const int i, const size_t size);
int GetRightIndex(const int heap[], const int i, const size_t size);
int GetLeftIndex(const int heap[], const int i, const size_t size);
void Swap(int heap[], const int i, const int m, const size_t size);
void Heapify(int heap[], const int i, const size_t size);
void RemoveMinimum(int heap[], int* size);
void BuildHeap(int array[], const size_t size);
int IsMinHeap(const int array[], const size_t size) ;
int IsMaxHeap(const int array[], const size_t size) ;
void RandomlyFillArray(int array[], const size_t size);



#endif // HEAP_H
