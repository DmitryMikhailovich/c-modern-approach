#include <stdio.h>
#include <math.h>

#define DISP(f,x) printf( #f "(%g) = %g\n", (x), (f (x)))
#define DISP2(f,x,y) printf( #f "(%g,%g) = %g\n", (x), (y), (f ((x),(y)))) 


double sum(double x, double y);


int main(void) {
    DISP(sqrt, 3.0);
    DISP2(sum, 3.4, 5.5);
    return 0;
}        


double sum(double x, double y) {
    return x + y;
}
