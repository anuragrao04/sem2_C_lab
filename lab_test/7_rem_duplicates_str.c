#include <stdio.h>
#include <string.h>

void remove_duplicates(char *str) {
  int i, j, k;

  for (i = 0; i < strlen(str); i++) {
    for (j = i + 1; str[j] != '\0'; j++) {
      if (str[j] == str[i]) {
        for (k = j; str[k] != '\0'; k++) {
          str[k] = str[k + 1];
        }
      }
    }
  }
}

int main() {
  char str[100];

  printf("Please Enter any String: ");
  fgets(str, 100, stdin);

  remove_duplicates(str);

  printf("The Final String after Removing All Duplicates = %s\n", str);

  return 0;
}
