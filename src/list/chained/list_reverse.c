/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_reverse
*/

#include "kaplist.h"

void list_reverse(list_t *list) {
    list_node_t *tmp = list->head;
    list_node_t *tmp2 = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->prev;
        tmp->prev = tmp->next;
        tmp->next = tmp2;
        tmp = tmp->prev;
    }
    if (tmp2 != NULL)
        list->head = tmp2->prev;
}

ksize_t list_size(const list_t *list) {
    return list->size;
}

bool list_is_empty(const list_t *list) {
    return list->size == 0;
}

void list_sort(list_t *list, int (*cmp)(const void *, const void *)) {
    list_node_t *tmp = list->head;
    list_node_t *tmp2 = NULL;
    void *data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            if (cmp(tmp->data, tmp2->data) > 0) {
                data = tmp->data;
                tmp->data = tmp2->data;
                tmp2->data = data;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}
