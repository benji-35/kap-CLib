/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_add_line
*/

#include "kapstring.h"

private bool equal_line_text(void *data1, void *data2) {
    string str1 = (string) data1;
    string str2 = (string) data2;

    return str_is_equal(str1, str2, true);
}

void text_add_line(text_t text, char *line) {
    list_node_t *node = list_push(text, str_copy(line));

    if (node == NULL)
        return;
    node->destroy = &kapfree;
    node->equal = &equal_line_text;
}

void text_add_line_at(text_t text, string lines, ksize_t index) {
    list_node_t *node = list_insert(text, str_copy(lines), index);

    if (node == NULL)
        return;
    node->destroy = &kapfree;
    node->equal = &equal_line_text;
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
