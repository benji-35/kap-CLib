/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_io
*/

#include "kapstring.h"

void text_write(ctext_t text, cstring path, bool append) {
    string str = text_to_string(text);
    str_write(str, path, append);
    kapfree(str);
}

text_t text_read(cstring path) {
    string str = str_read(path);
    text_t text = str_split_str(str, "\r\n");

    if (text->size == 1 && str_contains_char(text_get_line(text, 0), '\n')) {
        text_destroy(text);
        text = str_split_str(str, "\n");
    }
    kapfree(str);
    return text;
}
