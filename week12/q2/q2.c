// Write a C program to write multiple lines to a file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n_lines;
  char file_name[32];
  printf("\nEnter file name: ");
  scanf("%s", file_name); // assuming no spaces in file name
  printf("\nEnter number of lines you want to write: ");
  scanf("%d", &n_lines);
  getchar(); // consume the newline character left in the input buffer
  FILE *file = fopen(file_name, "w");
  char line[512];

  for (int i = 0; i < n_lines; i++) {
    printf("Enter line%d: ", i + 1);
    fgets(line, 512, stdin);
    fprintf(file, "%s", line);
  }

  printf("\nDone!");
  fclose(file);

  return EXIT_SUCCESS;
}
