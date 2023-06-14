#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n);
void print_union(int arr1[], int arr2[], int n1, int n2);
void print_intersection(int arr1[], int arr2[], int n1, int n2);
int is_member(int num, int arr[], int size);
int main(int argc, char *argv[]) {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {4, 5, 6, 7, 8};
  int n1 = 5, n2 = 5;
  print_array(arr1, n1);
  printf("\n");
  print_array(arr2, n2);

  printf("\nUnion\n");
  print_union(arr1, arr2, n1, n2);
  printf("Intersection\n");
  print_intersection(arr1, arr2, n1, n2);

  return EXIT_SUCCESS;
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void print_union(int arr1[], int arr2[], int n1, int n2) {
  for (int i = 0; i < n1; i++) {
    if (is_member(arr1[i], arr2, n2)) {
      printf("%d ", arr1[i]);
    }
  }
  printf("\n");
}

void print_intersection(int arr1[], int arr2[], int n1, int n2) {
  print_array(arr1, n1);
  for (int i = 0; i < n2; i++) {
    if (!is_member(arr2[i], arr1, n1)) {
      printf("%d ", arr2[i]);
    }
  }
}

int is_member(int num, int arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (num == arr[i]) {
      return 1;
    }
  }
  return 0;
}
