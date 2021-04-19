#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *mystrdup(const char *s);
int mystricmp(const char *s1, const char *s2);
char *mystrlwr(char *s);
char *mystrrev(char *s);
char *mystrset(char *s, int ch);

int main(void) {
    char s[50], *s2;
    int ch;

    strcpy(s, "some string");
    printf("Address of string \"%s\": %p; address of a copy: %p\n", s, s, mystrdup(s));

    strcpy(s, "string");
    s2 = "String";
    printf("mystricmp(\"%s\", \"%s\") == %d\n", s, s2, mystricmp(s, s2));

    strcpy(s, "STRING");
    printf("mystrlwr(\"%s\") == \"%s\"\n", s, mystrlwr(s));

    printf("mystrrev(\"%s\") == \"%s\"\n", s, mystrrev(s));

    ch = 'x';
    printf("mystrset(\"%s\", '%c') == ", s, ch);
    printf("\"%s\"\n", mystrset(s, ch));

    return 0;
}
    
char *mystrdup(const char *s) {
    char *sc = malloc(sizeof(s));
    if(sc != NULL)
        strcpy(sc, s);
    return sc;
}

int mystricmp(const char *s1, const char *s2) {
    int len = strlen(s1);

    if(strlen(s2) > len)
        len = strlen(s2);
    for(int i = 0; i < len; i++) {
        if(tolower(s1[i]) < tolower(s2[i]))
            return -1;
        if(tolower(s1[i]) > tolower(s2[i]))
            return 1;
    }

    return 0;
}
char *mystrlwr(char *s) {
    char *sc = s;
    while(*sc != '\0') {
        if(isupper(*sc))
            *sc = tolower(*sc);
        sc++;
    }
    return s;
}

char *mystrrev(char *s) {
    char ch;
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        ch = s[len - 1 - i];
        s[len - 1 - i] = s[i];
        s[i] = ch;
    }
    return s;
}

char *mystrset(char *s, int ch) {
    char *sc = s;
    while(*sc != '\0') {
        *sc = ch;
        sc++;
    }
    return s;
}
