#include <stdio.h>

int main(void) {

  char *months[12] = {"January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"};
  char *month_str;
  int day, month, year;

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%2d/%2d/%4d", &month, &day, &year);

  if(month < 1 || month > 12) {
     printf("Month value should be between 1 and 12");
     return 1;
  }
  month_str = months[month-1];

  printf("You entered the date %s %d, %d\n", month_str, day, year);
  return 0;
}
