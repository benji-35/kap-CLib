/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_key_exists
*/

#include "kapparser.h"
#include <stdio.h>

yaml_node_t *yaml_key_exists(yaml_node_t *node, cstring key, string before) {
    string new_before = str_copy(before);

    if (node == NULL || key == NULL || before == NULL || new_before == NULL) {
        kfree(before);
        return NULL;
    }
    if (str_len(new_before) > 0)
        str_add_str(&new_before, ".");
    str_add_str(&new_before, node->key);
    if (str_is_equal(node->key, key, true)) {
        kfree(new_before);
        return node;
    }
    foreach_l(node->children, child) {
        yaml_node_t *node = yaml_key_exists(child->data, key, before);
        if (node != NULL) {
            kfree(new_before);
            return node;
        }
    }
    kfree(new_before);
    return NULL;
}

yaml_node_t *yaml_key_exists_file(yaml_f *file, cstring key) {
    yaml_node_t *node = NULL;
    string empty = str_create_empty();

    if (file == NULL) {
        kfree(empty);
        return NULL;
    }
    foreach_l(file->yaml, child) {
        node = yaml_key_exists(child->data, key, empty);
        if (node != NULL) {
            kfree(empty);
            return node;
        }
    }
    kfree(empty);
    return NULL;
}
