#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    printf("a. %" PRId8 "\n", INT8_C(5)); 
    printf("b. %12.4" PRId32 "\n", INT32_C(5)); 
    printf("c. %-6" PRIo16 "\n", UINT16_C(5)); 
    printf("d. %#" PRIx64 "\n", UINT64_C(5)); 

    return 0;
}
