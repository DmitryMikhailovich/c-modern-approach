#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    char *locale_name;
    struct lconv *locale_info;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s locale\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((setlocale(LC_ALL, locale_name)) == NULL) {
        printf("Failed to get info on locale %s\n", locale_name);
        exit(EXIT_FAILURE);
    }
     
    locale_info = localeconv(); 
    printf("decimal_point = \"%s\"\n", locale_info->decimal_point);
    printf("thousands_sep = \"%s\"\n", locale_info->thousands_sep);
    printf("grouping = %s\n", locale_info->grouping);
    printf("mon_decimal_point = \"%s\"\n", locale_info->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", locale_info->mon_thousands_sep);
    printf("mon_grouping = %s\n", locale_info->mon_grouping);
    printf("positive_sign = \"%s\"\n", locale_info->positive_sign);
    printf("negative_sign = \"%s\"\n", locale_info->negative_sign);
    printf("currency_symbol = \"%s\"\n", locale_info->currency_symbol);
    printf("frac_digits = %c\n", locale_info->frac_digits);
    printf("p_cs_precedes = %c\n", locale_info->p_cs_precedes);
    printf("n_cs_precedes = %c\n", locale_info->n_cs_precedes);
    printf("p_sep_by_space = %c\n", locale_info->p_sep_by_space);
    printf("n_sep_by_space = %c\n", locale_info->n_sep_by_space);
    printf("p_sign_posn = %c\n", locale_info->p_sign_posn);
    printf("n_sign_posn = %c\n", locale_info->n_sign_posn);
    printf("int_curr_symbol = \"%s\"\n", locale_info->int_curr_symbol);
    printf("int_frac_digits = %c\n", locale_info->int_frac_digits);
    printf("int_p_cs_precedes = %c\n", locale_info->int_p_cs_precedes);
    printf("int_n_cs_precedes = %c\n", locale_info->int_n_cs_precedes);
    printf("int_p_sep_by_space = %c\n", locale_info->int_p_sep_by_space);
    printf("int_n_sep_by_space = %c\n", locale_info->int_n_sep_by_space);
    printf("int_p_sign_posn = %c\n", locale_info->int_p_sign_posn);
    printf("int_n_sign_posn = %c\n", locale_info->int_n_sign_posn);

    return 0;
}
