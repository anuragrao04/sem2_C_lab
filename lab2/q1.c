#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("Welcome\n");
  int i = 0;
  while (i <= n) {
    printf("%d\n", i++);
  }
  printf("Thank you");
}
