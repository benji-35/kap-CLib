/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_add_line
*/

#include "kapstring.h"

void text_add_line(text_t text, char *line) {
    list_push(text, str_copy(line));
}

void text_add_lines_at(text_t text, string *lines, ksize_t index) {
    list_insert(text, lines, index);
}

void text_add_text(text_t text, ctext_t text2) {
    list_add_list(text, text2);
}

string text_get_line(ctext_t text, ksize_t index) {
    void *data = list_get(text, index);
    if (data == NULL)
        return NULL;
    return (string) data;
}
