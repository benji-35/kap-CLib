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
    for (ksize_t i = len - len_end, j = 0; i < len; i++, j++) {
        if (str[i] != end[j])
            return false;
    }
    return true;
}

bool str_end_cwith(cstring str, char c) {
    string str_c = str_create_char(c);
    bool result = str_end_with(str, str_c);

    kapfree(str_c);
    return result;
}
