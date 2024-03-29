/*
** KAP PROJECT, 2023
** C Lib
** File description:
** list_concat
*/

#include "kaplist.h"

list_t *list_concat(const list_t *list1, const list_t *list2) {
    list_t *list = list_create();

    foreach_l(list1, node) {
        list_push(list, node->data);
    }
    foreach_l(list2, node) {
        list_push(list, node->data);
    }
    return list;
}

void list_add_list(list_t *list1, const list_t *list2) {
    if (list1 == NULL || list2 == NULL)
        return;
    foreach_l(list2, node) {
        list_push(list1, node->data);
    }
}
