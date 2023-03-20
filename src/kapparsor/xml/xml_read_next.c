/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_read_next
*/

#include "kapparser.h"

private bool check_version(string line, xml_f *xml_file) {
    if (xml_file->version != NULL || xml_file->encoding != NULL)
        return false;
    if (!str_start_with(line, "<?xml"))
        return false;
    ksize_t version_index = str_index_of_string(line, "version=");
    ksize_t encoding_index = str_index_of_string(line, "encoding=");
    if (version_index != str_len(line)) {
        ksize_t version_start = version_index + 9;
        ksize_t version_end = str_index_of_char_from(line, '"', version_start);
        xml_file->version = str_copy_from_to(line, version_start, version_end);
    } else
        xml_file->version = str_copy("1.0");
    if (encoding_index != str_len(line)) {
        ksize_t encoding_start = encoding_index + 10;
        ksize_t encoding_end = str_index_of_char_from(line, '"', encoding_start);
        xml_file->encoding = str_copy_from_to(line, encoding_start, encoding_end);
    } else
        xml_file->encoding = str_copy("UTF-8");
    return true;
}

private void check_tag(string line, xml_reading_t *reading) {
    if (str_start_with(line, "</"))
        reading->type = XML_END_TAG;
    else if (str_end_with(line, "/>"))
        reading->type = XML_SINGLE_TAG;
    else
        reading->type = XML_START_TAG;
}

xml_reading_t *xml_read_next(xml_f *xml_file, xml_node_t *parent, cstring line, ksize_t i) {
    xml_reading_t *reading = malloc(sizeof(xml_reading_t));
    string line_without_spaces = str_copy(line);

    str_remove_first_chars(&line_without_spaces, ' ');
    reading->content = NULL;
    reading->tag = NULL;
    reading->type = XML_MAX;
    if (xml_file == NULL || line == NULL || str_len(line) == 0)
        return reading;
    if (str_start_with(line_without_spaces, "<!--")) {
        reading->type = XML_COMMENT;
        return reading;
    }
    if (check_version(line_without_spaces, xml_file))
        return reading;
    
}
