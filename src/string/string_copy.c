/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_copy
*/

#include "kapstring.h"

string str_copy(cstring src) {
    return str_copy_from_to(src, 0, str_len(src));
}

string str_copy_to(string dest, cstring src) {
    dest = str_copy(src);
    return dest;
}

string str_copy_from_to(cstring src, ksize_t from, ksize_t to) {
    string new_string = str_create_empty();
    
    if (src == NULL) {
        kfree(new_string);
        return NULL;
    }
    if (from > to || from >= str_len(src)) {
        kfree(new_string);
        return NULL;
    }
    if (to >= str_len(src))
        to = str_len(src) - 1;
    for (ksize_t i = from; i <= to; i++)
        str_add_char(&new_string, src[i]);
    return new_string;
}
