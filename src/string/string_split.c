/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_split
*/

#include "kapstring.h"

text_t str_split(cstring str, char c) {
    text_t text = text_create();
    string tmp = str_create_empty();
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            text_add_line(text, tmp);
            tmp = str_create_empty();
        } else
            str_add_char(&tmp, str[i]);
        i++;
    }
    text_add_line(text, tmp);
    return (text);
}

text_t str_split_str(cstring str, cstring c) {
    text_t text = text_create();
    string tmp = str_create_empty();
    int i = 0;

    while (str[i] != '\0') {
        if (str_start_with_from(&str[i], c, i)) {
            text_add_line(text, tmp);
            tmp = str_create_empty();
            i += str_len(c);
        } else {
            str_add_char(&tmp, str[i]);
            i++;
        }
        i++;
    }
    return (text);
}
