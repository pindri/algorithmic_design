#include <stdio.h>
#include <stdlib.h>


#define MAX_HEAP_ORDERING >=
#define MIN_HEAP_ORDERING <=
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))


/**
 * Swaps array[i] and array [m].
 */
void Swap(int array[], const int i, const int m, const size_t size) {
  if (i <= size && m <= size) {
    int tmp1 = array[i];
    int tmp2 = array[m];
    array[i] = tmp2;
    array[m] = tmp1;
  }
}

int GetRoot(const int heap[]) {
  return heap[0];
}



int RightChild(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return heap[2*(i+1)];
  } else {
    return 1./0.;
  }
}



int LeftChild(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return heap[2*(i+1)-1];
  } else {
    return 1./0.;
  }
}



int GetRightIndex(const int heap[], const int i, const size_t size) {
  if ( (2*(i+1)+1) <= size ) {
    return 2*(i+1);
  } else {
    return -1;
  }
}



int GetLeftIndex(const int heap[], const int i, const size_t size) {
  if ( 2*(i+1) <= size ) {
    return 2*(i+1)-1;
  } else {
    return -1;
  }
}



void Heapify(int heap[], const int i, const size_t size) {
  int m = i;

  int j[2] = {GetLeftIndex(heap, i, size), GetRightIndex(heap, i, size)};

  for (int k = 0; k <= 1; ++k) {
    if (j[k] <= size && heap[j[k]] MAX_HEAP_ORDERING heap[m]) {
      m = j[k];
    }
  }

  if ( i != m ) {
    Swap(heap, i, m, size);
    Heapify(heap, m, size);
  }

}



void RemoveMinimum(int heap[], int* size) {
  heap[0] = heap[*size - 1];
  *size = *size -1;
  Heapify(heap, 0, *size);
}



void BuildHeap(int array[], const size_t size) {
  for (int i = (size/2 - 1); i >= 0; i--) { // Bottom up on each subtree.
    Heapify(array, i, size);
  }
}



int IsHeap(const int array[], const size_t size) {
  for (size_t i = 0; i <= (size-2)/2; i++) { // From root untill last internal node.
    if (LeftChild(array, i, size) < array[i]) return 0; // If left child is greater.
    if ( GetRightIndex(array, i, size) != -1 && array[2*(i+1)] < array[i] ) return 0;
  }
  return 1;
}



void DijkstraHeap(Graph* g, size_t s) { // 's' is the starting vertex.
  //InitSSSP(g); // The graph should already be initialized.
  ( (g -> v)[s] ).d = 0;

  // Build an array queue, made of all the distances.
  QArray q = BuildQArray(g);

  Vertex u; // Will contain the minimum Vertex for the minimum.
  int steps = 0;

  while(steps < g -> size) { // When start == size, only one element left.
    u = ExtractMinQArray(&q); // u.index cointains the index of the minimum in g!

    int* adj = Adj(g, &u); // Contains weights too
    int i = 0;
    for (size_t i = 0; i < g -> size; i++) {
      // If non-null weight, then neighbour.
      if ( (g -> weights).matrix[u.index][i] != 0 ) {
        int w = (g -> weights).matrix[u.index][i];
        Relax(&q, &u, g, w, i);
      }
    }
    printf("");
    free(adj);
    steps += 1;
  }

  FreeQArray(&q);

}
