#include <stdio.h>

int main() {
  int p, q, n;
  scanf("%d", &p);
  scanf("%d", &q);
  scanf("%d", &n);
  int d = (p++ + ++q) * n;
  printf("%d", d);
}
