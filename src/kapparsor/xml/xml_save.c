/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_save
*/

#include "kapparser.h"

private void rewrite_xml(text_t text, xml_node_t *parent, ksize_t increment) {
    string line = str_create_empty();
    string end_balise = str_create_string("</");
    string content = str_create_string("\t");

    str_add_str(&end_balise, parent->tag_name);
    str_add_char(&end_balise, '>');
    for (ksize_t i = 0; i < increment; i++) {
        str_add_str(&line, "\t");
        str_add_str(&content, "\t");
    }
    str_add_char(&line, '<');
    str_add_str(&line, parent->tag_name);
    foreach_l(parent->attributes, attr) {
        char delim = '\"';
        str_add_char(&line, ' ');
        str_add_str(&line, attr->key);
        str_add_char(&line, '=');
        if (str_contains_char(attr->value, '\"'))
            delim = '\'';
        str_add_char(&line, delim);
        str_add_str(&line, attr->value);
        str_add_char(&line, delim);
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
        text_add_line(&line, content);
    }
    rewrite_xml(text, parent->children, increment + 1);
    text_add_line(text, end_balise);
    kfree(end_balise);
    kfree(content);
}

void xml_save(xml_f *xml) {
    if (xml == NULL)
        return;
    text_t txt = text_create();

    foreach_l(xml->xml, node) {
        xml_node_t *xml_nd = (xml_node_t *)node->data;
        rewrite_xml(txt, xml_nd, 0);
    }
    text_write(xml->path, txt);
    text_destroy(txt);
}
