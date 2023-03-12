/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_reverse
*/

#include "kapstring.h"

string str_reverse(cstring str) {
    string result = str_create_empty();
    ksize_t size = str_len(str);

    for (ksize_t i = size - 1; i > 0; i--)
        str_add_char(&result, str[i]);
    return (result);
}
