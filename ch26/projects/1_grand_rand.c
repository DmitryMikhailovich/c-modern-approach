#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    for (int i = 0; i < 1000; i++) 
        printf("%d", rand() % 2 == 0 ? 0 : 1);

    putchar('\n');

    printf("With improved randomness:\n");
    for (int i = 0; i < 1000; i++) 
        printf("%d", rand()  / (RAND_MAX / 2));

    putchar('\n');
    return 0;
}
