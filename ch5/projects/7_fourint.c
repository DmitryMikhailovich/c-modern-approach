#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, s, l, s1, l1, s2, l2;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
    if (i1 > i2) {
        s1 = i2;
        l1 = i1;
    } else {
        s1 = i1;
        l1 = i2;
    }
    if (i3 > i4) {
        s2 = i4;
        l2 = i3; 
    } else {
        s2 = i3;
        l2 = i4;
    }
    if (s1 > s2) 
        s = s2;
    else
        s = s1;
    if (l1 > l2)
        l = l1;
    else
        l = l2;
    printf("Largest: %d\n", l);
    printf("Smallest: %d\n", s);
    return 0;
}
