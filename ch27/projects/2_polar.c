#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    double a, b, r, theta;

    printf("a=");
    scanf("%lg", &a);
    printf("b=");
    scanf("%lg", &b);

    theta = carg(a + b * I);
    r = sqrt(a * a + b * b);
    printf("r = %g, theta = %g\n", r, theta);

    return 0;
}
