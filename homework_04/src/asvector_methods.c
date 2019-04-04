#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heapify.h"
#include "utilities.h"
#include "asvector.h"

int InitAsVector(AsVector* v, size_t capacity) {

  v -> data = malloc( capacity * sizeof *(v->data) );
  if (!v -> data) return -1;

  v->size = 0;
  v->max_capacity = capacity;
  return 0;
}

void ResizeAsVector(AsVector* v, size_t new_size) {
  //printf("resizing\n");
  float* tmp; // so that if realloc returns null, it's safer
  tmp = realloc(v -> data, new_size * sizeof *(v->data) );
  //v -> data = (float*)realloc(v -> data, new_size);
  // if not tmp could not realloc, else
  v -> data = tmp;
  v -> max_capacity = new_size;

}

void PushBackAsVector(AsVector* v, float value) {
  // realloc if vector is full.
  if (v -> size == v-> max_capacity) {
    ResizeAsVector(v, 2*(v->max_capacity));
  }

  //printf("some info. max_capacity = %ld, size = %ld\n", v->max_capacity, v->size);
  v -> data[v -> size] = value;
  v -> size += 1;
}

void PrintAsVector(const AsVector v) {
  if (v.size == 0) {
    printf("Empty vector\n");
  } else {
    for (int i = 0; i < v.size; i++) {
      printf("%f\t", v.data[i]);
    }
    LINE;
  }
}

void DeleteAsVector(AsVector* v) {
  free(v->data);
  v -> size = 0;
  v -> max_capacity = 0;
}


