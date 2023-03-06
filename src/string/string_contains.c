/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_contains
*/

#include "kapstring.h"

bool str_contains_char(cstring str, char c) {
    return str_index_of_char(str, c) != str_len(str);
}

bool str_contains_string(cstring str, cstring cstr) {
    return str_index_of_string(str, cstr) != str_len(str);
}

bool str_contains_char_from(cstring str, char c, ksize_t from) {
    return str_index_of_char_from(str, c, from) != str_len(str);
}

bool str_contains_string_from(cstring str, cstring cstr, ksize_t from) {
    return str_index_of_string_from(str, cstr, from) != str_len(str);
}

