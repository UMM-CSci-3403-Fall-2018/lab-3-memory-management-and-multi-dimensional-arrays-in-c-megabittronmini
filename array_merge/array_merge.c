#include<stdlib.h>
#include<stdio.h>
#include"array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {

  for (int i = 0; i < num_arrays; i++) {
    if (sizes[i]==0) {
      return sizes;
    }
  }

  int result_size = 0;
  
  for (int i = 0; i < num_arrays; i++) {
    result_size += sizes[i];
  }

  return 0;
}
