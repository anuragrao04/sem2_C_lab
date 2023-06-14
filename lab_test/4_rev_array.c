#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void rev_arr_index(int a[], int n);
void rev_arr_pointer(int *a, int n);

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  int copy_arr[] = {1, 2, 3, 4, 5};
  print_array(arr, 5);

  printf("\nIndex Notation: ");
  rev_arr_index(arr, 5);
  print_array(arr, 5);

  printf("\nPointer Notation: ");
  rev_arr_pointer(copy_arr, 5);
  print_array(copy_arr, 5);

  return EXIT_SUCCESS;
}

void rev_arr_index(int a[], int n) {
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

void rev_arr_pointer(int *a, int n) {
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
