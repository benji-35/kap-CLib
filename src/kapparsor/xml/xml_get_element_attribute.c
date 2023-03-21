/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_get_element_others
*/

#include "kapparser.h"

private bool can_add_xml_node_attr(xml_node_t *node, cstring attribute, cstring value) {
    if (node == NULL || attribute == NULL || value == NULL)
        return false;
    if (!map_key_exists(node->attributes, attribute))
        return false;
    string val = (string)map_get(node->attributes, attribute);
    return str_is_equal(val, value, true);
}

list_t *xml_get_element_tag(xml_f *xml_file, cstring tag) {
    list_t *list = list_create();

    foreach_l(xml_file->xml, node) {
        xml_nd = (xml_node_t *)node->data;
        if (str_is_equal(xml_nd->tag_name, tag, true) == false)
            continue;
        list_push(list, xml_nd);
    }
    return list;    
}

list_t *xml_get_element_attribute(xml_f *xml_file, cstring attribute, cstring value) {
    list_t *list = list_create();

    foreach_l(xml_file->xml, node) {
        xml_nd = (xml_node_t *)node->data;
        if (can_add_xml_node_attr(xml_nd, attribute, value) == false)
            continue;
        list_push(list, xml_nd);
    }
    return list;
}
