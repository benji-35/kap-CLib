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
    get_xml_intel(xml);
    return xml;
}
