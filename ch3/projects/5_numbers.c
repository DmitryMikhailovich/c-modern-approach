#include <stdio.h>

int main(void) 
{
    int c11, c12, c13, c14,
    c21, c22, c23, c24,
    c31, c32, c33, c34,
    c41, c42, c43, c44;
    printf("Enter the numbers from 1 to 15 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
    &c11, &c12, &c13, &c14, &c21, &c22, &c23, &c24, &c31, &c32, &c33, &c34,
    &c41, &c42, &c43, &c44);
    
    printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n",
    c11, c12, c13, c14,
    c21, c22, c23, c24,
    c31, c32, c33, c34,
    c41, c42, c43, c44);
    printf("Row sums: %2d %2d %2d %2d\n", c11+c12+c13+c14, c21+c22+c23+c24, 
    c31+c32+c33+c34, c41+c42+c43+c44);
    printf("Column sums: %2d %2d %2d %2d\n", c11+c21+c31+c41, c12+c22+c32+c42,
    c13+c23+c33+c43, c14+c24+c34+c44);
    printf("Diagonal sums: %2d %2d\n", c11+c22+c33+c44, c41+c32+c23+c14);

    return 0;
}
