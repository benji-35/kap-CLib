/*
** KAP PROJECT, 2023
** C Lib
** File description:
** int_to_bin
*/

#include "kaptools.h"
#include "kapstring.h"
#include <stdio.h>

private int get_max_bin_num(const int nb) {
    int base = 2;

    while (base <= nb)
        base *= 2;
    return (base);
}

string int_to_bin(const int nb) {
    string result = str_create_empty();
    int nb_tmp = nb;
    int i = 0;
    int base = get_max_bin_num(nb);

    if (nb_tmp <= 0) {
        kfree(result);
        return (str_create_char('0'));
    }
    for (i = 0; base > 0; i++) {
        if (nb_tmp >= base) {
            str_add_char(&result, '1');
            nb_tmp -= base;
        } else
            str_add_char(&result, '0');
        base /= 2;
    }
    if (str_start_with(result, "0") && str_len(result) > 1) {
        str_remove_char_at(&result, 0);
    }
    return (result);
}
