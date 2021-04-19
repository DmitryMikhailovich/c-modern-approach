#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool iscidentifier(const char * s);

int main(void) {
    char *s[] = {"variable", "$variable", "variable_1", "varIaBLe$$$"};

    for(int i = 0; i < 4; i++) {

        printf("'%s' is%s a C identifier\n", s[i], iscidentifier(s[i]) ? "" : " not");
    }

    return 0;
}

bool iscidentifier(const char * s) {
    bool result = true;
    for(int i = 0; i < strlen(s); i++) {
        if(i == 0) 
            result = result && (isalpha(s[i]) || s[i] == '_');
        else
            result = result && (isalnum(s[i]) || s[i] == '_');
    }

    return result;
}

