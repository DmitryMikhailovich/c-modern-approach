#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void remove_filename(char *url);

int main(void)
{
    int n = 50;
    char url[n];

    strcpy(url, "http://google.com/index.html");
    printf("Before remove_filename: %s\n", url);
    remove_filename(url);
    printf("After remove_filename: %s\n", url);
    
    return 0;
}

void remove_filename(char *url) {
  char *c = url;
  while(*c)
    c++;
  while(c > url) {
    if(*c == '/') {
      *c = '\0';
      return;
    }
    c--;
 }
}
