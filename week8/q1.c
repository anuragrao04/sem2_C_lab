#include <stdio.h>
#include <string.h>

int main() {
  char st[200];
  scanf("%s", st);
  // a = 97
  // 0 => 97
  // 123 => z
  int arr[26];
  for (int i = 0; i < 26; i++) {
    arr[i] = 0;
  }

  for (int i = 0; i < strlen(st); i++) {
    arr[(int)st[i] - 97] += 1;
  }

  for (int i = 0; i < 26; i++) {
    if (arr[i] != 0) {
      printf("%c %d\n", i + 97, arr[i]);
    }
  }

  return 0;
}
