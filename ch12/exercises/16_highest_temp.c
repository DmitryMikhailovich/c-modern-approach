#include <stdio.h>

int find_largest(int *a, int n);
void print_highest_temp(int *temperatures);

int main(void)
{
    int temperatures[7][24] = {0};
    temperatures[1][20] = 12;
    temperatures[5][2] = 4;
    print_highest_temp(temperatures[0]);
    return 0;
}

int find_largest(int *a, int n)
{
    int max = *a;
    for(int *p = a+1; p < a + n; p++)
        if(max < *p)
            max = *p;
    return max;
}

void print_highest_temp(int *temperatures)
{
    for(int *p = temperatures; p < temperatures + 7*24; p += 24)
        printf("%3d", find_largest(p, 24));
    printf("\n");
}


