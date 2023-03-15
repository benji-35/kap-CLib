/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_destroy_node
*/

#include "kapparser.h"

void destroy_yml_data_node(yaml_node_t *yml_node) {
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
}

void yaml_destroy_node(void *data) {
    yaml_node_t *yml_node = data;

    if (data == NULL)
        return;
    kfree(yml_node->key);
    destroy_yml_data_node(yml_node);
    list_destroy(yml_node->children);
    kfree(yml_node);
}
