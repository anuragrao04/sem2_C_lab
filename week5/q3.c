#include <stdio.h>

int checkPerfect(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (n % (i * j) == 0) {
        sum += i;
        break;
      }
    }
  }

  return sum == n;
}

int main() {
  int n = 0;
  scanf("%d", &n);
  if (checkPerfect(n)) {
    printf("Perfect number");
  } else {
    printf("Not a perfect number");
  }
}
