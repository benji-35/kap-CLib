/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_set_line
*/

#include "kapstring.h"

void text_set_line(text_t text, cstring line, ksize_t index) {
    if (text == NULL || index >= text->size)
        return;
    
    list_node_t *node = text->head;
    ksize_t i = 0;

    while (node != NULL) {
        if (i == index) {
            kfree(node->data);
            node->data = str_create_string(line);
            return;
        }
        node = node->next;
        i++;
    }
}
