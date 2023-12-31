/*
** KAP PROJECT, 2023
** C Lib
** File description:
** long_to_str
*/

#include "kapstring.h"

string long_int_to_str(const long int nb) {
    string result = str_create_empty();
    long int nb_tmp = nb;
    int i = 0;

    if (nb_tmp == 0) {
        str_add_char(&result, '0');
        return (result);
    }
    if (nb_tmp < 0)
        nb_tmp *= -1;
    for (i = 0; nb_tmp > 0; i++) {
        str_add_char(&result, (nb_tmp % 10) + '0');
        nb_tmp /= 10;
    }
    str_reverse(result);
    if (nb < 0)
        str_add_char_at_begin(&result, '-');
    return (result);
}

string long_long_int_to_str(const long long int nb) {
    string result = str_create_empty();
    long long int nb_tmp = nb;
    int i = 0;

    if (nb_tmp == 0) {
        str_add_char(&result, '0');
        return (result);
    }
    if (nb_tmp < 0)
        nb_tmp *= -1;
    for (i = 0; nb_tmp > 0; i++) {
        str_add_char(&result, (nb_tmp % 10) + '0');
        nb_tmp /= 10;
    }
    str_reverse(result);
    if (nb < 0)
        str_add_char_at_begin(&result, '-');
    return (result);
}

string ulong_int_to_str(const unsigned long int nb) {
    string result = str_create_empty();
    unsigned long int nb_tmp = nb;
    int i = 0;

    if (nb_tmp == 0) {
        str_add_char(&result, '0');
        return (result);
    }
    for (i = 0; nb_tmp > 0; i++) {
        str_add_char(&result, (nb_tmp % 10) + '0');
        nb_tmp /= 10;
    }
    str_reverse(result);
    return (result);
}
