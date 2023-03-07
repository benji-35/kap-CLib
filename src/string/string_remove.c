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
    bool can_remove = false;
    string new_str = str_create_empty();

    for (ksize_t i = 0; i < len; i++) {
        if (i >= index)
            can_remove = true;
        if ((*str)[i] == c && can_remove == true) {
            if (first == true && all == false) {
                str_add_char(&new_str, (*str)[i]);
            }
            first = true;
        } else {
            str_add_char(&new_str, (*str)[i]);
        }
    }
    kapfree(*str);
    *str = new_str;
}

void str_remove_string(string *str, cstring to_remove, bool all) {
    str_remove_string_from(str, to_remove, 0, all);
}

void str_remove_string_from(string *str, cstring to_remove, ksize_t index, bool all) {
    ksize_t len = str_len(*str);
    ksize_t len_to_remove = str_len(to_remove);
    bool first = false;
    bool can_remove = false;
    string new_str = str_create_empty();

    for (ksize_t i = 0; i < len; i++) {
        if (i >= index)
            can_remove = true;
        if (str_start_with_from(*str, to_remove, i) && can_remove == true) {
            if (first == true && all == false) {
                str_add_char(&new_str, (*str)[i]);
            }
            first = true;
            i += len_to_remove - 1;
        } else {
            str_add_char(&new_str, (*str)[i]);
        }
    }
    kapfree(*str);
    *str = new_str;
}

void str_remove_char_at(string *str, ksize_t index) {
    str_remove_char_from(str, (*str)[index], index, false);
}
