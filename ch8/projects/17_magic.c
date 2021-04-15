#include <stdio.h>

int main(void) 
{
    int n, i, j;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &n);
    if(!(n > 0 && n < 100 && n % 2 == 1)) {
        printf("The size must be an odd number between 1 and 99. Terminating...\n");
        return 1;
    }

    int square[n][n];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            square[i][j] = 0;

    i = 0;
    j = n / 2;
    square[i][j] = 1;
    for(int k = 2; k <= n*n; k++) {
        i = i == 0 ? n-1 : i - 1;
        j = j == n-1 ? 0 : j + 1; 
        if(square[i][j] != 0) {
            i = (i + 2) % n; 
            j = j == 0 ? n-1 : j - 1;
        }
        square[i][j] = k;
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            printf("%6d", square[i][j]);
            if(j == n-1)
                printf("\n");
        }
    return 0;
}
