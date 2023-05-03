#include <stdio.h>

void readMatrix(int m, int n, int a[][n]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}

void displayMatrix(int m, int n, int a[][n]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

int multiplyMatrix(int m, int n, int p, int q, int a[][n], int b[][q],
                   int c[][q]) {
  if (n != p) {
    printf("Matrix multiplication is not possible\n");
    return 0;
  }
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < q; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return 1;
}

int main() {
  int m, n, p, q;
  scanf("%d %d", &m, &n);
  int a[m][n];
  scanf("%d %d", &p, &q);
  int b[p][q];
  readMatrix(m, n, a);
  readMatrix(p, q, b);
  int c[m][q];
  int show = multiplyMatrix(m, n, p, q, a, b, c);
  if (show) {
    displayMatrix(m, q, c);
  }
  return 0;
}
