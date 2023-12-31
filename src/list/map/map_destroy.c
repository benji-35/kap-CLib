/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_destroy
*/

#include "kaplist.h"
#include "kapstring.h"

private void remove_node_map(map_t *map, map_node_t *node) {
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        map->head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        map->tail = node->prev;
    if (node->destroy != NULL)
        node->destroy(node->data);
    kapfree(node->key);
    kapfree(node);
}

void map_remove(map_t *map, const char *key) {
    if (map == NULL || key == NULL)
        return;
    map_node_t *node = map->head;
    map_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        if (str_is_equal(node->key, key, true)) {
            remove_node_map(map, node);
            return;
        }
        node = next;
    }
}

void map_clear(map_t *map) {
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
    map->head = NULL;
    map->tail = NULL;
}
