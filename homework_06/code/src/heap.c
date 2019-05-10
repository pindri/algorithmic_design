#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "struct.h"


#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=



void Swap(QHeap* q, const size_t i, const size_t m) {
  size_t size = q -> size;
  if (i <= size && m <= size) {
    HeapElem tmp1 = (q -> h)[i];
    HeapElem tmp2 = (q -> h)[m];
    (q -> h)[i] = tmp2;
    (q -> h)[m] = tmp1;
  }
}


size_t GetRightIndex(const size_t i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return 2*(i+1);
  } else {
    return -1;
  }
}



size_t GetLeftIndex(const size_t i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return 2*(i+1)-1;
  } else {
    return -1;
  }
}



void Heapify(QHeap* q, const size_t i) {
  size_t size = q -> size;
  size_t m = i;

  size_t j[2] = {GetLeftIndex(i, size), GetRightIndex(i, size)};

  for (int k = 0; k <= 1; ++k) {
    if (j[k] <= size && ((q -> h)[j[k]]).key MAX_HEAP_ORDERING ((q -> h)[m]).key) {
      m = j[k];
    }
  }

  if ( i != m ) {
    Swap(q, i, m);
    Heapify(q, m);
  }

}



HeapElem ExtractMinQHeap(QHeap* q) {
  HeapElem minimum = q -> h[0];
  q -> h[0] = q -> h[ (q -> size) -1];
  q -> size -= 1;
  Heapify(q, 0);
  return minimum;
}



void BuildHeap(QHeap* q) {
  size_t size = q -> size;
  for (size_t i = 0; i >= (size/2 - 1); i++) { // Bottom up on each subtree.
    Heapify(q, (size/2 - 1) - i);
  }
}



void InsertHeap(QHeap* q, size_t i, int p) {
  // If heapsize==capacity, stop

  q -> size += 1; // Added element, increase size.
  HeapElem new_elem = {i, p};
  q -> h[(q -> size) - 1] = new_elem; // Insert new_elem at the end of the heap.

  // If the heap property has been violated, heapify.
  BuildHeap(q);
}


void RelaxUpdateHeap(QHeap* q, HeapElem* u, Graph* g, int w, size_t i) {
  int new_distance = u -> key + w;
  if ( (new_distance) < ((g -> v[i]).d) ) {
    InsertHeap(q, i, new_distance); // Insert el i of graph, with distance key + w
    size_t pred_index = u -> index;
    (g -> v[i]).pred = &(g -> v[pred_index]);
    (g -> v[i]).d = new_distance; // Updated distance.
  }
}


void DijkstraHeap(Graph* g, size_t s) { // 's' is the starting vertex.
  //InitSSSP(g); // The graph should already be initialized.
  ( (g -> v)[s] ).d = 0;
  size_t size = g -> size;

  // Build an empty heap queue.
  HeapElem h[size];
  QHeap q = {h, 0, size};

  HeapElem u; // Will contain minimum.
  // Insert index i with priority p on qheap
  InsertHeap(&q, s, 0);

  while (q.size != 0) {
    u = ExtractMinQHeap(&q);
    for (size_t i = 0; i < g -> size; i++) {
      // If non-null weight, then neighbour.
      if ( (g -> weights).matrix[u.index][i] != 0 ) {
        int w = (g -> weights).matrix[u.index][i];
        RelaxUpdateHeap(&q, &u, g, w, i);
      }
    }
  }
}


