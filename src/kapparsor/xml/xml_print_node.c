/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_print_node
*/

#include "kapparser.h"
#include <stdio.h>

void xml_print_node(void *data) {
    if (data == NULL)
        return;
    xml_node_t *node = data;
    map_t *attributes = node->attributes;

    printf("Node name: %s\n", node->name);
    printf("Node content: %s\n", node->content);
    printf("Node attributes:\n");
    foreach_m(attributes, node) {
        string key = node->key;
        string value = node->data;
        printf("\t%s: %s\n", key, value);
    }
    printf("Node children:\n");
    foreach_l(node->children, child) {
        xml_print_node(child->data);
    }
}
