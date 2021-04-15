#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

int area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int dx, int dy);
bool is_within(struct point p, struct rectangle r);

int main(void) {
    struct point p = {10, 20};
    struct rectangle r = {{0, 30}, {40, 5}};
    struct point resp;
    struct rectangle resr;
    
    printf("point(%d, %d)\n", p.x, p.y);
    printf("rectangle((%d, %d), (%d, %d))\n", r.upper_left.x, r.upper_left.y,
        r.lower_right.x, r.lower_right.y);

    printf("area: %d\n", area(r));

    resp = center(r);
    printf("center: point(%d, %d)\n", resp.x, resp.y);

    resr = move(r, 1, 1);
    printf("move by (1, 1): rectangle((%d, %d), (%d, %d))\n", resr.upper_left.x, 
        resr.upper_left.y, resr.lower_right.x, resr.lower_right.y);

    printf("is within: %d\n", is_within(p, r)); 
    return 0;
}

int area(struct rectangle r) {
    return (int) fabs((r.upper_left.x - r.lower_right.x) * (r.upper_left.y - r.lower_right.y));
}

struct point center(struct rectangle r) {
    struct point c;
    c.x = r.lower_right.x + (r.upper_left.x - r.lower_right.x)/2;
    c.y = r.upper_left.y + (r.lower_right.y - r.upper_left.y)/2;
    return c;
}

struct rectangle move(struct rectangle r, int dx, int dy) {
    r.upper_left.x += dx;
    r.lower_right.x += dx;
    r.upper_left.y += dy;
    r.lower_right.y += dy;
    return r;
}

bool is_within(struct point p, struct rectangle r) {
    return p.x >= r.upper_left.x && p.x <= r.lower_right.x 
        && p.y >= r.lower_right.y && p.y <= r.upper_left.y;
}
