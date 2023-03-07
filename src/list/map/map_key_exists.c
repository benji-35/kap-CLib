/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_key_exists
*/

#include "kaplist.h"
#include "kapstring.h"

void *map_get(map_t *map, const char *key) {
    map_node_t *node = map->head;

    while (node != NULL) {
        if (str_is_equal(node->key, key, true))
            return (node->data);
        node = node->next;
    }
    return (NULL);
}

bool map_key_exists(map_t *map, const char *key) {
    return (map_get(map, key) != NULL);
}
