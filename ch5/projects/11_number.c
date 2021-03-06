#include <stdio.h>

int main(void) 
{
    int number, tens, units;
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    tens = number / 10;
    units = number % 10;
    
    printf("You entered the number ");
    switch(tens) {
        case 9: printf("ninety"); break;
        case 8: printf("eighty"); break;
        case 7: printf("seventy"); break;
        case 6: printf("sixty"); break;
        case 5: printf("fifty"); break;
        case 4: printf("fourty"); break;
        case 3: printf("thirty"); break;
        case 2: printf("twenty"); break;
        case 1:
        switch(units) {
            case 9: printf("nineteen"); break;
            case 8: printf("eighteen"); break;
            case 7: printf("seventeen"); break;
            case 6: printf("sixteen"); break;
            case 5: printf("fiveteen"); break;
            case 4: printf("fourteen"); break;
            case 3: printf("thirteen"); break;
            case 2: printf("twelve"); break;
            case 1: printf("eleven"); break;
            case 0: printf("ten"); break;
        }
    }
    
    if (tens != 1) {
        if (tens != 0) 
            printf("-");
        switch(units) {
            case 9: printf("nine"); break;
            case 8: printf("eight"); break;
            case 7: printf("seven"); break;
            case 6: printf("six"); break;
            case 5: printf("five"); break;
            case 4: printf("four"); break;
            case 3: printf("three"); break;
            case 2: printf("two"); break;
            case 1: printf("one"); break;
        }
    }
    printf("\n");
    return 0;
}

