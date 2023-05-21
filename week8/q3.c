#include <stdio.h>
#include <string.h>

void vowFreqConCount(char *str, int *count) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == 'a' || str[i] == 'A') {
      count[0]++;
    } else if (str[i] == 'e' || str[i] == 'E') {
      count[1]++;
    } else if (str[i] == 'i' || str[i] == 'I') {
      count[2]++;
    } else if (str[i] == 'o' || str[i] == 'O') {
      count[3]++;
    } else if (str[i] == 'u' || str[i] == 'U') {
      count[4]++;
    } else if (!isspace(str[i]) && !isdigit(str[i])) {
      count[5]++;
    }
  }
}

int main() {
  char st[100];
  gets(st, 100, stdin);
  int count[6];
  vowFreqConCount(st, count);
  for (int i = 0; i < 6; i++) {
    printf("%d ", count[i]);
  }
  return 0;
}
