/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_index_of
*/

#include "kapstring.h"

ksize_t str_index_of_char(cstring str, char c) {
    return str_index_of_char_from(str, c, 0);
}

ksize_t str_index_of_string(cstring str, cstring cstr) {
    return str_index_of_string_from(str, cstr, 0);
}

ksize_t str_index_of_char_from(cstring str, char c, ksize_t from) {
    ksize_t i = from;

    if (str == NULL || i >= str_len(str))
        return -1;
    for (; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return str_len(str);
}

ksize_t str_index_of_string_from(cstring str, cstring cstr, ksize_t from) {
    ksize_t i = from;
    ksize_t j = 0;
    ksize_t size = str_len(cstr);

    if (str == NULL || cstr == NULL || i >= str_len(str))
        return str_len(str);
    for (; str[i] != '\0'; i++) {
        if (str[i] == cstr[j]) {
            j++;
            if (j == size)
                return i - size + 1;
        } else
            j = 0;
    }
    return str_len(str);
}
