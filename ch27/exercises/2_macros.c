#include <stdio.h>

#define INT32_C(n) n##L
#define UINT32_C(n) n##UL
#define INT64_C(n) n##LL
#define UINT64_C(n) n##ULL

int main(void) {
    printf("INT32_C(5) = %ld\n", INT32_C(5));
    printf("UINT32_C(5) = %lu\n", UINT32_C(5));
    printf("INT64_C(5) = %lld\n", INT64_C(5));
    printf("UINT64_C(5) = %llu\n", UINT64_C(5));

    return 0;
}
