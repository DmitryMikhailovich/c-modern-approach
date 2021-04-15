#include <stdio.h>
#include <math.h>

int main(void)
{
    float number, old_root, root;
    printf("Enter a positive number: ");
    scanf("%f", &number);
    root = 1;
    do {
        old_root = root;
        root = ( root + number / root ) / 2.0f; 
    } while (fabs(old_root - root) >= 0.00001);
    printf("Square root: %f\n", root);
    return 0;
}
