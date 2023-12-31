/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_count
*/

#include "kapstring.h"

ksize_t str_count_str(cstring str, cstring to_find) {
    ksize_t count = 0;
    ksize_t len = str_len(to_find);

    for (ksize_t i = 0; i < str_len(str); i++) {
        if (str_start_with_from(str, to_find, i) == true) {
            count++;
            i += len - 1;
        }
    }
    return count;
}

ksize_t str_count_char(cstring str, char to_find) {
    ksize_t count = 0;

    for (ksize_t i = 0; i < str_len(str); i++) {
        if (str[i] == to_find)
            count++;
    }
    return count;
}
