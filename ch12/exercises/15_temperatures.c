#include <stdio.h>

void print_temperatures(int *temperatures, int row_num);

int main(void)
{
    int temperatures[7][24] = {0};
    temperatures[1][20] = 12;
    temperatures[5][2] = 4;
    print_temperatures(temperatures[0], 1);
    return 0;
}

void print_temperatures(int *temperatures, int row_num)
{
    for(int *p = temperatures + row_num*24; p <= temperatures + row_num*24 + 24; p++) {
        printf("%3d", *p);
    }
    printf("\n");
}

