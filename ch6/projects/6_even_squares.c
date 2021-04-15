#include <stdio.h>

int main(void)
{
    int n, sq, i;
    printf("Enter number: ");
    scanf("%d", &n);
    for(i = 2; i * i <= 100; i += 2) {
       printf("%d\n", i * i);
    }
    return 0;
} 
