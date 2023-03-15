/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_insert
*/

#include "kaplist.h"
#include "kapstring.h"

#include <stdio.h>

private map_node_t *__insert_map_node(map_t *map, const char *key, void *data) {
    map_node_t *node = calloc(1, sizeof(map_node_t));

    if (node == NULL)
        return NULL;
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
    return node;
}

private map_node_t *__modify_map_node(map_t *map, const char *key, void *data) {
    map_node_t *node = map->head;

    while (node != NULL) {
        if (str_is_equal(node->key, key, true)) {
            if (node->destroy != NULL)
                node->destroy(node->data);
            node->data = data;
            return node;
        }
        node = node->next;
    }
    return NULL;
}

map_node_t *map_insert(map_t *map, const char *key, void *data, bool can_replace) {
    if (map == NULL || key == NULL)
        return NULL;
    void *old_data = map_get(map, key);
    if (old_data != NULL && can_replace) {
        return __modify_map_node(map, key, data);
    } else if (old_data != NULL && !can_replace) {
        return NULL;
    }
    return __insert_map_node(map, key, data);
}
