#include <stdio.h>

#define CUBE(x) ((x)*(x)*(x))
#define REM(n) ((n)%4)
#define PR(x,y) ((x)*(y)) < 100 ? 1 : 0

int main(void) {

    int x = 5;
    int y = 6;

    printf("The cube of %d is %d\n", x, CUBE(x));
    printf("The remainder when %d is divided by 4 is %d\n", x, REM(x));
    printf("%d * %d < 100 ? %d\n", x, y, PR(x,y));

    return 0;
}
