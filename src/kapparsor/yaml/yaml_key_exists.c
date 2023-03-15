/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_key_exists
*/

#include "kapparser.h"
#include <stdio.h>

yaml_node_t *yaml_key_exists(yaml_node_t *node, cstring key, string before) {
    if (node == NULL) {
        kfree(before);
        return NULL;
    }
    if (str_len(before) > 0)
        str_add_str(&before, ".");
    str_add_str(&before, node->key);
    if (str_is_equal(node->key, key, true)) {
        kfree(before);
        return node;
    }
    foreach_l(node->children, child) {
        yaml_node_t *node = yaml_key_exists(child->data, key, before);
        if (node != NULL) {
            kfree(before);
            return node;
        }
    }
    kfree(before);
    return NULL;
}

yaml_node_t *yaml_key_exists_file(yaml_f *file, cstring key) {
    yaml_node_t *node = NULL;

    foreach_l(file->yaml, child) {
        node = yaml_key_exists(child->data, key, str_create_empty());
        if (node != NULL) {
            return node;
        }
    }
    return NULL;
}
