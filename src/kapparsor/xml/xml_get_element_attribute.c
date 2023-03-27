/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_get_element_others
*/

#include "kapparser.h"

private bool can_add_attr_xml_search(xml_node_t *node, cstring attr_name, cstring value) {
    if (node == NULL || attr_name == NULL)
        return false;
    if (map_key_exists(node->attributes, attr_name) == true && node->destroyed == false) {
        if (value == NULL)
            return true;
        string val = (string)map_get(node->attributes, attr_name);
        if (str_is_equal(val, value, true) == true)
            return true;
    }
    return false;
}

private void search_xml_attr_from(xml_node_t *parent, xml_f *file, cstring attribute, cstring value, list_t *result) {
    if (file == NULL || attribute == NULL || result == NULL)
        return;
    list_t *list_search = NULL;

    if (parent != NULL)
        list_search = parent->children;
    else if (file != NULL)
        list_search = file->xml;
    else
        return;
    foreach_l(list_search, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        if (can_add_attr_xml_search(xml_nd, attribute, value) == true)
            list_push(result, xml_nd);
        search_xml_attr_from(xml_nd, file, attribute, value, result);
    }
}

list_t *xml_get_element_attribute(xml_f *xml_file, cstring attribute, cstring value) {
    list_t *list = list_create();

    search_xml_attr_from(NULL, xml_file, attribute, value, list);
    return list;
}

list_t *xml_get_element_attribute_from_node(xml_node_t *xml_node, cstring attribute, cstring value) {
    list_t *list = list_create();

    if (xml_node == NULL || attribute == NULL || xml_node->children == NULL || xml_node->children->size == 0)
        return list;
    search_xml_attr_from(xml_node, NULL, attribute, value, list);
    return list;
}
