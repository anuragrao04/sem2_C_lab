#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Enter number: ");
  scanf("%d", &num);

  int temp = num;
  int reverse = 0;
  int remainder;
  while (temp != 0) {
    remainder = temp % 10;
    reverse = reverse * 10 + remainder;
    temp = temp / 10;
  }

  if (num == reverse) {
    printf("\npalindrome");
  } else {
    printf("\nnot palindrome");
  }

  return EXIT_SUCCESS;
}
