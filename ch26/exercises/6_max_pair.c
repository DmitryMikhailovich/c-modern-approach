#include <stdarg.h>
#include <stdio.h>


struct pair {
    int key;
    char *value;
};

char *max_pair(int num_pairs, ...);

int main(void) {

    printf("%s\n", max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
                               39, "The Honeymooners", 210, "All in the Family",
                               86, "The Sopranos"));

    return 0;
}

char *max_pair(int num_pairs, ...) {
    struct pair pairs[num_pairs];
    struct pair *max_pair = &pairs[0];
    va_list ap;

    va_start(ap, num_pairs);
    for(int i = 0; i < num_pairs; i++) {
        pairs[i].key = va_arg(ap, int);
        pairs[i].value = va_arg(ap, char *);
        if(max_pair->key < pairs[i].key)
            max_pair = &pairs[i];
    }

    
    return max_pair->value;
}
