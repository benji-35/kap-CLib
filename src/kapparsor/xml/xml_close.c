/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_close
*/

#include "kapparser.h"

#include <stdio.h>

void destroy_xml_node(void *data) {
    if (data == NULL)
        return;
    xml_node_t *node = data;

    kfree(node->name);
    kfree(node->content);
    map_destroy(node->attributes);
    list_destroy(node->children);
    kfree(node);
}

void xml_close(xml_f *xml_file) {
    if (xml_file == NULL)
        return;
    kfree(xml_file->path);
    kfree(xml_file->version);
    kfree(xml_file->encoding);
    text_destroy(xml_file->file_content);
    list_destroy(xml_file->xml);
    kfree(xml_file);
}
