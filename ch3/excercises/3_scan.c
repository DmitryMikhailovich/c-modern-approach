#include <stdio.h>

int main(void)
{   
    int i, j, k;
    scanf("%d", &i);
    printf("%d\n", i);
    scanf(" %d", &i);
    printf(" %d\n", i);
    scanf("%d-%d-%d", &i, &j, &k);
    printf("%d-%d-%d\n", i, j, k);
    scanf("%d -%d -%d", &i, &j, &k);
    printf("%d -%d -%d\n", i, j, k);

    return 0;
}
