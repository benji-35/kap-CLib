/*
** KAP PROJECT, 2023
** C Lib
** File description:
** init_chained_list
*/

#include "kaplist.h"

list_t *list_create(void) {
    list_t *list = calloc(1, sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->size = 0;
    return list;
}

void list_destroy(list_t *list) {
    if (list == NULL)
        return;
    list_node_t *node = list->head;
    list_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        if (node->destroy != NULL)
            node->destroy(node->data);
        kapfree(node);
        node = next;
    }
    kapfree(list);
}
