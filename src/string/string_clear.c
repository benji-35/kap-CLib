/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_clear
*/

#include "kapstring.h"

void str_clear(string *str) {
    if (str == NULL || *str == NULL)
        return;
    kfree(*str);
    *str = str_create_empty();
}
