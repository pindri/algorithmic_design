#ifndef HEAPIFY_H
#define HEAPIFY_H

int get_root(const int heap[]);

int right_child(const int heap[], const int i, const size_t size);

int left_child(const int heap[], const int i, const size_t size);

int get_right_index(const int heap[], const int i, const size_t size);

int get_left_index(const int heap[], const int i, const size_t size);

void swap(int heap[], const int i, const int m, const size_t size);

void heapify(int heap[], const int i, const size_t size);

void remove_minimum(int heap[], int* size);

void build_heap(int array[], const size_t size);

int is_heap(const int array[], const size_t size) ;


#endif // HEAPIFY_H
