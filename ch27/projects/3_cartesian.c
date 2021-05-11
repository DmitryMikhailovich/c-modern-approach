#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    double a, b, r, theta;

    printf("r=");
    scanf("%lg", &r);
    printf("theta=");
    scanf("%lg", &theta);

    a = r * cos(theta);
    b = r * sin(theta);

    printf("%g %c %g\n", a, b >= 0 ? '+' : '-', b);

    return 0;
}
