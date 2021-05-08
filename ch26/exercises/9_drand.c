#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double drand(void);

int main(void) {

    srand(time(NULL));

    printf("Random double: %f\n", drand());

    return 0;
}

double drand(void) {
    return rand() / (double) ((long int) RAND_MAX + 1);
}
