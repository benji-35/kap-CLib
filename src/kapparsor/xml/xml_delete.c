/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_delete
*/

#include "kapparser.h"

#include <stdio.h>

private bool xml_can_delete(xml_node_t *nd, cstring tag, cstring content, map_t *attributes) {
    if (nd == NULL)
        return false;
    if (nd->destroyed)
        return false;
    if (tag != NULL && !str_is_equal(nd->tag_name, tag, true))
        return false;
    if (content != NULL && !str_is_equal(nd->content, content, true))
        return false;
    if (attributes != NULL && !map_is_equal(nd->attributes, attributes))
        return false;
    return true;
}

void xml_delete_element_node(xml_node_t *nd, cstring tag, cstring content, map_t *attributes) {
    if (nd == NULL)
        return;
    if (xml_can_delete(nd, tag, content, attributes)) {
        nd->destroyed = true;
        return;
    }
    if (nd->children == NULL)
        return;
    for (ksize_t i = 0; i < nd->children->size; i++)
        xml_delete_element_node(list_get(nd->children, i), tag, content, attributes);
}

void xml_delete_element(xml_f *xml_file, cstring tag, cstring content, map_t *attributes) {
    if (XML_FAILED(xml_file))
        return;
    for (ksize_t i = 0; i < xml_file->xml->size; i++) {
        xml_node_t *nd = list_get(xml_file->xml, i);
        xml_delete_element_node(nd, tag, content, attributes);
    }
}
