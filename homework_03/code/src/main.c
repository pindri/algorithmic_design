#include <stdio.h>
#include <stdlib.h>
#include "cptimer.h"
#include "heapify.h"

#define MAX_ELEM_VALUE 1000000
#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))

int main() {

#ifdef BENCHMARK

  for (int dim = 1000; dim < MAX_ELEM_VALUE; dim = dim + 1000) {
    int test[dim];

    int size_test = LENGTH(test);

    randomly_fill_array(test, size_test);

    double start_build = seconds();
      build_heap(test, size_test);
    double end_build = seconds();

    double start_heapify = seconds();
      remove_minimum(test, &size_test);
    double end_heapify = seconds();

    printf("%d\t%f\t%d\t%f\t%d\n", dim, end_build-start_build, is_heap(test, size_test), end_heapify - start_heapify, is_heap(test, size_test)); 
  }

#else

  int heap[6] = {1,2,4,7,6,5};
  int size = LENGTH(heap);

  printf("root is %d\n", get_root(heap));
  printf("size is %d\n", size);
  printf("is heap? %d\n", is_heap(heap, size));

  printf("\n----- Testing remove_minimum -----\n");
  remove_minimum(heap, &size);

  printf("root is %d\n", get_root(heap));
  printf("size is %d\n", size);




  printf("\n----- Testing build_heap -----\n");

  int array[6] = {2,7,4,1,6,5};
  int size_a = LENGTH(array);

  build_heap(array, size_a);

  printf("root is %d\n", get_root(array));
  printf("left_child of root is %d\n", left_child(array, 0, size)); 
  printf("right_child of root is %d\n", right_child(array, 0, size));

  printf("is heap? %d\n", is_heap(heap, size));




  printf("\n----- Execution time on a big heap -----\n");

  srand(3); // Setting seed for rand().

  int big[MAX_ELEM_VALUE];
  int size_big = LENGTH(big);

  randomly_fill_array(big, size_big);

  double start = seconds();
    build_heap(big, size_big);
  printf("elapsed time = %fs\n", seconds()-start); 

  printf("is heap? %d\n", is_heap(big, size_big));


#endif // BENCHMARK

  return 0;
}
