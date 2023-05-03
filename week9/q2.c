#include <stdio.h>
#include <stdlib.h>

struct COMPLEX {
  float real;
  float imaginary;
};

void readComplex(struct COMPLEX *a);
void addComplex(struct COMPLEX *a, struct COMPLEX *b, struct COMPLEX *c);
void displayComplex(struct COMPLEX *a);

int main(int argc, char *argv[]) {
  struct COMPLEX a, b, c;
  readComplex(&a);
  readComplex(&b);

  addComplex(&a, &b, &c);
  displayComplex(&c);
  return EXIT_SUCCESS;
}

void readComplex(struct COMPLEX *a) { scanf("%f %f", &a->real, &a->imaginary); }

void addComplex(struct COMPLEX *a, struct COMPLEX *b, struct COMPLEX *c) {
  c->real = a->real + b->real;
  c->imaginary = a->imaginary + b->imaginary;
}

void displayComplex(struct COMPLEX *a) {
  printf("%.1f + %.1fi", a->real, a->imaginary);
}
