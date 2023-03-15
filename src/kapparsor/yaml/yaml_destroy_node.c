/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_destroy_node
*/

#include "kapparser.h"

void yaml_destroy_node(void *data) {
    yaml_node_t *yml_node = data;

    if (data == NULL)
        return;
    kfree(yml_node->key);
    switch (yml_node->type) {
        case YML_STRING:
            kfree(yml_node->value);
            break;
        case YML_LIST:
            list_destroy(yml_node->value);
            break;
        default:
            break;
    }
    list_destroy(yml_node->children);
    kfree(yml_node);
}
