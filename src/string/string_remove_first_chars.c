/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_remove_first_chars
*/

#include "kapstring.h"

void str_remove_first_chars(string *str, char c) {
    while (str_len(*str) > 0 && str_start_cwith(*str, c))
        str_remove_char_at(str, 0);
}
