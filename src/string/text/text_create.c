/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_create
*/

#include "kapstring.h"

text_t text_create(void) {
    return list_create();
}

void text_destroy(text_t text) {
    list_destroy(text);
}
