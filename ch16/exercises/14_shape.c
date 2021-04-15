#include <stdio.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point {
    int x, y;
};

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
};

int area(struct shape s);
struct shape move(struct shape s, int dx, int dy);
struct shape scale(struct shape s, double c);

int main(void) {
    struct shape s = {CIRCLE, {5, 2}, {{5}}};
    printf("Area of circle with radius %d is %d\n", s.u.circle.radius, area(s));
    
    struct shape ns = move(scale(s, 2.1), 3, -2);
    printf("New coordinates of shape: (%d, %d), new radius: %d\n", ns.center.x, ns.center.y,
        ns.u.circle.radius);
    return 0;
}

int area(struct shape s) {
   if(s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
   else if(s.shape_kind == CIRCLE)
        return s.u.circle.radius * s.u.circle.radius * 3.1415; 
    else
        return -1;
}

struct shape move(struct shape s, int dx, int dy) {
    struct shape ns = s;
    ns.center.x += dx;
    ns.center.y += dy;
    return ns;
}

struct shape scale(struct shape s, double c) {
    struct shape ns = s;
    if(ns.shape_kind == RECTANGLE) {
        ns.u.rectangle.height = (int) ns.u.rectangle.height * c;   
        ns.u.rectangle.width = (int) ns.u.rectangle.width * c;   
    } else if(ns.shape_kind == CIRCLE) {
        ns.u.circle.radius = (int) ns.u.circle.radius * c;
    }
    return ns;
}
