/*
** KAP PROJECT, 2023
** C Lib
** File description:
** int_to_hex
*/

#include "kapstring.h"
#include "kapmath.h"

#include <stdio.h>

private void check_bin_format(string *bin) {
    int len = str_len(*bin);
    int i = 0;

    if (len % 4 != 0) {
        int nb = 4 - (len % 4);
        for (i = 0; i < nb; i++)
            str_add_char_from(bin, '0', 0);
    }
}

string bin_to_hex(cstring bin) {
    string _bin = str_copy(bin);
    string hex = str_create_empty();
    int i = 0;
    int j = 0;
    int nb = 0;

    check_bin_format(&_bin);
    for (ksize_t i = 0; i < str_len(_bin); i += 4) {
        nb = 0;
        for (j = 0; j < 4; j++)
            nb += (_bin[i + j] - '0') * power(2, 3 - j);
        if (nb < 10)
            str_add_char(&hex, nb + '0');
        else
            str_add_char(&hex, nb + 'A' - 10);
    }
    kfree(_bin);
    return hex;
}

string int_to_hex(const int nb) {
    string bin = int_to_bin(nb);
    string hex = bin_to_hex(bin);

    kfree(bin);
    return hex;
}
