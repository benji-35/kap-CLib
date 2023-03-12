/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_insert
*/

#include "kaplist.h"
#include "kapstring.h"

void __insert_map_node(map_t *map, const char *key, void *data) {
    map_node_t *node = calloc(1, sizeof(map_node_t));

    if (node == NULL)
        return;
    node->key = str_copy(key);
    node->data = data;
    node->head = map->head;
    node->prev = map->tail;
    if (map->head == NULL)
        map->head = node;
    if (map->tail != NULL)
        map->tail->next = node;
    else
        map->tail = node;
    map->tail = node;
}

void map_insert(map_t *map, const char *key, void *data, bool can_replace) {
    map_node_t *node = malloc(sizeof(map_node_t));
    
    void *old_data = map_get(map, key);
    if (old_data != NULL && can_replace) {
        node->data = data;
        return;
    } else if (old_data != NULL && !can_replace) {
        return;
    }
    __insert_map_node(map, key, data);
}
