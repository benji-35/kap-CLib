/*
** KAP PROJECT, 2023
** C Lib
** File description:
** int_to_string
*/

#include "kaptools.h"
#include "kapstring.h"
#include "kapmemory.h"

static ksize_t size_nb(int nb)
{
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

string int_to_str(int nb) {
    bool is_neg = false;
    ksize_t size = size_nb(nb);
    string result = str_create_empty();

    if (nb < 0) {
        is_neg = true;
        nb = ABS(nb);
    }
    if (nb == 0) {
        kfree(result);
        return (str_create_char('0'));
    }
    for (ksize_t i = size - 1; i >= 0; i--) {
        str_add_char(&result, (nb % 10) + 48);
        nb = nb / 10;
    }
    if (is_neg)
        str_add_char_from(&result, '-', 0);
    return (result);
}

string int_to_hex(int nb) {
    string result = str_create_empty();
    int i = 0;
    int base = 16;

    if (nb <= 0) {
        kfree(result);
        return (str_create_char('0'));
    }
    for (i = 0; base > 0; i++) {
        if (nb >= base) {
            str_add_char(&result, (nb / base) + 48);
            nb -= base;
        } else
            str_add_char(&result, '0');
        base /= 16;
    }
    return (result);
}
