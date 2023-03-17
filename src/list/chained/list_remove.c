/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_remove
*/

#include "kaplist.h"

void list_remove(list_t *list, ksize_t index) {
    list_node_t *tmp = list->head;

    if (index >= list->size)
        return;
    for (ksize_t i = 0; i < index; i++) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    }
    if (tmp->prev == NULL)
        list->head = tmp->next;
    else
        tmp->prev->next = tmp->next;
    if (tmp->next == NULL)
        list->tail = tmp->prev;
    else
        tmp->next->prev = tmp->prev;
    list->size--;
    if (tmp->destroy)
        tmp->destroy(tmp->data);
    kfree(tmp);
}

void list_remove_data(list_t *list, void *data) {
    list_node_t *tmp = list->head;
    list_node_t *tmp2 = NULL;

    for (ksize_t i = 0; i < list->size; i++) {
        tmp2 = tmp->next;
        if (tmp->equal != NULL && tmp->equal(tmp->data, data)) {
            list_remove(list, i);
        }
        tmp = tmp2;
    }
}
