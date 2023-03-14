/*
** KAP PROJECT, 2023
** C Lib
** File description:
** str_replace
*/

#include "kapstring.h"

string str_replace(cstring source, cstring target, cstring replace) {
    string result = str_create_empty();
    if (source == NULL || target == NULL || replace == NULL) {
        kfree(result);
        return NULL;
    }
    ksize_t index = str_index_of_string_from(source, target, 0);
    if (index >= str_length(source)) {
        kfree(result);
        return str_copy(source);
    }
    for (ksize_t i = 0; i < str_len(source); i++) {
        if (i == index) {
            str_add_str(&result, replace);
            i += str_length(target) - 1;
            index = str_index_of_string_from(source, target, i + 1);
        } else
            str_add_char(&result, source[i]);
    }
    return result;
}
