#include <stdio.h>

typedef struct {double real, imaginary; } complex;

complex make_complex(double real, double imaginary);
complex add_complex(complex c1, complex c2);

int main(void) {


    complex c1, c2, c3;
    c1 = make_complex(1.1, 2.0);
    c2 = make_complex(2.4, 4.4);
    c3 = add_complex(c1, c2);

    printf("%f%+fi\n", c3.real, c3.imaginary);    

    return 0;
}


complex make_complex(double real, double imaginary) {
    complex s = { real, imaginary };
    return s;
}


complex add_complex(complex c1, complex c2) {
    complex s = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return s;
}
