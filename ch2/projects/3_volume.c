#include <stdio.h>

int main(void) 
{
    float volume, radius;
    printf("Enter radius of sphere: ");
    scanf("%f", &radius);
    volume = (4.0 / 3.0) * 3.1415 * radius * radius * radius;
    printf("Volume of sphere with a %.1f meter radius is %.1f\n", radius, volume);
    return 0;
}
