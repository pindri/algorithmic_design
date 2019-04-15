#include <stdio.h>
#include <stdlib.h> 
#include "macro.h" 
#include "asvector.h"  


/*
 * Initialises the AsVector struct
 */
void InitAsVector(AsVector* v, size_t capacity) {

  v -> data = malloc( capacity * sizeof *(v->data) );
  if (!v -> data) {
    printf("ERROR, could not allocate. %f", 1./0.);
  } else {
    v->size = 0;
    v->max_capacity = capacity;
  }
}


/*
 * Reallocates a AsVector struct, with size new_size
 */
void ResizeAsVector(AsVector* v, size_t new_size) {
  float* tmp; // so that if realloc returns null, it's safer
  tmp = realloc(v -> data, new_size * sizeof *(v->data) );
  // if not tmp could not realloc, else
  if (!tmp) {
    printf("ERROR, could not reallocate. %f", 1./0.);
  } else {
    v -> data = tmp;
    v -> max_capacity = new_size;
  }

}



void PushBackAsVector(AsVector* v, float value) {
  // Realloc if vector is full.
  if (v -> size == v-> max_capacity) {
    ResizeAsVector(v, 2*(v->max_capacity));
  }

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


