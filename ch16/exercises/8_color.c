#include <stdio.h>

struct color {
    int red, green, blue;
};

const struct color MAGENTA = {255, 0, 255};
const struct color MAGENTA_99 = {255, .blue=255};

int main(void) {

    return 0;
}
