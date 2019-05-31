#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "struct.h"
#include "graph.h"


void FreeQArray(QArray* q) {
  free(q -> v);
  free(q -> extracted);
}



// Builds a queue of Vertices.
QArray BuildQArray(Graph* g) {

  Vertex* v = (Vertex*)malloc(sizeof(Vertex) * g -> size);
  size_t* extracted = (size_t*)malloc(sizeof(size_t) * g -> size);

  for(size_t i = 0; i < g -> size; i++) {
    v[i] = g -> v[i];
    extracted[i] = 0;
  }

  QArray q = {v, extracted, g -> size};

  return q;
}



Vertex ExtractMinQArray(QArray* q) {
  int min = INT_MAX; // The default minimum is inf.
  int pos = 0;
  for(size_t i = 0; i < q -> size; i++) {
    if ( ((q -> v[i]).d <= min)  && (q -> extracted[i] == 0) )  {
      min = (q -> v[i]).d; // Take the distance as a measure.
      pos = i; // Holds the position of the minimum, to extract it.
    }
  }

  q -> extracted[pos] = 1; // 1 encodes a Vertex to skip

  return q -> v[pos];
}



void UpdateDistance(Vertex* vert_q, Vertex* v, int new_w) {
  v -> d = new_w;
  vert_q -> d = new_w;
}


void Relax(QArray* q, Vertex* u, Graph* g, int w, size_t i) {
  if ( (u -> d + w) < ((g -> v[i]).d) ) {
    UpdateDistance(&(q -> v[i]), &(g -> v[i]), u -> d + w);
    int pred_index = u -> index;
    (g -> v[i]).pred = &(g -> v[pred_index]);
  }
}



void DijkstraArray(Graph* g, size_t s) { // 's' is the starting vertex.
  //InitSSSP(g); // The graph should already be initialized.
  ( (g -> v)[s] ).d = 0;

  // Build an array queue, made of all the distances.
  QArray q = BuildQArray(g);

  Vertex u; // Will contain the minimum Vertex for the minimum.
  size_t steps = 0; // Must be size_t since it cycles through a QArray.

  while(steps < g -> size) { // When start == size, only one element left.
    u = ExtractMinQArray(&q); // u.index cointains the index of the minimum in g!

    for (size_t i = 0; i < g -> size; i++) {
      // If non-null weight, then neighbour.
      if ( (g -> weights).matrix[u.index][i] != 0 ) {
        int w = (g -> weights).matrix[u.index][i];
        Relax(&q, &u, g, w, i);
      }
    }
    steps += 1;
  }

  FreeQArray(&q);

}

