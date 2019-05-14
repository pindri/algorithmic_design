#ifndef HEAPIFY_H
#define HEAPIFY_H

int GetRightIndex(const int heap[], const int i, const size_t size);
int GetLeftIndex(const int heap[], const int i, const size_t size);
void Swap(int heap[], const int i, const int m, const size_t size);
void Heapify(int heap[], const int i, const size_t size);
void BuildHeap(int array[], const size_t size);



#endif // HEAPIFY_H
