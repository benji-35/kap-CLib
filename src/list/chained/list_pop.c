/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_pop
*/

#include "kaplist.h"

void list_pop(list_t *list) {
    if (list == NULL || list->size == 0)
        return;
    list_node_t *node = list->tail;
    list->tail = node->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    list->size--;
    if (node->destroy)
        node->destroy(node->data);
    kfree(node);
}

void list_pop_front(list_t *list) {
    if (list == NULL || list->size == 0)
        return;
    list_node_t *node = list->head;
    list->head = node->next;
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;
    list->size--;
    if (node->destroy)
        node->destroy(node->data);
    kfree(node);
}

void list_clear(list_t *list) {
    if (list == NULL)
        return;
    while (list->size > 0)
        list_pop(list);
}
