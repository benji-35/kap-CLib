/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_init
*/

#include "kaplist.h"
#include "kapstring.h"

map_t *map_create(void) {
    map_t *map = malloc(sizeof(map_t));

    map->head = NULL;
    map->tail = NULL;
    return (map);
}

void map_destroy(map_t *map) {
    if (map == NULL)
        return;
    map_node_t *node = map->head;
    map_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        if (node->destroy != NULL)
            node->destroy(node->data);
        kapfree(node->key),
        kapfree(node);
        node = next;
    }
    kapfree(map);
}

map_t *map_create_from_lists(list_t *keys, list_t *values) {
    map_t *map = map_create();

    if (keys->size != values->size) {
        map_destroy(map);
        return (NULL);
    }

    for(ksize_t i = 0; i < keys->size; i++) {
        map_insert(map, (string)list_get(keys, i), list_get(values, i), true);
    }
    return (map);
}
