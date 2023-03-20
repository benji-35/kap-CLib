/*
** KAP PROJECT, 2023
** C Lib
** File description:
** str_substring
*/

#include "kapstring.h"

string str_substring(cstring str, ksize_t from, ksize_t to) {
    string new = str_create_empty();
    ksize_t len = str_len(str);

    if (from > len || from > to) {
        kfree(new);
        return NULL;
    }
    if (to > len)
        to = len;
    for (ksize_t i = from; i <= to; i++)
        str_add_char(&new, str[i]);
    return new;
}

string str_substring_from(cstring str, ksize_t from) {
    return str_substring(str, from, str_len(str) - 1);
}

string str_substring_size(cstring str, ksize_t from, ksize_t size) {
    return str_substring(str, from, from + (size - 1));
}
