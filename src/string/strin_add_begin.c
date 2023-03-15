/*
** KAP PROJECT, 2023
** C Lib
** File description:
** strin_add_begin
*/

#include "kapstring.h"

void str_add_str_at_begin(string *str, cstring to_add) {
    string tmp = str_create_empty();

    str_add_str(&tmp, to_add);
    str_add_str(&tmp, *str);
    kfree(*str);
    *str = tmp;
}

void str_add_char_at_begin(string *str, char to_add) {
    string tmp = str_create_empty();

    str_add_char(&tmp, to_add);
    str_add_str(&tmp, *str);
    kfree(*str);
    *str = tmp;
}
