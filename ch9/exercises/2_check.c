#include <stdio.h>

int check(int x, int y, int n);


int check(int x, int y, int n)
{
    if(x >= 0 && y >= 0 && x <= n-1 && y <= n-1)
        return 1;
    return 0;
}

