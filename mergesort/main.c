#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

int main()

  
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergesort(arr_size,arr); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
