#include <stdio.h>

struct complex {double real, imaginary; };

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex c1, struct complex c2);

int main(void) {


    struct complex c1, c2, c3;
    c1 = make_complex(1.1, 2.0);
    c2 = make_complex(2.4, 4.4);
    c3 = add_complex(c1, c2);

    printf("%f%+fi\n", c3.real, c3.imaginary);    

    return 0;
}


struct complex make_complex(double real, double imaginary) {
    struct complex s = { real, imaginary };
    return s;
}


struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex s = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return s;
}
