void printInts(int *ref, int count);

void printInts(int *ref, int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("%d ", *(ref+i));
  }
  printf("\n");
}
