#include <stdio.h>
#include <complex.h>

int main(void) {
    int n;

    printf("n=");
    scanf("%d", &n);

    for(int k = 0; k < n; k++) {
        printf("k=%d, root of unity=%g\n", k, cexp(2*PI*I*k/n));
    }

    return 0;
}
