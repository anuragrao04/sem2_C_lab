#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int rollno;
  char name[30];
} student_t;

void sort_by_rollno(student_t students[], int num_students) {
  int i, j;
  student_t key;
  for (i = 1; i < num_students; i++) {
    key = students[i];
    j = i - 1;
    while (j >= 0 && students[j].rollno > key.rollno) {
      students[j + 1] = students[j];
      j = j - 1;
    }
    students[j + 1] = key;
  }
}
void sort_by_name(student_t students[], int num_students) {
  int i, j;
  student_t key;
  for (i = 1; i < num_students; i++) {
    key = students[i];
    j = i - 1;
    while (j >= 0 && strcmp(students[j].name, key.name) > 0) {
      students[j + 1] = students[j];
      j = j - 1;
    }
    students[j + 1] = key;
  }
}
int main(int argc, char *argv[]) {
  FILE *csv_file = fopen("stud_details.csv", "r");
  char buffer[64];
  fgets(buffer, 64, csv_file); // to get rid of the headers

  student_t students[128];
  int num_students = 0;

  while (fgets(buffer, 64, csv_file) != NULL) {
    char *rno_str = strtok(buffer, ",");
    char *name = strtok(NULL, ",");
    int rno = atoi(rno_str);
    strcpy(students[num_students].name, name);
    students[num_students].rollno = rno;
    num_students++;
  }
  fclose(csv_file);
  int choice = 0;

  do {
    printf(
        "\n1. Sort by roll number\n2. Sort by name\n3. Exit\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
      sort_by_rollno(students, num_students);
      for (int i = 0; i < num_students; i++) {
        printf("%d %s", students[i].rollno, students[i].name);
      }
      continue;
    } else if (choice == 2) {
      sort_by_name(students, num_students);
      for (int i = 0; i < num_students; i++) {
        printf("%d %s", students[i].rollno, students[i].name);
      }
      continue;
    }
    break;
  } while (choice > 0 && choice <= 3);

  return 0;
}
