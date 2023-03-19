/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_get
*/

#include "kaplist.h"
#include <stdio.h>

void *list_get(const list_t *list, ksize_t index) {
    if (list == NULL)
        return (NULL);
    list_node_t *node = list->head;

    if (index >= list->size)
        return (NULL);
    for (ksize_t i = 0; i < index; i++) {
        if (node == NULL)
            return (NULL);
        node = node->next;
    }
    return (node->data);
}

void *list_get_first(const list_t *list) {
    if (list == NULL || list->size == 0)
        return (NULL);
    return (list->head->data);
}

void *list_get_last(const list_t *list) {
    if (list == NULL || list->size == 0)
        return (NULL);
    return (list->tail->data);
}

void list_print(const list_t *list) {
    if (list == NULL)
        return;
    list_node_t *node = list->head;

    if (list->size == 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (ksize_t i = 0; i < list->size; i++) {
        if (node->print != NULL)
            node->print(node->data);
        else
            printf("%p", node->data);
        if (i != list->size - 1)
            printf(", ");
        node = node->next;
    }
    printf("]\n");
}
