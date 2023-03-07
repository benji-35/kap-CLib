/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_init
*/

#include "kaplist.h"

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
        else
            kapfree(node->data);
        kapfree(node->key),
        kapfree(node);
        node = next;
    }
    kapfree(map);
}
