#include <stdio.h>
#include <stdlib.h>

struct DISTANCE {
  int Feet;
  float Inch;
};

void readDistance(struct DISTANCE *d);
struct DISTANCE addDistance(struct DISTANCE *d1, struct DISTANCE *d2);
void displayDistance(struct DISTANCE *d);

int main(int argc, char *argv[]) {
  struct DISTANCE d1;
  struct DISTANCE d2;
  readDistance(&d1);
  readDistance(&d2);

  struct DISTANCE sum = addDistance(&d1, &d2);
  displayDistance(&sum);
  return EXIT_SUCCESS;
}

void readDistance(struct DISTANCE *d) {
  scanf("%d", &d->Feet);
  scanf("%f", &d->Inch);
}

struct DISTANCE addDistance(struct DISTANCE *d1, struct DISTANCE *d2) {
  struct DISTANCE sum;
  sum.Feet = d1->Feet + d2->Feet;
  sum.Inch = d1->Inch + d2->Inch;
  if (sum.Inch >= 12.0) {
    sum.Inch -= 12.0;
    sum.Feet++;
  }
  return sum;
}

void displayDistance(struct DISTANCE *d) { printf("%d'-%f", d->Feet, d->Inch); }
