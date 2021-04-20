#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

double try_math_fcn(double (fcn)(double), double value, char *msg);

int main(void) {
    double X[] = {4.0, -1.0};
    double x;
    double y;

    for(int i = 0; i < 2; i++) {
        x = X[i];
        y = try_math_fcn(sqrt, x, "Error in call of sqrt");
        printf("The result of sqrt(%.2f) is %.2f\n", x, y); 
    }

    return 0;
}

    
double try_math_fcn(double (fcn)(double), double value, char *msg) {
    errno = 0;

    double result = fcn(value);
    if(errno != 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    } else {
        return result;
    }
}

