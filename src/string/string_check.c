/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_check
*/

#include "kapstring.h"

bool str_is_empty(cstring str) {
    if (str == NULL)
        return true;
    return str[0] == '\0';
}

bool str_is_equal(cstring str1, cstring str2, bool case_sensitive) {
    ksize_t size1 = str_len(str1);
    ksize_t size2 = str_len(str2);

    if (size1 != size2)
        return false;
    for (ksize_t i = 0; i < size1; i++) {
        if (case_sensitive) {
            if (str1[i] != str2[i])
                return false;
        } else {
            if (str1[i] != str2[i] && str1[i] != str2[i] + 32 && str1[i] != str2[i] - 32)
                return false;
        }
    }
    return true;
}

bool str_is_not_empty(cstring str) {
    return !str_is_empty(str);
}

bool str_is_not_equal(cstring str1, cstring str2, bool case_sensitive) {
    return !str_is_equal(str1, str2, case_sensitive);
}
