#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} part;


int main(int argc, char *argv[]) {
    FILE *fp1, *fp2, *fpo;
    int num_parts1, num_parts2, i1 = 0, i2 = 0;
    part inv1[MAX_PARTS], inv2[MAX_PARTS];
    part current;
    part item_arr[1];

    if(argc != 4) {
        fprintf(stderr, "Usage: %s inputfile1 inputfile2 outputfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp1 = fopen(argv[1], "rb")) != NULL &&
        (fp2 = fopen(argv[2], "rb")) != NULL &&
        (fpo = fopen(argv[3], "wb")) != NULL) {

        num_parts1 = fread(inv1, sizeof(part), MAX_PARTS, fp1);
        num_parts2 = fread(inv2, sizeof(part), MAX_PARTS, fp2);
        if(ferror(fp1)) {
            fprintf(stderr, "Failed to read from %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if(ferror(fp2)) {
            fprintf(stderr, "Failed to read from %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        for(int i = 0; i < num_parts1 + num_parts2; i++) {
            if(i1 == num_parts1 - 1) {
                current = inv2[i2++];
            } else if(i2 == num_parts2 - 1) {
                current = inv1[i1++];
            } else if(inv1[i1].number < inv2[i2].number) {
                current = inv1[i1++];
            } else if(inv1[i1].number > inv2[i2].number) {
                current = inv2[i2++];
            } else {
                current = inv1[i1++];
                if(current.name != inv2[i2].name) {
                    fprintf(stderr, "Names of part #%d does not match: '%s' and '%s'\n",
                            current.number, current.name, inv2[i2].name); 
                    exit(EXIT_FAILURE);
                }
                current.on_hand += inv2[i2++].on_hand;
            }
            item_arr[0] = current; 
            fwrite(item_arr, sizeof(part), 1, fpo); 

        }

        fclose(fp1);
        fclose(fp2);
        fclose(fpo);
    } else {
        fprintf(stderr, "Failed to open one of files\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
