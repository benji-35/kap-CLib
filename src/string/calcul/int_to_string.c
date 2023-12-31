/*
** KAP PROJECT, 2023
** C Lib
** File description:
** int_to_string
*/

#include "kaptools.h"
#include "kapstring.h"
#include "kapmemory.h"
#include "kapmath.h"

string int_to_str(const int nb) {
    string result = str_create_empty();
    int nb_tmp = nb;
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
