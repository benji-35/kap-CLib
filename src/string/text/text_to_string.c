/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_to_string
*/

#include "kapstring.h"

string text_to_string(ctext_t text) {
    string str = str_create_empty();
    list_node_t *node = text->head;

    while (node != NULL) {
        if (str_is_empty(str)) {
            str_add_str(&str, (cstring)node->data);
        } else {
            str_add_char(&str, '\n');
            str_add_str(&str, (cstring)node->data);
        }
        node = node->next;
    }
    return (str);
}
