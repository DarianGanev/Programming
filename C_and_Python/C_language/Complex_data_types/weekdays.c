#include <stdio.h>

enum Weekday {
  MONDAY = 1,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
};

int main(void) {

  printf("Please enter a weekday\n");
  int dayInput;
  scanf("%d", &dayInput);

  enum Weekday week = dayInput;

  switch (week) {
    case MONDAY:
      printf("Its Monday");
      break;
    case TUESDAY:
      printf("Its Tuesday");
      break;
    case WEDNESDAY:
      printf("Its Wednesday");
      break;
    case THURSDAY:
      printf("Its Thursday");
      break;
    case FRIDAY:
      printf("Its Friday");
      break;
    case SATURDAY:
      printf("Its Saturday");
      break;
    case SUNDAY:
      printf("Its Sunday");
      break;
    default:
      printf("Invalid weekday!\n");
      break;
  }

  return 0;
}