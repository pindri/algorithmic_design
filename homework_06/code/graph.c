#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "matrix.h"


void InitializeGraph(Graph* g, IntMatrix weight_matrix) {
  size_t size = weight_matrix.size;
  Vertex* v = (Vertex*)malloc(sizeof(Vertex) * size);
  g -> v = v;
  g -> size = size;
  g -> weights = weight_matrix;

  for(size_t i = 0; i < size; i++) {
    (g -> v[i]).d = ~(1<<31); // MANAGE INF!
    (g -> v[i]).index = i; // Every vertex is labelled.
    (g -> v[i]).pred = NULL;
  }
}

void ResetGraph(Graph* g) {
  size_t size;
  size = g -> size;
  for(size_t i = 0; i < size; i++) {
    (g -> v[i]).d = ~(1<<31); // MANAGE INF!
    (g -> v[i]).pred = NULL;
  }
}

void DeallocateGraph(Graph* g) {

  free(g -> v);
  DeallocateIntMatrix(g -> weights);

}

void InitSSSP(Graph* g) {
  for(size_t i = 0; i < g -> size; i++) {
    (g -> v[i]).d = ~(1<<31); // MANAGE INF!
    (g -> v[i]).pred = NULL;
  }
}


int* Adj(Graph* g, Vertex* u) {
  size_t index = u -> index;
  int* adj = (int*)malloc(sizeof(int) * g -> size);
  for (size_t i = 0; i < g -> size; i++) {
    if ( (g -> weights).matrix[index][i] != 0 ) { // If non-null weight.
      adj[i] = 1; // Index i is part of the adjecent Vertices.
    } else {
      adj[i] = 0; // Non connected Vertices will have -1.
    }
  }
  return adj;
}

// Should update distance editing queue and the graph vertex.
void UpdateDistance(Vertex* vert_q, Vertex* v, int new_w) {
  v -> d = new_w;
  vert_q -> d = new_w;
}



void ShortestPath(Graph* g, size_t to) {
  Vertex v = g -> v[to]; // Destination vertex.
  int total_distance = v.d;
  while (v.pred != NULL) {
    printf("%d <- ", v.index);
    v = *v.pred;
  }
  printf("%d;\ntotal distance: %d\n\n", v.index, total_distance);
}
