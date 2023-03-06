/*
** KAP PROJECT, 2023
** C Lib
** File description:
** init_chained_list
*/

#include "kaplist.h"

list_t *list_create(void) {
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
