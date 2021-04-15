#include <stdio.h>

int main(void) {
    char *str;
    char *sales_rank;
    str = "asdf #989 abc";
    sscanf(str, " %*[^#]#%[,0123456789,]", sales_rank);

    printf("str=%s, sales_rank=%s\n", str, sales_rank);

    str = "asdf #24,675 abc";
    sscanf(str, " %*[^#]#%[,0123456789,]", sales_rank);

    printf("str=%s, sales_rank=%s\n", str, sales_rank);

    str = "asdf #1,162,620   abc";
    sscanf(str, " %*[^#]#%[,0123456789,]", sales_rank);

    printf("str=%s, sales_rank=%s\n", str, sales_rank);

    return 0;
}
