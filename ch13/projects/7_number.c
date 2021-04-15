#include <stdio.h>

int main(void) 
{
    int number, tens, units;
    char *tens_values[] = {"twenty", "thirty", "fourty",
      "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens_values[] = {"ten", "eleven", "twelve", "thirteen",
         "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
         "nineteen"};
    char *units_values[] = {"one", "two", "three", "four", "five", 
         "six", "seven", "eight", "nine"};
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    tens = number / 10;
    units = number % 10;
    
    printf("You entered the number ");
    if(tens > 1) {
       printf(tens_values[tens-2]);
       if (units != 0) { 
            printf("-");
            printf(units_values[units-1]);
       }
    } else if(tens == 1) {
       printf(teens_values[units]);
    } else {
        printf(units_values[units-1]);
    }
    
    printf("\n");
    return 0;
}

