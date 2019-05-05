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

    RandomlyFillArray(test, size_test);

    double start_build = Seconds();
      BuildHeap(test, size_test);
    double end_build = Seconds();

    double start_Heapify = Seconds();
      RemoveMinimum(test, &size_test);
    double end_Heapify = Seconds();

    printf("%d\t%f\t%d\t%f\t%d\n", dim, end_build-start_build, IsHeap(test, size_test), end_Heapify - start_Heapify, IsHeap(test, size_test));
  }

#else

  int heap[6] = {1,2,4,7,6,5};
  int size = LENGTH(heap);

  printf("root is %d\n", GetRoot(heap));
  printf("size is %d\n", size);
  printf("is heap? %d\n", IsHeap(heap, size));

  printf("\n----- Testing RemoveMinimum -----\n");
  RemoveMinimum(heap, &size);

  printf("root is %d\n", GetRoot(heap));
  printf("size is %d\n", size);




  printf("\n----- Testing BuildHeap -----\n");

  int array[6] = {2,7,4,1,6,5};
  int size_a = LENGTH(array);

  BuildHeap(array, size_a);

  printf("root is %d\n", GetRoot(array));
  printf("LeftChild of root is %d\n", LeftChild(array, 0, size));
  printf("RightChild of root is %d\n", RightChild(array, 0, size));

  printf("is heap? %d\n", IsHeap(heap, size));




  printf("\n----- Execution time on a big heap -----\n");

  srand(3); // Setting seed for rand().

  int big[MAX_ELEM_VALUE];
  int size_big = LENGTH(big);

  RandomlyFillArray(big, size_big);

  double start = Seconds();
    BuildHeap(big, size_big);
  printf("elapsed time = %fs\n", Seconds()-start);

  printf("is heap? %d\n", IsHeap(big, size_big));


#endif // BENCHMARK

  return 0;
}
