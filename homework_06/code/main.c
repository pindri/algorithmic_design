#include <stdio.h>
#include <stdlib.h>

#include "struct.h" // IntMatrix, Vertex, Graph and QArray structs.
#include "matrix.h" // Methods for IntMatrix.
#include "graph.h"  // Methods for Graph and Vertex.
#include "array.h"  // Methods for QArray.



int main() {

unsigned int n = 10;

Graph g;

IntMatrix w = AllocateIntMatrix(n);
RandomlyFillSparseIntMatrix(w, 3);

for(int i = 0; i < n; i++) {
  for(int j =0; j < n; j++) {
    printf("%d\t", w.matrix[i][j]);
  }
  printf("\n");
}

InitializeGraph(&g, w);

//DijkstraArray(&g, 0);
//
//for (int i = 0; i < n; i++) {
  //ShortestPath(&g, i);
//}
//
//ResetGraph(&g); // Graphs can be resetted, to be processed by another algorithm.



//DijkstraHeap(&g, 0);



DeallocateGraph(&g);


return 0;
}
