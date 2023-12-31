/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_get_size
*/

#include "kaplist.h"

ksize_t map_size(map_t *map) {
    map_node_t *node = map->head;
    ksize_t size = 0;

    while (node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}
