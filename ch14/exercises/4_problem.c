#include <stdio.h>

#define AVG(x,y) ((x-y)/2)
#define AREA(x,y) ((x)*(y))


int main(void) {

   printf("2/AVG(5,3) should be 2, actual: %d\n", 2/AVG(5,3));
   printf("20/AREA(5,2) should be 2, actual: %d\n", 20/AREA(5,2));
   return 0;
}
