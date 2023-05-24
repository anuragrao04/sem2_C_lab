// Write a C program to find corrupted characters between two files
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *file1 = fopen("file1.txt", "r");
  FILE *file2 = fopen("file2.txt", "r");

  int line_num = 1;
  int n_errors = 0;
  int error_pos = 1;
  int error_count = 0;
  char ch1;
  char ch2;
  while (((ch1 = fgetc(file1)) != EOF) && ((ch2 = fgetc(file2)) != EOF)) {
    if (ch1 == '\n' || ch2 == '\n') {
      line_num += 1;
      error_pos = 1;
      continue;
    }
    if (ch1 != ch2) {
      printf("Line number: %d\tError position: %d\n", line_num, error_pos);
      error_count += 1;
    }
    error_pos += 1;
  }

  printf("Total Errors: %d", error_count);
  return EXIT_SUCCESS;
}
