#ifndef ASVECTOR_H_
#define ASVECTOR_H_

typedef struct AsVector {
  float* data;
  size_t max_capacity;
  size_t size;
} AsVector;

#endif // ASVECTOR_H_
