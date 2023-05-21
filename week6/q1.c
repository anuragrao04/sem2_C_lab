#include <stdio.h>
void readArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

void copyArray(int a[], int copy[], int n) {
  for (int i = 0; i < n; i++) {
    copy[i] = a[i];
  }
}

void displayArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void reverseArray1(int a[], int n) {
  int temp[n];
  int num = 0;
  for (int i = n - 1; i >= 0; i--) {
    temp[i] = a[num];
    num++;
  }

  for (int i = 0; i < n; i++) {
    a[i] = temp[i];
  }
}

void reverseArray2(int *a, int n) {
  int *l = &a[n - 1];
  int *f = a;

  while (l > f) {
    int temp = *l;
    *l = *f;
    *f = temp;
    f++;
    l--;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  readArray(a, n);

  int copy[n];
  copyArray(a, copy, n);

  printf("Using index notation\n");
  displayArray(a, n);
  reverseArray1(a, n);
  displayArray(a, n);

  printf("Using pointer notation\n");
  displayArray(copy, n);
  reverseArray2(copy, n);
  displayArray(copy, n);
}
