/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_find_first_node
*/

#include "kapparser.h"

yaml_node_t *yaml_find_first_node(yaml_f *file, cstring key) {
    yaml_node_t *node_f = NULL;
    text_t points = str_split(key, '.');
    string tmp_key = str_create_empty();

    foreach_l(file->yaml, node) {
        foreach_l(points, n) {
            if (str_len(tmp_key) > 0)
                str_add_str(&tmp_key, ".");
            str_add_str(&tmp_key, n->data);
            node_f = yaml_key_exists(node->data, tmp_key, str_create_empty());
            if (node_f != NULL)
                break;
        }
        if (node_f != NULL)
            break;
    }
    kfree(tmp_key);
    text_destroy(points);
    return node_f;
}
