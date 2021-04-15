#include <stdio.h>

#define CHECK(x,y,n) (((x)>=0&&(x)<=(n)-1)&&((y)>=0&&(y)<=(n)-1)) ? 1 : 0
#define MEDIAN(x,y,z)  ( (x)>(y) ? \
  (x)>(z) ? \
    (z) > (y) ? (z) : (y) \
   : (x) \
  : (y) > (z) ? \
       (z) > (x) ? (z) : (x) \
   : (y) )
#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x) + 2*(x)*(x)*(x)*(x) \
- 5*(x)*(x)*(x) - (x)*(x) + 7*(x)-6)

int main(void) {

    printf("CHECK(%d,%d,%d) = %d\n", 2, 4, 10, CHECK(2,4,10));
    printf("MEDIAN(%d,%d,%d) = %d\n", 4, 5, 2, MEDIAN(4,5,2));
    printf("POLYNOMIAL(%d) = %d\n", 4, POLYNOMIAL(4));

    return 0;
}
