#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cricket {
  char name[50];
  char country[50];
  int score;
};

void readInfo(struct Cricket a[], int n);
void sort(struct Cricket a[], int n);
void display(struct Cricket a[], int n);

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  struct Cricket players[n];
  readInfo(players, n);
  sort(players, n);
  display(players, n);

  return EXIT_SUCCESS;
}

void readInfo(struct Cricket a[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i].name);
    scanf("%s", a[i].country);
    scanf("%d", &a[i].score);
  }
}

void sort(struct Cricket a[], int n) {
  struct Cricket temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(a[j].country, a[j + 1].country) > 0) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

void display(struct Cricket a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%s %s %d\n", a[i].name, a[i].country, a[i].score);
  }
}
