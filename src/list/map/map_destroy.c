/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_destroy
*/

#include "kaplist.h"
#include "kapstring.h"

void map_remove(map_t *map, char *key) {
    if (map == NULL || key == NULL)
        return;
    list_node_t *node = map->head;
    list_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        if (str_is_equal(node->key, key)) {
            if (node->destroy != NULL)
                node->destroy(node->data);
            else
                kapfree(node->data);
            kapfree(node);
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
