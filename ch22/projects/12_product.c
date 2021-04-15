#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fd;
    int num, day, month, year;
    float price;
    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fd = fopen(argv[1], "rb")) != NULL) {
        printf("Item\tUnit\tPurchase\n");
        printf("\tPrice\tDate\n");
        while(1) {
            if(5 != fscanf(fd, "%d,%f,%d/%d/%4d\n", &num, &price, &month, &day, &year)) {
                break;
            }
            printf("%d\t$%7.2f\t%02d/%02d/%04d\n", num, price, month, day, year);
        }

    }

    return 0;
}
