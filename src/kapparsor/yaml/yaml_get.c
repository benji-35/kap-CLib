/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_get
*/

#include "kapparser.h"

string yaml_get(yaml_f *file, cstring key) {
    yaml_node_t *node = yaml_parser(file, key);
    if (node == NULL)
        return NULL;
    return node->value;
}

list_t *yaml_get_list(yaml_f *file, cstring key) {
    yaml_node_t *node = yaml_parser(file, key);
    if (node == NULL)
        return NULL;
    return node->value;
}