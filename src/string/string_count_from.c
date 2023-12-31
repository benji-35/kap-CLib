/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_count_from
*/

#include "kapstring.h"

ksize_t str_count_char_from(cstring str, char c, ksize_t index) {
    ksize_t nb = 0;

    if (str == NULL)
        return 0;
    for (ksize_t i = index; i < str_len(str); i++) {
        if (str[i] != c)
            break;
        nb++;
    }
    return nb;
}
