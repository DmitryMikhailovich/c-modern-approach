#include <stdio.h>

struct fraction {
    int numerator, denominator;
};

struct fraction reduce(struct fraction f);
int gcd(int x, int y);
struct fraction add(struct fraction f1, struct fraction f2);
struct fraction subtract(struct fraction f1, struct fraction f2);
struct fraction multiply(struct fraction f1, struct fraction f2);
struct fraction divide(struct fraction f1, struct fraction f2);

int main (void) {
    struct fraction f1 = {15, 20};
    struct fraction f2 = {13, 28};

    struct fraction res;

    res = reduce(f1);
    printf("%d/%d reduced to %d/%d\n", f1.numerator, f1.denominator, res.numerator, res.denominator);
    
    res = add(f1, f2);
    printf("%d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, res.numerator, res.denominator);

    res = subtract(f1, f2);
    printf("%d/%d - %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, res.numerator, res.denominator);

    res = multiply(f1, f2);
    printf("%d/%d * %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, res.numerator, res.denominator);

    res = divide(f1, f2);
    printf("%d/%d / %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, res.numerator, res.denominator);
    return 0;
}
struct fraction reduce(struct fraction f) {
    struct fraction res = f;
    int gcd_ = gcd(res.numerator, res.denominator);
    res.numerator = res.numerator / gcd_;
    res.denominator = res.denominator / gcd_;

    return res;
}

int gcd(int x, int y) {

    if(y == 0) return x;
    return gcd(y, x%y);
}

struct fraction add(struct fraction f1, struct fraction f2) {
    struct fraction res = {f1.numerator*f2.denominator + f2.numerator*f1.denominator, 
        f1.denominator*f2.denominator};
    
    return reduce(res);
}

struct fraction subtract(struct fraction f1, struct fraction f2) {
    struct fraction res = {f1.numerator*f2.denominator - f2.numerator*f1.denominator, 
        f1.denominator*f2.denominator};

    return reduce(res);
}

struct fraction multiply(struct fraction f1, struct fraction f2) {
    struct fraction res = {f1.numerator*f2.numerator, f1.denominator*f2.denominator};
    
    return reduce(res);
}
struct fraction divide(struct fraction f1, struct fraction f2) {
    struct fraction res = {f1.numerator*f2.denominator, f1.denominator* f2.numerator};

    return reduce(res);
}
