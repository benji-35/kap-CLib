/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_save
*/

#include "kapparser.h"

private void generate_xml_header(text_t txt, xml_f *xml_file) {
    string header = str_create_string("<?xml version=\"");

    str_add_str(&header, xml_file->version);
    str_add_str(&header, "\" encoding=\"");
    str_add_str(&header, xml_file->encoding);
    str_add_str(&header, "\"?>");
    text_add_line(txt, header);
    kfree(header);
}

private void rewrite_xml(text_t text, xml_node_t *parent, ksize_t increment) {
    if (parent == NULL || parent->destroyed)
        return;
    string line = str_create_empty();
    string end_balise = str_create_string("</");
    string content = str_create_string("\t");

    str_add_str(&end_balise, parent->tag_name);
    str_add_char(&end_balise, '>');
    for (ksize_t i = 0; i < increment; i++) {
        str_add_str(&line, "\t");
        str_add_str(&content, "\t");
        str_add_str_at_begin(&end_balise, "\t");
    }
    str_add_char(&line, '<');
    str_add_str(&line, parent->tag_name);
    foreach_m(parent->attributes, attr) {
        char delim = '\"';
        str_add_char(&line, ' ');
        str_add_str(&line, attr->key);
        if (attr->data != NULL) {
            str_add_char(&line, '=');
            if (str_contains_char(attr->data, '\"'))
                delim = '\'';
            str_add_char(&line, delim);
            str_add_str(&line, attr->data);
            str_add_char(&line, delim);
        }
    }
    if ((parent->content == NULL || str_is_empty(parent->content)) && parent->children->size == 0) {
        str_add_str(&line, "/>");
        text_add_line(text, line);
        kfree(content);
        kfree(line);
        kfree(end_balise);
        return;
    }
    str_add_char(&line, '>');
    text_add_line(text, line);
    kfree(line);
    if (parent->content != NULL && !str_is_empty(parent->content)) {
        str_add_str(&content, parent->content);
        text_add_line(text, content);
    }
    foreach_l(parent->children, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        rewrite_xml(text, xml_nd, increment + 1);
    }
    text_add_line(text, end_balise);
    kfree(end_balise);
    kfree(content);
}

void xml_save(xml_f *xml) {
    if (xml == NULL)
        return;
    text_t txt = text_create();

    generate_xml_header(txt, xml);
    foreach_l(xml->xml, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        rewrite_xml(txt, xml_nd, 0);
    }
    text_write(txt, xml->path, false);
    text_destroy(txt);
}
