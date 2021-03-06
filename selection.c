#include <stdio.h>
#include "utils.c"

// selection sort w/ pointers

void selection(int *items, int itemCount);

int main(int argc, char *argv[])
{
  int itemCount = 9;
  int items[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};

  printInts(items, 0, itemCount - 1);
  selection(items, itemCount);
  printInts(items, 0, itemCount - 1);

  return 0;
}

void selection(int *items, int itemCount) {
  int i;
  for(i = 0; i < itemCount - 1; i++) {
    // try and find item smaller than one at i
    int j;
    int smallestJ = i;
    for(j = i+1; j < itemCount; j++) {
      if(*(items + j) < *(items + smallestJ)) {
        smallestJ = j;
      }
    }

    if(smallestJ != i) { // found item smaller than one at i, so swap it in
      int oldItem = *(items + i);
      *(items + i) = *(items + smallestJ);
      *(items + smallestJ) = oldItem;
    }
  }
}
