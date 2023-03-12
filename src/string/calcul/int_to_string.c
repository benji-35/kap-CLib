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

private ksize_t size_nb(int nb) {
    ksize_t r = 0;

    nb = ABS(nb);
    if (nb == 0)
        return (1);
    while (nb > 0) {
        r++;
        nb = nb / 10;
    }
    return (r);
}

string int_to_str(const int nb) {
    bool is_neg = false;
    ksize_t size = size_nb(nb);
    string result = str_create_empty();
    int nb_tmp = nb;

    if (nb_tmp < 0) {
        is_neg = true;
        nb_tmp = ABS(nb_tmp);
    }
    if (nb_tmp == 0) {
        kfree(result);
        return (str_create_char('0'));
    }
    for (ksize_t i = size - 1; i > 0; i--) {
        str_add_char(&result, (nb_tmp % 10) + 48);
        nb_tmp = nb_tmp / 10;
    }
    if (is_neg)
        str_add_char_from(&result, '-', 0);
    return (result);
}
