/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_last_index_of
*/

#include "kapstring.h"

ksize_t str_last_index_of_char(cstring str, char c) {
    ksize_t last_good = str_index_of_char(str, c);
    ksize_t tmp_good = 0;

    while (last_good < str_len(str)) {
        tmp_good = str_index_of_char_from(str, c, last_good + 1);
        if (tmp_good == str_len(str))
            break;
        last_good = tmp_good;
    }
    return last_good;
}

ksize_t str_last_index_of_string(cstring str, cstring cstr) {
    ksize_t last_good = str_index_of_string(str, cstr);
    ksize_t tmp_good = 0;

    while (last_good < str_len(str)) {
        tmp_good = str_index_of_string_from(str, cstr, last_good + 1);
        if (tmp_good == str_len(str))
            break;
        last_good = tmp_good;
    }
    return last_good;
}
