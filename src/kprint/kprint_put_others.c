/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kprint_put_others
*/

#include "kapprintf.h"

void kap_put_hex_low(int fd, va_list *data) {
    int nb = va_arg(*data, int);
    string str = int_to_hex(nb);

    str_to_lower(str);
    kprint_string(str, fd, 0);
    kfree(str);
}
