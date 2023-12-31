/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_add
*/

#include "kapparser.h"

private xml_node_t *xml_create_added_xml(cstring tag, cstring content, map_t *attributes) {
    xml_node_t *result = calloc(1, sizeof(xml_node_t));

    if (tag == NULL || str_len(tag) == 0 || result == NULL) {
        kfree(result);
        return NULL;
    }
    result->tag_name = str_copy(tag);
    result->content = str_copy(content);
    result->children = list_create();
    result->attributes = attributes;
    result->destroyed = false;
    if (result->attributes == NULL)
        result->attributes = map_create();
    return result;
}

void xml_add_element(xml_f *xml_file, cstring tag, cstring content, map_t *attributes) {
    if (XML_FAILED(xml_file) || tag == NULL || str_len(tag) == 0)
        return;
    xml_node_t *added = xml_create_added_xml(tag, content, attributes);
    if (added == NULL)
        return;
    added->parent = NULL;
    added->file = xml_file;
    list_node_t *l_nd = list_push(xml_file->xml, added);
    l_nd->destroy = &xml_node_destroy;
}

void xml_add_element_to_node(xml_node_t *xml_node, cstring tag, cstring content, map_t *attributes) {
    if (xml_node == NULL || tag == NULL || str_len(tag) == 0)
        return;
    xml_node_t *added = xml_create_added_xml(tag, content, attributes);
    if (added == NULL)
        return;
    added->parent = xml_node;
    added->file = xml_node->file;
    list_node_t *l_nd = list_push(xml_node->children, added);
    l_nd->destroy = &xml_node_destroy;
}
