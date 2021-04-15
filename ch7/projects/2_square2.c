#include <stdio.h>

int main(void)
{
    int i, num;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);
    getchar();    
    for (i = 1; i <= num ; i++) {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return 0;
} 
