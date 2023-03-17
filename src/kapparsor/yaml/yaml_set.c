/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_set
*/

#include "kapparser.h"
#include <stdio.h>

void yaml_set(yaml_f *file, cstring key, cstring value) {
    yaml_node_t *node = yaml_parser(file, key);
    if (node == NULL)
        return;
    destroy_yml_data_node(node);
    node->type = YML_STRING;
    node->modified = true;
    if (value == NULL) {
        node->destroyed = true;
        node->value = NULL;
    } else {
        node->destroyed = false;
        node->value = str_copy(value);
    }
}

void yaml_set_list(yaml_f *file, cstring key, list_t *value) {
    yaml_node_t *node = yaml_parser(file, key);
    if (node == NULL)
        return;
    destroy_yml_data_node(node);
    node->type = YML_LIST;
    node->modified = true;
    node->value = value;
    if (value == NULL) {
        node->destroyed = true;
    } else {
        node->destroyed = false;
    }
}
