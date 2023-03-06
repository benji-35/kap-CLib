/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_remove
*/

#include "kapstring.h"

void str_remove_char(string *str, char c, bool all) {
    str_remove_char_from(str, c, 0, all);
}

void str_remove_char_from(string *str, char c, ksize_t index, bool all) {
    ksize_t len = str_len(*str);
    bool first = false;
    ksize_t i = index;
    ksize_t j = 0;
    string new_str = str_create_empty();

    while (i < len) {
        if ((*str)[i] != c) {
            str_add_char(&new_str, (*str)[i]);
            j++;
        } else if (first == false && all == false) {
            str_add_char(&new_str, (*str)[i]);
            first = true;
            j++;
        }
        i++;
    }
    free(*str);
    *str = new_str;
}

void str_remove_string(string *str, cstring to_remove, bool all) {
    str_remove_string_from(str, to_remove, 0, all);
}

void str_remove_string_from(string *str, cstring to_remove, ksize_t index, bool all) {
    ksize_t len = str_len(*str);
    ksize_t to_remove_len = str_len(to_remove);
    bool first = false;
    ksize_t i = index;
    ksize_t j = 0;
    string new_str = str_create_empty();

    while (i < len) {
        if (str_is_equal_from(*str, to_remove, i, true) == false) {
            str_add_char(&new_str, (*str)[i]);
            j++;
        } else if (first == false && all == false) {
            str_add_char(&new_str, (*str)[i]);
            first = true;
            j++;
        }
        i += to_remove_len;
    }
    free(*str);
    *str = new_str;
}
