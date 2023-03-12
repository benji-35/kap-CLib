/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_is_float
*/

#include "kapstring.h"

bool str_is_decimal(cstring str) {
    ksize_t i = 0;
    bool dot = false;

    if (str == NULL)
        return false;
    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (dot)
                return false;
            dot = true;
        } else if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool str_is_number(cstring str) {
    ksize_t i = 0;

    if (str == NULL)
        return false;
    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
