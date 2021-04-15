#include <stdio.h>
#include <stdlib.h>

#define COUNTRY_COUNT ((int) (sizeof(country_codes) / sizeof(country_codes[0])))

struct dialing_code {
    char *country;
    int code;
};

int main(void) {
    const struct dialing_code country_codes[] = 
    {{"Argentina", 54}, {"Bangladesh", 880}
    }; 
    struct dialing_code dc;
    int i;
    int code;

    printf("Enter an international dialing code: ");
    scanf(" %d", &code);
    for(i = 0; i < COUNTRY_COUNT; i++) {
       dc = country_codes[i];
        if(code == dc.code) {
            printf("Code %d is for %s\n", code, dc.country);
            exit(0);
        }
    }
    printf("Code %d not found\n", code); 
    return 0;
}
