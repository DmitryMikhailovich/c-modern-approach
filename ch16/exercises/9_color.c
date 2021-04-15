#include <stdio.h>
#include <stdbool.h>

struct color {
    int red, green, blue;
};

struct color make_color(int red, int green, int blue);
int get_red(struct color c);
bool equal_color(struct color c1, struct color c2);
struct color brighter(struct color c);
struct color darker(struct color c);

const struct color MAGENTA = {255, 0, 255};
const struct color MAGENTA_99 = {255, .blue=255};

int main(void) {
    struct color c = make_color(-1, 23, 256);
    struct color res;
    printf("color(%d, %d, %d)\n", c.red, c.green, c.blue);

    res = brighter(c);
    printf("brighter: color(%d, %d, %d)\n", res.red, res.green, res.blue);
    res = darker(c);
    printf("darker: color(%d, %d, %d)\n", res.red, res.green, res.blue);
    return 0;
}


struct color make_color(int red, int green, int blue) {
    struct color r = {red, green, blue};
    r.red = r.red < 0 ? 0 : (r.red > 255 ? 255 : r.red);
    r.green = r.green < 0 ? 0 : (r.green > 255 ? 255 : r.green);
    r.blue = r.blue < 0 ? 0 : (r.blue > 255 ? 255 : r.blue);
    return r;
}

int get_red(struct color c) {
    return c.red;
}

bool equal_color(struct color c1, struct color c2) {
    return c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue;
}

struct color brighter(struct color c) {
    struct color res;
    if (c.red == 0 && c.blue == 0 && c.green == 0) {
        res.red = 3;
        res.green = 3;
        res.blue = 3;
    } else {
        if (c.red > 0 && c.red < 3)
            c.red = 3;
        if (c.green > 0 && c.green < 3)
            c.green = 3;
        if (c.blue > 0 && c.blue < 3)
            c.blue = 3;
        res.red = c.red / 0.7;
        res.green = c.green / 0.7;
        res.blue = c.blue / 0.7;
        if (res.red > 255)
            res.red = 255;
        if (res.green > 255)
            res.green = 255;
        if (res.blue > 255)
            res.blue = 255;
    }
    return res;
}
 
struct color darker(struct color c) {
    struct color res;
        if (c.red > 0 && c.red < 3)
            c.red = 3;
        if (c.green > 0 && c.green < 3)
            c.green = 3;
        if (c.blue > 0 && c.blue < 3)
            c.blue = 3;
        res.red = c.red * 0.7;
        res.green = c.green * 0.7;
        res.blue = c.blue * 0.7;
        if (res.red > 255)
            res.red = 255;
        if (res.green > 255)
            res.green = 255;
        if (res.blue > 255)
            res.blue = 255;
    return res;

}
