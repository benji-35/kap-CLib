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
    for (ksize_t i = 0; i < index; i++)
        tmp = tmp->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    list->size--;
    if (tmp->destroy)
        tmp->destroy(tmp->data);
    else
        kfree(tmp->data);
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
