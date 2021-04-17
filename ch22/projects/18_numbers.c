#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10000

int compar(const void * a, const void * b);

int main(int argc, char *argv[]) {
    FILE *fp;
    int numbers[ARR_SIZE], largest, smallest, median, i, num_elements;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) != NULL) {
        for(i = 0; i < 10000; i++) {
            if(fscanf(fp, " %d", &numbers[i]) != 1) {
                break;
            }
            if(feof(fp)) {
                break;
            }
        }
        num_elements = i;
        qsort(numbers, num_elements, sizeof(int), compar);
        smallest = numbers[0];
        largest = numbers[num_elements-1];
        if(num_elements % 2 == 1) {
            median = numbers[num_elements / 2];
        } else {
            median = (numbers[num_elements / 2 - 1] + numbers[num_elements / 2] ) / 2;
        }
        printf("Total numbers: %d, smallest: %d, largest: %d, median: %d\n", num_elements, smallest, largest, median);

        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}

int compar(const void * a, const void * b) {
    if(*((int *) a) < *((int *) b)) {
        return -1;
    } else if(*((int *) a) > *((int *) b)) {
        return 1;
    } else {
        return 0;
    }
}
