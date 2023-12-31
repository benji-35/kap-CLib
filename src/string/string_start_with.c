/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_start_with
*/

#include "kapstring.h"

bool str_start_with(cstring str, cstring start) {
    return str_start_with_from(str, start, 0);
}

bool str_start_cwith(cstring str, char c) {
    return str_start_cwith_from(str, c, 0);
}

bool str_start_cwith_from(cstring str, char c, ksize_t index) {
    if (str_len(str) <= index)
        return false;
    return str[index] == c;
}

bool str_start_with_from(cstring str, cstring start, ksize_t index) {
    ksize_t len = str_len(str);
    ksize_t len_start = str_len(start);

    if (len < len_start)
        return false;
    for (ksize_t i = 0; i < len_start; i++) {
        if (str[i + index] != start[i])
            return false;
    }
    return true;
}