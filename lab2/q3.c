#include <stdio.h>

int main() {
  int a, b, *pA;
  scanf("%d", &a);
  pA = &a;
  a++;
  b = *pA;
  printf("%d\n%d", a, b);
}
