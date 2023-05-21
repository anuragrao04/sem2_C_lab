#include <stdio.h>

void readArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

int isMember(int search, int a[], int n) {
  // linear search
  for (int i = 0; i < n; i++) {
    if (a[i] == search) {
      return 1;
    }
  }
  return 0;
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void sort(int arr[], int n) {
  int i, j, min_i;
  for (i = 0; i < n - 1; i++) {
    min_i = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_i]) {
        min_i = j;
      }
    }
    swap(&arr[min_i], &arr[i]);
  }
}

void printUnion(int arr1[], int arr2[], int m, int n, int *retArr) {
  int sum = n;
  for (int i = 0; i < n; i++) {
    retArr[i] = arr2[i];
  }
  int index = n;

  for (int i = 0; i < m; i++) {
    if (!isMember(arr1[i], arr2, n)) {
      // printf("%d ", arr1[i]);
      retArr[index] = arr1[i];
      index++;
      sum++;
    }
  }

  sort(retArr, sum);
  printArray(retArr, sum);
}

void printIntersection(int arr1[], int arr2[], int m, int n) {
  int i = 0, j = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (arr1[i] == arr2[j]) {
        printf("%d ", arr1[i]);
      }
    }
  }
}

int main() {
  int m;
  scanf("%d", &m);
  int arr1[m];
  readArray(arr1, m);

  int n;
  scanf("%d", &n);
  int arr2[n];
  readArray(arr2, n);
  int retArr[20];
  printUnion(arr1, arr2, m, n, retArr);
  printf("\n");
  printIntersection(arr1, arr2, m, n);

  return 0;
}
