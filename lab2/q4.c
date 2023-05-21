#include <stdio.h>

int main() {
  int x, y, a, b;
  scanf("%d", &x);
  scanf("%d", &y);
  a = x & y;
  b = 4;
  y = a | b;
  printf("%d", y);
  return 0;
}
