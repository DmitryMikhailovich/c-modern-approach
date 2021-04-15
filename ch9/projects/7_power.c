#include <stdio.h>

int power(int x, int y);

int main(void)
{
    int x, y;
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of y: ");
    scanf("%d", &y);

    printf("x^y is equals to %d\n", power(x, y));
    return 0;
}

int power(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2 == 1)
        return x * power(x, y-1);
    else {
        int result = power(x, y / 2);
        return result * result;
    }
}

