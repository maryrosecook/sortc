#include <stdio.h>
#include <math.h>
#include "utils.c"

// merge sort
void merge(int *items, int *tmp, int p, int q, int r);
void mergeSort(int *items, int *tmp, int p, int r);

int main(int argc, char *argv[])
{
  int itemCount = 9;
  int items[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
  int tmp[9] = {};

  printInts(items, itemCount);
  mergeSort(items, tmp, 0, itemCount - 1);
  printInts(items, itemCount);

  return 0;
}

void mergeSort(int *items, int *tmp, int p, int r)
{
  if(p < r) {
    int q = floor((p + r) / 2);
    mergeSort(items, tmp, p, q);
    mergeSort(items, tmp, q + 1, r);
    merge(items, tmp, p, q, r);
  }
}

void merge(int *items, int *tmp, int p, int q, int r) {
  int aCount = p;
  int bCount = q + 1;

  int i;

  // read numbers to be merged into tmp
  for(i = p; i <= r; i++) {
    tmp[i] = items[i];
  }

  for(i = p; i <= r; i++) {
    if(aCount > q) {
      items[i] = tmp[bCount];
      bCount++;
    }
    else if(bCount > r) {
      items[i] = tmp[aCount];
      aCount++;
    }
    else if(tmp[aCount] <= tmp[bCount]) {
      items[i] = tmp[aCount];
      aCount++;
    }
    else if(tmp[bCount] < tmp[aCount]) {
      items[i] = tmp[bCount];
      bCount++;
    }
  }
}
