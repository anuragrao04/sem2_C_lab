#include <stdio.h>

int getNextValue(int n) {
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return (3 * n) + 1;
  }
}

int getHailstone(int n) {
  printf("%d ", n);
  if (n == 1) {
    return 0;
  } else {
    getHailstone(getNextValue(n));
  }
}

int main() {
  int n;
  scanf("%d", &n);
  getHailstone(n);
}
