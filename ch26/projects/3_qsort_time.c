#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int compar(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

#define S 1000
#define M 10000
#define L 100000

int main(void) {
    int s_array[S],
        m_array[M],
        l_array[L];
    clock_t start_clock;

    for (int i = S-1; i >= 0; i--)
        s_array[i] = i;
    for (int i = M-1; i >= 0; i--)
        m_array[i] = i;
    for (int i = L-1; i >= 0; i--)
        l_array[i] = i;

    printf("Time of sorting arrays of integers in reverse order\n");
    printf("#Elements     Seconds\n");
    printf("---------     -------\n");

    start_clock = clock(); 
    qsort(s_array, S, sizeof(int), compar);
    printf("%-14d%-.3f\n", S, (clock() - start_clock) / (double) CLOCKS_PER_SEC); 

    start_clock = clock(); 
    qsort(m_array, M, sizeof(int), compar);
    printf("%-14d%-.3f\n", M, (clock() - start_clock) / (double) CLOCKS_PER_SEC); 

    start_clock = clock(); 
    qsort(l_array, L, sizeof(int), compar);
    printf("%-14d%-.3f\n", L, (clock() - start_clock) / (double) CLOCKS_PER_SEC); 

    return 0;
}
