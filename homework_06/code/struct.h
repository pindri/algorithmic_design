#ifndef STRUCT_H
#define STRUCT_H

typedef struct IntMatrix { // Note, square matrix.
  int** matrix;
  size_t size;
} IntMatrix;


typedef struct Vertex {
  int d; // Distance.
  struct Vertex* pred; // Preceding Vertex.
  int index; // From 0 to size-q of the graph, labels Vertices, necessary
             // because swapping things might move the vertex.
} Vertex;


typedef struct Graph {
  IntMatrix weights;
  Vertex* v; // Array containing the Vertices.
  size_t size;
} Graph;


typedef struct QArray {
  Vertex* v; // Array of Vertices.
  int* extracted; // To keep note of already extracted minimums.
  size_t size;
} QArray;


#endif // STRUCT_H
