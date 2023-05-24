// Write a C program to merge contents of two files into a third file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char file1_name[32];
  char file2_name[32];
  char file3_name[32];
  printf("\nEnter 1st file name: ");
  scanf("%s", file1_name); // assuming filename does not contain spaces
  printf("\nEnter 2nd file name: ");
  scanf(" %s", file2_name); // assuming filename does not contain spaces
  printf("\nEnter new file name to merge the two files in: ");
  scanf(" %s", file3_name); // assuming filename does not contain spaces

  // assuming file1 and file2 exist
  FILE *file1 = fopen(file1_name, "r");
  FILE *file2 = fopen(file2_name, "r");
  FILE *file3 = fopen(file3_name, "w");

  char line[512];
  while ((fgets(line, 512, file1)) != NULL) {
    fputs(line, file3);
  }
  while (fgets(line, 512, file2) != NULL) {
    fputs(line, file3);
  }
  printf("\nThe first two lines have been merged into %s successfully!\n",
         file3_name);
  fclose(file1);
  fclose(file2);
  fclose(file3);

  return EXIT_SUCCESS;
}
