/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_end_with
*/

#include "kapstring.h"

bool str_end_with(cstring str, cstring end) {
    ksize_t len = str_len(str);
    ksize_t len_end = str_len(end);

    if (len < len_end)
        return false;
    for (ksize_t i = 0; i < len_end; i++) {
        if (str[i + len - len_end] != end[i])
            return false;
    }
    return true;
}

bool str_end_cwith(cstring str, char c) {
    ksize_t len = str_len(str);

    if (len == 0)
        return false;
    return str[len - 1] == c;
}
