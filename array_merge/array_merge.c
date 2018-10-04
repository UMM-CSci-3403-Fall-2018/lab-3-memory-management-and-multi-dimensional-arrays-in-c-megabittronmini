#include<stdlib.h>
#include<stdio.h>
#include"array_merge.h"
#include"../mergesort/mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_values = 0;

  for (int i = 0; i < num_arrays; i++) {
    total_values += sizes[i];
  }

  if (total_values == 0) {
    return 0;
  }

  int* result = (int*) calloc(total_values, sizeof(int));

  int i = 0;
  for(int j = 0; i < num_arrays; j++) {
    for(int k = 0; k < sizes[k]; k++) {
      result[i] = values[j][k];
      i++;
    }
  }

  mergesort(total_values, result);
  
  int* final_result = (int*) calloc(total_values - result + 1, sizeof(int));

  int counter = 0;
  
  for (int i = 0; i < total_values; i++) {
    if (result[i] != result[i+1]) {
      final_result[i] = result[i];
      counter++;
    } else {
      counter++;
    }
  }

  int* final_result = (int*) calloc(total_values - result + 1, sizeof(int));
  for (int i = 0, j = 1; i < total_values; i++) {
    if (result[i]
  
  return 0;
  
}
