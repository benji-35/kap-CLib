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
    xml_f *xml = malloc(sizeof(xml_f));

    // if (xml == NULL)
    //     return NULL;
    // xml->path = str_copy(path);
    // xml->file_content = text_read(path);
    // xml->xml = xml_parse(xml);
    // get_xml_intel(xml);
    // if (xml->version == NULL)
    //     xml->version = str_copy("1.0");
    // if (xml->encoding == NULL)
    //     xml->encoding = str_copy("UTF-8");
    return xml;
}
