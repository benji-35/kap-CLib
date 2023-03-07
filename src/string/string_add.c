/*
** KAP PROJECT, 2023
** C Lib
** File description:
** str_add
*/

#include "kapstring.h"

void str_add_char(string *str, char c) {
    str_add_char_from(str, c, str_len(*str));
}

void str_add_str(string *str, cstring cstr) {
    str_add_str_from(str, cstr, str_len(*str));
}

void str_add_char_from(string *str, char c, ksize_t from) {
    ksize_t size = str_len(*str);
    string new_str = calloc(1, sizeof(char) * (size + 2));

    if (new_str == NULL)
        return;
    for (ksize_t i = 0; i < from; i++)
        new_str[i] = (*str)[i];
    new_str[from] = c;
    for (ksize_t i = from; i < size; i++)
        new_str[i + 1] = (*str)[i];
    new_str[size + 1] = '\0';
    kfree(*str);
    *str = new_str;
}

void str_add_str_from(string *str, cstring cstr, ksize_t from) {
    ksize_t size = str_len(*str);
    ksize_t size2 = str_len(cstr);
    string new_str = malloc(sizeof(char) * (size + size2 + 1));

    if (new_str == NULL)
        return;
    for (ksize_t i = 0; i < from; i++)
        new_str[i] = (*str)[i];
    for (ksize_t i = 0; i < size2; i++)
        new_str[from + i] = cstr[i];
    for (ksize_t i = from; i < size; i++)
        new_str[size2 + i] = (*str)[i];
    new_str[size + size2] = '\0';
    kfree(*str);
    *str = new_str;
}
