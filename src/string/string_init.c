/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_init
*/

#include "kapstring.h"

string str_create_empty(void) {
    string str = malloc(sizeof(char));

    if (str == NULL)
        return NULL;
    str[0] = '\0';
    return str;
}

string str_create_char(char c) {
    string str = malloc(sizeof(char) * 2);

    if (str == NULL)
        return NULL;
    str[0] = c;
    str[1] = '\0';
    return str;
}

string str_create_string(cstring cstr) {
    ksize_t size = str_len(cstr);
    string str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return NULL;
    for (ksize_t i = 0; i < size; i++) {
        str[i] = cstr[i];
    }
    return str;
}
