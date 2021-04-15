#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int month, day, year;
    char *months[] = {"January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November",
        "December"};

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], " %d%*[-/]%d%*[-/]%d", &month, &day, &year);
    
    printf("%s %d, %d\n", months[month-1], day, year);

    return 0;
}
