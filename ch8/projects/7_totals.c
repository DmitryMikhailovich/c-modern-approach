#include <stdio.h>

int main(void) 
{
    int matrix[5][5];
    int row_totals[5] = {0}, col_totals[5] = {0};
    int i, j;
    for(i = 0; i < 5; i++) {
        printf("Enter row %d: ", i+1);
        for(j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            row_totals[i] += matrix[i][j];
            col_totals[j] += matrix[i][j];
        }
    }
    printf("Row totals:");
    for(i = 0; i< 5; i++)
        printf(" %d", row_totals[i]);
    printf("\nColumn totals:");
    for(j = 0; j < 5; j++)
        printf(" %d", col_totals[j]);
    printf("\n");
    return 0;
} 
