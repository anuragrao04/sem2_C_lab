#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int counter = 1;
  int num;
  printf("Enter number of rows: ");
  scanf("%d", &num);
  for (int i = 0; i <= num; i++) {
    for (int j = 0; j < i; j++) {
      printf("%d ", counter);
      counter++;
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
