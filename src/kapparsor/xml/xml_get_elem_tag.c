/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_get_elem_tag
*/

#include "kapparser.h"

private void search_xml_tag_from(xml_node_t *parent, xml_f *file, cstring tag, list_t *result) {
    if (tag == NULL || result == NULL)
        return;
    list_t *list_search = NULL;

    if (parent != NULL)
        list_search = parent->children;
    else if (file != NULL)
        list_search = file->xml;
    else
        return;
    if (parent != NULL)
        list_search = parent->children;
    foreach_l(list_search, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        if (str_is_equal(xml_nd->tag_name, tag, true) == true && xml_nd->destroyed == false)
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

list_t *xml_get_element_tag_from_node(xml_node_t *xml_node, cstring tag) {
    list_t *list = list_create();

    if (xml_node == NULL || tag == NULL || xml_node->children == NULL || xml_node->children->size == 0)
        return list;
    search_xml_tag_from(xml_node, NULL, tag, list);
    return list;
}
