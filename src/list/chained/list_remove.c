/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_remove
*/

#include "kaplist.h"

void list_remove(list_t *list, int index) {
    list_node_t *tmp = list->head;

    if (index < 0 || index >= list->size)
        return;
    for (int i = 0; i < index; i++)
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

    for (int i = 0; i < list->size; i++) {
        if (tmp->equal != NULL && tmp->equal(tmp->data, data)) {
            list_remove(list, i);
        }
        tmp = tmp->next;
    }
}
