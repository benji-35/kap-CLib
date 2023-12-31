/*
** KAP PROJECT, 2023
** C Lib
** File description:
** map_is_equal
*/

#include "kaplist.h"

bool map_is_equal(map_t *map1, map_t *map2) {
    if (map1 == map2)
        return true;
    if (map1 == NULL || map2 == NULL)
        return false;
    if (map_size(map1) != map_size(map2))
        return false;
    foreach_m(map1, node) {
        if (!map_key_exists(map2, node->key))
            return false;
        if (node->equal != NULL) {
            if (!node->equal(node->data, map_get(map2, node->key)))
                return false;
        }
    }
    return (true);
}
