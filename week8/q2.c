#include <stdio.h>
#include <string.h>

int strend(char s[], char t[]);

int main() {
  char st1[100];
  char st2[100];

  scanf("%s", st1);
  scanf(" %s", st2);

  printf("%d", strend(st1, st2));
}

int strend(char s[], char t[]) {
  int len_t = strlen(t);
  int len_s = strlen(s);
  int i = len_s - len_t;
  int n = 0;
  for (i; i < len_s; i++) {
    if (s[i] != t[n]) {
      return 0;
    }
    n++;
  }
  return 1;
}
