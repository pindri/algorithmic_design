#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEM_VALUE 5

typedef struct IntMatrix { // Note, square matrix.
  int** matrix;
  size_t size;
} IntMatrix;
IntMatrix AllocateIntMatrix(const size_t size) {
  int** A = (int** )malloc(sizeof(int* ) * size);
  for (size_t i = 0; i < size; i++) {
    A[i] = (int* )malloc(sizeof(int) * size);
  }
  IntMatrix MAT = {A, size};
  return MAT;
}
void DeallocateIntMatrix(IntMatrix A) {
  for (size_t i = 0; i < A.size; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}
void RandomlyFillIntMatrix(IntMatrix A)
{
   int elem = 0;
   for (size_t i=0; i< A.size; i++) {
     for (size_t j=0; j< A.size; j++) {
       elem = rand()%(2*MAX_ELEM_VALUE)-MAX_ELEM_VALUE;
       A.matrix[i][j] = elem;
     }
   }
}







typedef struct Vertex {
  int d; // Distance.
  struct Vertex* pred; // Preceding Vertex.
  int index; // From 0 to size-q of the graph, labels Vertices, probably useless.
} Vertex;

typedef struct Graph {
  IntMatrix weights;
  Vertex* v; // Array containing the Vertices.
  size_t size;
} Graph;

void InitializeGraph(Graph* g, size_t size, IntMatrix weight_matrix) {
  Vertex* v = (Vertex*)malloc(sizeof(Vertex) * size);
  g -> v = v;
  g -> size = size;
  g -> weights = weight_matrix;

  for(size_t i = 0; i < size; i++) {
    (g -> v[i]).d = 10000; // MANAGE INF!
    (g -> v[i]).index = i; // Every vertex is labelled.
    (g -> v[i]).pred = NULL;
  }
}

void DeallocateGraph(Graph g) {

  free(g.v);
  DeallocateIntMatrix(g.weights);

}

void InitSSSP(Graph* g) {
  for(size_t i = 0; i < g -> size; i++) {
    (g -> v[i]).d = 10000; // MANAGE INF!
    (g -> v[i]).pred = NULL;
  }
}

void Dijkstra(Graph g, size_t s) { // 's' is the starting vertex.
  InitSSSP(&g);
  (g.v[s]).d = 0;

  //// Build an array queue, made of all the distances.
  //queue <- BuildQueueArray(g);
  //int u; // Will contain the index for the minimum.
  //while(IsEmpty(q) != 1) {
    //u = ExtractMinArray(queue);
//
    //// Some way to find Adiacent(g, u);
    //for (v, w) in adiacents {
      //Relax(queue, u, v, w);
    //}
  //}


}




int main() {

unsigned int n = 10;

Graph g;

IntMatrix w = AllocateIntMatrix(n);
RandomlyFillIntMatrix(w);

InitializeGraph(&g, n, w);
printf("graphsize = %ld", g.size);


InitSSSP(&g);

Dijkstra(g, 2);

DeallocateGraph(g);









return 0;
}
