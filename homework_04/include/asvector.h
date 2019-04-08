#ifndef ASVECTOR_H_
#define ASVECTOR_H_

/*
 * struct that emulates some of the features of a dynamic vector.
 * 'data' holds the values of the vector, 'size' is the number of 
 * elements the vector contains, while 'max_capacity' is the maximum
 * number of elements the vector can hold: once 'size'=='capacity' 
 * the vector capacity gets doubled using 'realloc'.
 */
typedef struct AsVector {
  float* data;
  size_t max_capacity;
  size_t size;
} AsVector;

#endif // ASVECTOR_H_
