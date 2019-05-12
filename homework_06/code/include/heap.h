#ifndef HEAP_H
#define HEAP_H

void Swap(QHeap* q, const size_t i, const size_t m);
size_t GetParentIndex(const size_t i);
size_t GetRightIndex(const size_t i);
size_t GetLeftIndex(const size_t i);
void Heapify(QHeap* q, const size_t i);
void BuildQHeap(Graph* g, QHeap* q, int distance[]);
HeapElem ExtractMinQHeap(QHeap* q);
void DijkstraHeap(Graph* g, size_t s);


#endif //HEAP_H
