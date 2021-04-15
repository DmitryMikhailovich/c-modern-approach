#include <stdio.h>
#include <string.h>

#define CONCAT(x,y) x##y
#define STRINGIZE(x) #x
#define LINE_FILE line_file(CONCAT(__LI,NE__)) 

char* line_file(int line) {
    char a[100];
    char *p = a; 
    sprintf(p, "Line %d of file %s", line, __FILE__); 
    return p;
}


//#define LINE_FILE "Line CONCAT(__LI,NE__) of file CONCAT(__FI,LE__)"

int main (void) {

    const char *str = LINE_FILE;
    printf(str);
    printf("\n");

    return 0;
}
