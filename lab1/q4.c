#include <stdio.h>

int main() {
  int x, y, z, a;
  scanf("%d", &x);
  scanf("%d", &y);
  scanf("%d", &z);
  a = x && y || z++;
  printf("%d", z);
  return 0;
}
