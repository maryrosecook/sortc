#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.c"

// quicksort (in place)

void quicksort(int *items, int left, int right);
int partition(int *items, int left, int right, int pivotIndex);
void swap(int *items, int i, int j);

int main(int argc, char *argv[])
{
  int itemCount = 20;
  int *items = malloc(sizeof(int) * itemCount);
  int i;
  for(i = 0; i < itemCount; i++) {
    items[i] = itemCount - 1 - i;
  }

  printInts(items, 0, itemCount - 1);
  quicksort(items, 0, itemCount - 1);
  printInts(items, 0, itemCount - 1);

  free(items);

  return 0;
}

void quicksort(int *items, int left, int right) {
  if(left < right) {
    int pivotIndex = floor((right + left) / 2);
    int newPivotIndex = partition(items, left, right, pivotIndex);

    quicksort(items, left, newPivotIndex - 1);
    quicksort(items, newPivotIndex + 1, right);
  }
}

int partition(int *items, int left, int right, int pivotIndex) {
  int pivotValue = items[pivotIndex];
  swap(items, pivotIndex, right);

  int i;
  int storeIndex = left;
  for(i = left; i < right; i++) {
    if(items[i] < pivotValue) {
      swap(items, i, storeIndex);
      storeIndex++;
    }
  }

  swap(items, storeIndex, right);
  return storeIndex;
}

void swap(int *items, int i, int j) {
  int tmp = items[i];
  items[i] = items[j];
  items[j] = tmp;
}
