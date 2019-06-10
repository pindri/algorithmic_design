#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "struct.h"
#include "matrix.h"


void InitializeGraph(Graph* g, IntMatrix weight_matrix) {
  size_t size = weight_matrix.size;
  Vertex* v = (Vertex*)malloc(sizeof(Vertex) * size);
  g -> v = v;
  g -> size = size;
  g -> weights = weight_matrix;

  for(size_t i = 0; i < size; i++) {
    (g -> v[i]).d = INT_MAX; // MANAGE INF!
    (g -> v[i]).index = i; // Every vertex is labelled.
    (g -> v[i]).pred = NULL;
  }
}


void ResetGraph(Graph* g) {
  size_t size;
  size = g -> size;
  for(size_t i = 0; i < size; i++) {
    (g -> v[i]).d = INT_MAX; // MANAGE INF!
    (g -> v[i]).pred = NULL;
  }
}


void DeallocateGraph(Graph* g) {

  free(g -> v);
  DeallocateIntMatrix(g -> weights);

}


void InitSSSP(Graph* g) {
  for(size_t i = 0; i < g -> size; i++) {
    (g -> v[i]).d = INT_MAX; // MANAGE INF!
    (g -> v[i]).pred = NULL;
  }
}





void ShortestPath(Graph* g, size_t to) {
  Vertex v = g -> v[to]; // Destination vertex.
  int total_distance = v.d;
  if (total_distance == INT_MAX || total_distance == -INT_MAX) {
    printf("Going to: %ld. No path available.\n", to);
    return;
  }
  printf("Going to: %ld. Total distance: %d\t\t", to, total_distance);
  while (v.pred != NULL) {
    printf("%ld <- ", v.index);
    v = *v.pred;
  }
  printf("%ld\n", v.index);
}
