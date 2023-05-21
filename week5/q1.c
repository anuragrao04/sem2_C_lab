#include <stdio.h>

int isPrime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int nextPrime(int n) {
  n++;
  while (1) {
    if (isPrime(n)) {
      return n;
    } else {
      n++;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", nextPrime(n));
  return 0;
}
