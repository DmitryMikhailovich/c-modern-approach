#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    int numbers[] = {7, 11, 15, 19};
    int n;
    
    srand(time(NULL));
    n = numbers[rand() % 4];

    printf("Random number from [7, 11, 15, 19] is %d\n", n);

    return 0;
}
