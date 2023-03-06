/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_io
*/

#include "kapstring.h"

void text_write(ctext_t text, cstring path) {
    string str = text_to_string(text);
    str_write(str, path);
    kapfree(str);
}

text_t text_read(cstring path) {
    string str = str_read(path);
    text_t text = str_split(str, '\n');
    kapfree(str);
    return text;
}
