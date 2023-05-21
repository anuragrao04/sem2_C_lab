#include <stdio.h>

int readArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

int displayArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int delEleAtPos(int arr[], int *n, int pos) {

  for (int i = pos + 1; i < *n; i++) {
    arr[i - 1] = arr[i];
  }
  *n -= 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  readArray(arr, n);
  int pos;
  scanf("%d", &pos);
  if (pos >= 0 && pos < n) {
    displayArray(arr, n);
    printf("\n");
    delEleAtPos(arr, &n, pos);
    displayArray(arr, n);
  } else {
    printf("Invalid position");
  }
  return 0;
}
