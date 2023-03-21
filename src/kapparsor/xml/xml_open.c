/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_open
*/

#include "kapparser.h"

#include <stdio.h>

private void get_xml_intel(xml_f *xml) {
    string all_lines = text_to_string(xml->file_content);
    string xml_intel = str_value_between(all_lines, "<?xml", "?>");

    xml->version = str_value_between(xml_intel, "version=\"", "\"");
    xml->encoding = str_value_between(xml_intel, "encoding=\"", "\"");
    if (str_is_empty(xml->version)) {
        kfree(xml->version);
        xml->version = NULL;
    }
    if (xml->version == NULL)
        xml->version = str_copy("1.0");
    if (str_is_empty(xml->encoding)) {
        kfree(xml->encoding);
        xml->encoding = NULL;
    }
    if (xml->encoding == NULL)
        xml->encoding = str_copy("UTF-8");
    kfree(all_lines);
    kfree(xml_intel);
}

xml_f *xml_open(cstring path) {
    xml_f *xml = calloc(1, sizeof(xml_f));

    if (path == NULL) {
        kfree(xml);
        return NULL;
    }
    if (xml == NULL)
        return NULL;
    xml->path = str_copy(path);
    xml->file_content = text_read(path);
    get_xml_intel(xml);
    xml->xml = list_create();
    xml_parse(xml);
    return xml;
}
