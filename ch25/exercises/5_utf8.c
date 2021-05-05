#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "en_US.UTF8");

    printf("C\xc3\xf4te d'Azur\n");
    printf("cr\xc3\xe8me br\xc3\xfbl\xc3\xe9e\n");
    printf("cr\xc3\xe8me fra\xc3\xeeche\n");
    printf("Fahrvergn\xc3\xfcgen\n");
    printf("t\xc3\xeate-\xc3\xe0-t\xc3\xeate\n");
    return 0;
}
