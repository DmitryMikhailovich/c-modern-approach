#include <stdio.h>

int main(void) 
{
    int code, first, last;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%3d) %3d-%4d", &code, &first, &last);
    printf("You entered %3d.%3d.%4d\n", code, first, last);

    return 0;
}
