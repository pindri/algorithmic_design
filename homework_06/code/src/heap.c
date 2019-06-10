#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"
#include "struct.h"
#include "matrix.h"

#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=



void Swap(QHeap* q, const size_t i, const size_t m) {
  const size_t size = q -> size;
  if (i <= size - 1 && m <= size - 1) {
    HeapElem tmp1 = q -> h[i];
    HeapElem tmp2 = q -> h[m];

    q -> h[i] = tmp2;
    q -> h[m] = tmp1;
  }
}


size_t GetParentIndex(const size_t i) {
  return (i+1)/2 - 1;
}

size_t GetRightIndex(const size_t i) {
  return 2*(i+1);
}

size_t GetLeftIndex(const size_t i) {
  return 2*(i+1)-1;
}


void Heapify(QHeap* q, const size_t i) {
  size_t size = q -> size;

  size_t l = GetLeftIndex(i);
  size_t r = GetRightIndex(i);
  size_t largest;

  if ( l <= size-1 && *((q -> h[l]).d) MIN_HEAP_ORDERING *((q -> h[i]).d) ) {
    largest = l;
  } else {
    largest = i;
  }

  if ( r <= size-1 && *((q -> h[r]).d) MIN_HEAP_ORDERING *((q -> h[largest]).d) ) {
    largest = r;
  }

  if ( largest != i ) {
    Swap(q, i, largest);
    Heapify(q, largest);
  }

}



void BuildQHeap(Graph* g, QHeap* q, int distance[]) {
  size_t size = g -> size;
  for (size_t i = 0; i < size; i++) {
    (q -> h[i]).index = i;
    (q -> h[i]).d = &distance[i];
  }
  for (size_t i = 0; i <= (size/2 - 1); i++) { // Bottom up on each subtree.
    Heapify(q, (size/2 - 1) - i);
  }
}



HeapElem ExtractMinQHeap(QHeap* q) {
  if (q -> size == 0) {
    printf("Error, heap underflow");
  }
  HeapElem minimum = q -> h[0];
  q -> h[0] = q -> h[q -> size -1];
  q -> size -= 1;
  if (q -> size > 0) Heapify(q, 0);
  return minimum;
}




void DijkstraHeap(Graph* g, size_t s) { // 's' is the starting vertex.

  //InitSSSP(g); // The graph should already be initialized.
  ( (g -> v)[s] ).d = 0;
  size_t size = g -> size;

  // Initialise distances, providing a fixed reference.
  int distance[size];
  for (size_t i = 0; i < size; i++ ) {
    distance[i] = INT_MAX;
  }

  // Create a QHeap of correct size, fill it, and set the s element at distance zero.
  HeapElem h[size];
  distance[s] = 0;
  QHeap q = {h, size, size};
  BuildQHeap(g, &q, distance);

  HeapElem u; // Will contain minimum.

  while (q.size > 0) {
    u = ExtractMinQHeap(&q);
    // Takes care of unreachable nodes.
    if (*(u.d) != INT_MAX) {
      // Now run through the neighbours.
      for (size_t i = 0; i < g -> size; i++) {
        // If weight is non null, then there is an edge.
        if ( (g -> weights).matrix[u.index][i] != 0 ) {

          int w = (g -> weights).matrix[u.index][i];
          int new_distance = *(u.d) + w;
          if ( (new_distance) < ((g -> v[i]).d) ) {

            // Updating distances vector.
            distance[i] = new_distance;

            // Updating distance and predecessor.
            size_t pred_index = u.index;
            (g -> v[i]).pred = &(g -> v[pred_index]);
            (g -> v[i]).d = new_distance;


            // Finding updated element of queue.
            size_t j = 0;
            while(j < q.size) {
              if ((q.h[j]).index == i) {break;}
              j++;
            }
            // Restoring heap property.
            while ( (j != 0) && ( *((q.h[j]).d) < *((q.h[GetParentIndex(j)]).d) )) {
              Swap(&q, j, GetParentIndex(j));
              j = GetParentIndex(j);
            }
          }
        }
      }
    }
  }
}

