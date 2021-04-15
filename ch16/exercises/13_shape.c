#include <stdio.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point { int x, y; };

int main(void) {
    struct shape {
        int shape_kind;
        struct point center;
        union {
            struct {
                int height, width;
            } rectangle;
            struct {
                int radius;
            } circle;
        } u;
    } s;
    
    s.shape_kind = RECTANGLE;
    s.center.x = 10;
    s.u.rectangle.height = 25;
    s.u.rectangle.width = 8;    
    s.shape_kind = CIRCLE;
    s.u.circle.radius = 5;

    return 0;
}
