#include <stdio.h>

#define FRENCH

int main(void) {

    char *p;
    #ifdef ENGLISH
        p = "Insert Disk 1";
   #elif defined FRENCH
        p = "Inserez Le Disque 1"; 
    #elif defined SPANISH
        p = "Inserte El Disco 1";
    #else
        p = "Language is not defined";
    #endif 

    printf(p);
    printf("\n");
    return 0;
}
