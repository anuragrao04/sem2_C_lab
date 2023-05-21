#include <stdio.h>

int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  int factorial = 1;
  while (n > 1) {
    factorial *= n;
    n--;
  }
  return factorial;
}

int ncr(int n, int r) {
  return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  printf("%d", ncr(n, r));
  return 0;
}
