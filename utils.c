void printInts(int *ref, int start, int end);

void printInts(int *ref, int start, int end) {
  int i;
  for(i = start; i <= end; i++) {
    printf("%d ", *(ref+i));
  }
  printf("\n");
}
