#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 50

void reverse_name(char *name);
int read_line(char str[], int n);

int main(void) 
{
    char name[N+1];
    printf("Enter a first and last name: ");
    read_line(name, N);
    reverse_name(name);
    printf("Reversed name: %s\n", name);
    return 0;
}


void reverse_name(char *name) {
    char rev_name[N+1];
    char *p = name;
    char *r = rev_name;
    char first_initial, ch;
    _Bool last_name_found = 0;

    while(*p == ' ')
      p++;
    first_initial = toupper(*p++);
    while((ch = *p++)) {
        if(last_name_found) { 
            *r++ = ch; 
            continue;
        }
        last_name_found = ch == ' ';
    }
    *r++ = ',';
    *r++ = ' ';
    *r++ = first_initial;
    *r++ = '.';
    *r = '\0';
    
    strcpy(name, rev_name);

}

int read_line(char str[], int n) {
  int ch, i = 0;
  while((ch = getchar()) != '\n')
   if(i < n)
     str[i++] = ch;
  str[i] = '\0';
  return i;
}
