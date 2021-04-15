#include <stdio.h>

int main(void)
{
    printf("%-8.1e", 1.234);
    printf("%10.6e", 1.234);
    printf("%-8.3f", 1.2345);
    printf("%6.0f", 1.2345);
    return 0;
}
