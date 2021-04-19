#include <stdio.h>
#include <math.h>

double evaluate_polynomial(double a[], int n, double x);

int main(void) {
    double a[3] = {1.1, 2.0, 3.5};
    int n = 2;
    double x = 1.5;

    printf("evaluate_polynomial([%.1f, %.1f, %.1f], %d, %.1f) = %f\n",
        a[0], a[1], a[2], n, x, evaluate_polynomial(a, n, x));

    return 0;
}

double evaluate_polynomial(double a[], int n, double x) {
    double result = 0;
    for(int i = n-1; i >= 0; i--) {
        if(i == n-1) 
            result = fma(a[i+1], x, a[i]);
        else
            result = fma(result, x, a[i]);
    }
    return result;
}

