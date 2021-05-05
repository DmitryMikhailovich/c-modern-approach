#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "en_US.iso88591");

    printf("C\xf4te d'Azur\n");
    printf("cr\xe8me br\xfbl\xe9e\n");
    printf("cr\xe8me fra\xeeche\n");
    printf("Fahrvergn\xfcgen\n");
    printf("t\xeate-\xe0-t\xeate\n");
    return 0;
}
