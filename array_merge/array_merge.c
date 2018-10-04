#include<stdlib.h>
#include<stdio.h>
#include"array_merge.h"
#include"../mergesort/mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) {

  // Count how many elements are in all arrays
  int total_values = 0;
  for (int i = 0; i < num_arrays; i++) {
    total_values += sizes[i];
  }

  // If there are no elements, return an empty array
  if (total_values == 0) {
    int* empty_array = (int*) calloc(1, sizeof(int));
    return empty_array;
  }

  // Concatenate elements from all arrays into one array
  int* combined_array = (int*) calloc(total_values, sizeof(int));
  int k = 0;
  for(int i = 0; i < num_arrays; i++) {
    for(int j = 0; j < sizes[i]; j++) {
      combined_array[k] = values[i][j];
      k++;
    }
  }

  // Sort the combined array so we can remove repeated elements later
  mergesort(total_values, combined_array);

  // Count the repeated elements in the combined array
  // Set repeated elements to -1 so we can keep track of values to ignore later
  int repeated = 0;
  for (int i = total_values - 1; i > 0; i--) {
    if (combined_array[i] == combined_array[i-1]) {
      combined_array[i] = -1;
      repeated++;
    }
  }

  // Create merged array with the proper size
  int* merged_array = (int*) calloc(total_values - repeated + 1, sizeof(int));
  
  // Insert the total number of elements at position 0
  merged_array[0] = total_values - repeated;

  // Set the rest of the elements to be non-repeated values
  for (int i = 0, j = 1; i < total_values; i++) {
    if (combined_array[i] != -1) {
      merged_array[j] = combined_array[i];
      j++;
    }
  }

  free(combined_array);
  
  return merged_array;
  
}
