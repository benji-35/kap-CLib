/*
** KAP PROJECT, 2023
** C Lib
** File description:
** str_add
*/

#include "kapstring.h"

void str_add_char(string *str, char c) {
    ksize_t size = str_len(*str);
    string new_str = malloc(sizeof(char) * (size + 2));

    if (new_str == NULL)
        return;
    for (ksize_t i = 0; i < size; i++)
        new_str[i] = (*str)[i];
    new_str[size] = c;
    new_str[size + 1] = '\0';
    free(*str);
    *str = new_str;
}

void str_add_string(string *str, cstring cstr) {
    ksize_t size = str_len(*str);
    ksize_t size2 = str_len(cstr);
    string new_str = malloc(sizeof(char) * (size + size2 + 1));

    if (new_str == NULL)
        return;
    for (ksize_t i = 0; i < size; i++)
        new_str[i] = (*str)[i];
    for (ksize_t i = 0; i < size2; i++)
        new_str[size + i] = cstr[i];
    new_str[size + size2] = '\0';
    free(*str);
    *str = new_str;
}
