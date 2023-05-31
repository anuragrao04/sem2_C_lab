#include "../insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  printf("Enter the number of elements you want to sort: ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nBefore sorting:\n");

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }

  insertion_sort_numbers(arr, n);

  printf("\nAfter sorting:\n");

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }

  return EXIT_SUCCESS;
}
