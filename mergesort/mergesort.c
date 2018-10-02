#include<stdlib.h>
#include<stdio.h>
#include"mergesort.h"

//There's no need to sort an array less than size 2
bool needsSorting(int rangeSize) {
    return rangeSize >= 2;
}

void mergeRanges(int *values, int start, int midPoint, int end) {
    int rangeSize = end - start;
    int *destination = (int*) calloc(rangeSize+1, sizeof(int));
    int first = start;
    int second = midPoint;
    int copy = 0;
    while (first < midPoint && second < end) {
      if (values[first] < values[second]) {
        destination[copy] = values[first];
        ++first;
      } else {
        destination[copy] = values[second];
        ++second;
      }
      ++copy;
    }
    while (first < midPoint) {
      destination[copy] = values[first];
      ++copy;
      ++first;
    }
    while (second < end) {
      destination[copy] = values[second];
      ++copy;
      ++second;
    }
    for (int i = 0; i < rangeSize; ++i) {
      values[i + start] = destination[i];
    }
    free(destination);
}

void mergesortRange(int *values, int start, int end) {
  int rangeSize = end - start;
  if (needsSorting(rangeSize)) {
    int midPoint = (start + end) / 2;
    mergesortRange(values, start, midPoint);
    mergesortRange(values, midPoint, end);
    mergeRanges(values, start, midPoint, end);
  }
}

void mergesort(int size, int *values) {
  mergesortRange(values, 0, size);
}
