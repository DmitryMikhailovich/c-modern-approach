??=include <ctype.h>
??=include <stdio.h>

??=define KEY 'c'

int main(void) ??<
    char orig_char, new_char;

    while((orig_char = getchar()) != EOF) ??<
        new_char = orig_char ??' KEY;
        if (isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    ??>

    return 0;
??>
