/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_get_key
*/

#include "kaplist.h"

char *map_get_key(map_t *map, ksize_t index) {
    map_node_t *node = map->head;

    while (node != NULL) {
        if (index == 0)
            return node->key;
        index--;
        node = node->next;
    }
    return NULL;
}
