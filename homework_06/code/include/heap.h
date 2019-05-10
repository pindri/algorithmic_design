#ifndef HEAP_H
#define HEAP_H

void Swap(QHeap* q, const size_t i, const size_t m);
int GetRightIndex(const size_t i, const size_t size);
int GetLeftIndex(const size_t i, const size_t size);
void Heapify(QHeap* q, const size_t i);
HeapElem ExtractMinQHeap(QHeap* q);
void InsertHeap(QHeap* q, size_t i, int p);
void RelaxUpdateHeap(QHeap* q, HeapElem* u, Graph* g, int w, size_t i);
void DijkstraHeap(Graph* g, size_t s);

#endif //HEAP_H
