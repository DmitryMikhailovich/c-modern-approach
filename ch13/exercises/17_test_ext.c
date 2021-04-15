#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool test_extension(const char *file_name, const char *extension); 

int main(void)
{
    if(test_extension("memo.txt", "TXT")) {
        printf("memo.txt has extension TXT\n");
    }

    if(test_extension("memo.doc", "txt")) {
       printf("memo.doc has extension txt\n");
    }
    return 0;
}

bool test_extension(const char *file_name, const char *extension) {
   const char *s = file_name, *e = extension;
   while(*s)
     s++;
   while(*e)
     e++;
   s--; e--;
   while(e >= extension && s >= file_name) {
     if(toupper(*e--) != toupper(*s--))
        return false;
   }

   return true;

} 
