#include <stdio.h>

int main() {
  int i;
  scanf("%d", &i);
  while (i < 10) {
    printf("hello\n");
    i++;
    while (i < 8) {
      printf("bye\n");
      i++;
    }
  }
  return 0;
}
