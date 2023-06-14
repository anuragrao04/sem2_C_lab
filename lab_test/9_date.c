#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

int compare_dates(Date d1, Date d2) {
  if (d1.year == d2.year) {
    if (d1.month == d2.month) {
      return d1.day - d2.day;
    }
    return d1.month - d2.month;
  }
  return d1.year - d2.year;
}

int main() {
  Date date1, date2;

  printf("Enter the first date (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &date1.day, &date1.month, &date1.year);

  printf("Enter the second date (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &date2.day, &date2.month, &date2.year);

  int result = compare_dates(date1, date2);

  if (result < 0) {
    printf("Date 1 is earlier than Date 2.\n");
  } else if (result > 0) {
    printf("Date 1 is later than Date 2.\n");
  } else {
    printf("Dates are equal.\n");
  }

  return 0;
}
