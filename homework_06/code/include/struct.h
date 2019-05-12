#ifndef STRUCT_H
#define STRUCT_H

typedef struct IntMatrix { // Note, square matrix.
  int** matrix;
  size_t size;
} IntMatrix;


typedef struct Vertex {
  int d; // Distance.
  struct Vertex* pred; // Preceding Vertex.
  size_t index; // From 0 to size-q of the graph, labels Vertices, necessary
             // because swapping things might move the vertex.
} Vertex;


typedef struct Graph {
  IntMatrix weights;
  Vertex* v; // Array containing the Vertices.
  size_t size;
} Graph;


typedef struct QArray {
  Vertex* v; // Array of Vertices.
  size_t* extracted; // To keep note of already extracted minimums.
  size_t size;
} QArray;


typedef struct HeapElem {
  size_t index;  // Index to the element contained.
  int* d; // Key, heap ordering done on this.
} HeapElem;


typedef struct QHeap {
  HeapElem* h; // Will only contain the indices of a vector of Vertex.
  size_t size;
  size_t max_capacity;
} QHeap;




#endif // STRUCT_H
