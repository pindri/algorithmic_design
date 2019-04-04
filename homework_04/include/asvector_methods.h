#ifndef ASVECTOR_METHODS_H_
#define ASVECTOR_METHODS_H_

int InitAsVector(AsVector* v, size_t capacity);

void ResizeAsVector(AsVector* v, size_t new_size);

void PushBackAsVector(AsVector* v, float value);
void PrintAsVector(const AsVector v);

void DeleteAsVector(AsVector* v);


#endif // ASVECTOR_METHODS_H_
