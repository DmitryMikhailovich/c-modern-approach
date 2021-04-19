#include <stdio.h>
#include <math.h>


double round_nearest(double x, int n);

int main(void) {
    double x;
    int n;

    x = 3.123456; n = 4;
    printf("round_nearest(%f, %d) = %f\n", x, n, round_nearest(x, n)); 
    x = -3.123456; n = 4;
    printf("round_nearest(%f, %d) = %f\n", x, n, round_nearest(x, n)); 
    x = 12.31; n = 3;
    printf("round_nearest(%f, %d) = %f\n", x, n, round_nearest(x, n)); 
    x = -58.5; n = 1;
    printf("round_nearest(%f, %d) = %f\n", x, n, round_nearest(x, n)); 
    return 0;

}

double round_nearest(double x, int n) {
    x = x * pow(10.0, n);
    return (x < 0.0 ? ceil(x - 0.5) : floor(x + 0.5)) / pow(10.0, n);
}
