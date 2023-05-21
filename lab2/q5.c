#include <stdio.h>

int main() {
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  if (x == 0 && y == 0) {
    printf("Origin");
    return 0;
  }
  if (x > 0) {
    if (y > 0) {
      printf("First Quadrant");
    } else {
      printf("Fourth Quadrant");
    }
  } else {
    if (y > 0) {
      printf("Second Quadrant");
    } else {
      printf("Third Quadrant");
    }
  }
  return 0;
}
