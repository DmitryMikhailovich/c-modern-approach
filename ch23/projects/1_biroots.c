#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    double a, b, c, d, x1, x2;

    printf("Enter values of a, b, c in equation ax^2 + bx + c = 0\n");
    printf("a= ");
    scanf(" %lf", &a);
    printf("b= ");
    scanf(" %lf", &b);
    printf("c= ");
    scanf(" %lf", &c);

    d = pow(b, 2.0) - 4.0 * a * c;

    if(d < 0) {
        printf("Roots are complex\n");
        exit(EXIT_FAILURE);
    }

    x1 = (-b + sqrt(d)) / (2.0 * a);
    x2 = (-b - sqrt(d)) / (2.0 * a);
    
    printf("Roots of equation %.2fx^2 + %.2fx + %.2f = 0 are:\n", a, b, c);
    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);

    return 0;
}
