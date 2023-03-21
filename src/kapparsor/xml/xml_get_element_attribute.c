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

private void search_xml_tag_from(xml_node_t *parent, xml_f *file, cstring tag, list_t *result) {
    if (file == NULL || tag == NULL || result == NULL)
        return;
    list_t *list_search = file->xml;

    if (parent != NULL)
        list_search = parent->children;
    foreach_l(list_search, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        if (str_is_equal(xml_nd->tag_name, tag, true) == true)
            list_push(result, xml_nd);
        search_xml_tag_from(xml_nd, file, tag, result);
    }
}

list_t *xml_get_element_tag(xml_f *xml_file, cstring tag) {
    list_t *list = list_create();

    if (xml_file == NULL || tag == NULL || xml_file->xml == NULL || xml_file->xml->size == 0)
        return list;
    search_xml_tag_from(NULL, xml_file, tag, list);
    return list;    
}

private bool can_add_attr_xml_search(xml_node_t *node, cstring attr_name, cstring value) {
    if (node == NULL || attr_name == NULL)
        return false;
    if (map_key_exists(node->attributes, attr_name) == true) {
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
    list_t *list_search = file->xml;

    if (parent != NULL)
        list_search = parent->children;
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
