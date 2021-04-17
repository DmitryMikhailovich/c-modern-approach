#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *fp;
    int region_code, first_num, second_num;
    int matches, line;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) != NULL) {
        line = 1;
        while(1) {
            matches = 0;
            fscanf(fp, "%*[ (]");
            matches += fscanf(fp, "%3d", &region_code);
            fscanf(fp, "%*[ ).-]");
            matches += fscanf(fp, "%3d", &first_num);
            fscanf(fp, "%*[ .-]");
            matches += fscanf(fp, "%4d\n", &second_num);
            if(matches != 3) {
                fprintf(stderr, "Failed to match all arguments. Expected 3, actual %d on line %d\n", matches, line);
                exit(EXIT_FAILURE);
            }
            printf("(%3d)%4d-%4d\n", region_code, first_num, second_num);
            line++;
            if(feof(fp)) {
                break;
            }
        }

        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
