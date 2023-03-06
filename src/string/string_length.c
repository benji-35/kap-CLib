/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_length
*/

#include "kapstring.h"

ksize_t str_len(cstring str) {
    ksize_t i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
