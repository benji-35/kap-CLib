/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_transform
*/

#include "kapstring.h"

void str_to_upper(string str) {
    ksize_t len = str_len(str);

    for (ksize_t i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

void str_to_lower(string str) {
    ksize_t len = str_len(str);

    for (ksize_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}
