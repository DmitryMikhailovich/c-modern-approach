#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = {"mercury", "venus", "earth",
                        "mars", "jupiter", "saturn",
                        "uranus", "neptune", "pluto"};
    int i, j;

    for(i = 1; i < argc; i++) {
        for(j = 0; j < NUM_PLANETS; j++) {
            int arg_len = strlen(argv[i]);
            char lowered_arg[arg_len+1];
            for(int k = 0; k < arg_len; k++) {
               lowered_arg[k] = tolower(argv[i][k]);
            }
            lowered_arg[arg_len+1] = '\0';
            
            if(strcmp(lowered_arg, planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if(j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}
