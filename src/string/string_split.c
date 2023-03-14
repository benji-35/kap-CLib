/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_split
*/

#include "kapstring.h"

text_t str_split(cstring str, char c) {
    string tmp = str_create_char(c);
    text_t text = str_split_str(str, tmp);

    kfree(tmp);
    return (text);
}

text_t str_split_str(cstring str, cstring c) {
    return (str_split_str_from(str, c, 0));
}

text_t str_split_str_from(cstring str, cstring c, ksize_t from) {
    text_t text = text_create();
    string tmp = str_create_empty();

    for (ksize_t i = from; i < str_len(str); i++) {
        if (str_start_with_from(str, c, i)) {
            text_add_line(text, tmp);
            str_clear(&tmp);
            i += str_len(c) - 1;
            continue;
        } else {
            str_add_char(&tmp, str[i]);
        }
    }
    text_add_line(text, tmp);
    kfree(tmp);
    return (text);
}
