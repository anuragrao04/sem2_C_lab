#include <stdio.h>
#include <stdlib.h>

union Shape {
  int number_of_sides;
  float radius;
  float sides[2]; // base and length of rect
};

enum ShapeType { CIRCLE, TRIANGLE, RECTANGLE };

struct ShapeInfo {
  enum ShapeType type;
  union Shape shape;
};

void printShapeInfo(struct ShapeInfo shapeInfo) {
  switch (shapeInfo.type) {
  case CIRCLE:
    printf("Shape: Circle\nRadius: %.2f\n", shapeInfo.shape.radius);
    break;
  case TRIANGLE:
    printf("Shape: Triangle\nNumber of Sides: %d\n",
           shapeInfo.shape.number_of_sides);
    break;
  case RECTANGLE:
    printf("Shape: Rectangle\nBase: %.2f\nLength: %.2f\n",
           shapeInfo.shape.sides[0], shapeInfo.shape.sides[1]);
    break;
  default:
    printf("Invalid ShapeType\n");
    break;
  }
}

int main(int argc, char *argv[]) {
  struct ShapeInfo shapeInfo1 = {CIRCLE, .shape.radius = 5};
  struct ShapeInfo shapeInfo2 = {TRIANGLE, .shape.number_of_sides = 3};
  struct ShapeInfo shapeInfo3 = {RECTANGLE, .shape.sides = {6, 6}};
  printShapeInfo(shapeInfo1);
  printShapeInfo(shapeInfo2);
  printShapeInfo(shapeInfo3);
  return EXIT_SUCCESS;
}
