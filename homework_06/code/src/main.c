#include <stdio.h>
#include <stdlib.h>

#include "struct.h"   // IntMatrix, Vertex, Graph and QArray structs.
#include "matrix.h"   // Methods for IntMatrix.
#include "graph.h"    // Methods for Graph and Vertex.
#include "array.h"    // Methods for QArray.
#include "heap.h"     // Methods for QHeap.
#include "cptimer.h"  // Timer.



int main() {

#ifdef BENCHMARK

  double start, end;

  for (size_t n = 100; n < 5000; n = n + 100) {
    Graph g;
    IntMatrix w = AllocateIntMatrix(n);
    RandomlyFillSparseIntMatrix(w, 3);
    InitializeGraph(&g, w);


    start = Seconds();
      DijkstraArray(&g, 0);
    end = Seconds();
    printf("%ld\t%f\t", n, end - start);


    ResetGraph(&g);

    start = Seconds();
      DijkstraHeap(&g, 0);
    end = Seconds();
    printf("%f\n", end - start);

    DeallocateGraph(&g);

  }


#else

  size_t n = 10;

  // Graphs must be initialised with a square matrix representing the graph.
  Graph g;
  IntMatrix w = AllocateIntMatrix(n);
  RandomlyFillSparseIntMatrix(w, 3);

  printf("Matrix representation of the directed graph\n");
  for(size_t i = 0; i < n; i++) {
    for(size_t j =0; j < n; j++) {
      printf("%d\t", w.matrix[i][j]);
    }
    printf("\n");
  }

  InitializeGraph(&g, w);


  DijkstraArray(&g, 0);

  printf("\n...Array approach...\n");
  for (size_t i = 0; i < n; i++) {
    ShortestPath(&g, i);
  }


  ResetGraph(&g); // Graphs can be resetted, to be processed by another algorithm.


  DijkstraHeap(&g, 0);

  printf("\n...Heap approach...\n");
  for (size_t i = 0; i < n; i++) {
    ShortestPath(&g, i);
  }


  DeallocateGraph(&g);

#endif

  return 0;
}
