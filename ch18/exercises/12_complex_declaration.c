#include <stdlib.h>

float f_arg(long a);
int f_return(double d);
int (*f(float (*)(long), char *)) (double);
//f - function with two arguments
//first - pointer to the function with long argument and return type of float
//second - pointer to char
//f returns pointer to function that accepts double as an argument and returns int
int main(void) {
    char *c = malloc(sizeof(char));
    int (*g)(double) = f(f_arg, c); 

    return 0;
}

float f_arg(long a) {
    return 1.0;
}

int f_return(double d) {
    return 1.0;
}

int (*f(float (*p)(long a), char *d)) (double) {

    return f_return;
}
