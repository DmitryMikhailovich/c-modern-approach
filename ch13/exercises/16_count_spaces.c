#include <stdio.h>

int count_spaces(const char *s);

int main(void)
{
    printf("count spaces: %d\n", count_spaces("Hello world over there"));
    return 0;
}

int count_spaces(const char *s) {
  int count = 0;
  
  while(*s) {
    if(*s == ' ')
      count++;
    s++;
  }
  return count;
}
