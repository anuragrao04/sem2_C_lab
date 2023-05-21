#include <stdio.h>
#include <string.h>

int countWords(char *text, int *count);

int main() {
  char str[100];
  fgets(str, 100, stdin);
  int count[10];
  int n = countWords(str, count);
  for (int i = 0; i < n; i++) {
    printf("%d ", count[i]);
  }

  return 0;
}

int countWords(char *text, int *count) {
  int c = 0;
  int n = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '\n') {
      break;
    }
    if (text[i] != ' ') {
      c++;
    } else {
      if (text[i - 1] != ' ') {
        count[n] = c;
        c = 0;
        n++;
      }
    }
  }
  count[n] = c;
  n++;
  return n;
}
