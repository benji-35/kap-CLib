/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_parse
*/

#include "kapparser.h"
#include <stdio.h>

private void xml_parse_from(xml_node_t *parent, xml_f *file, ksize_t line, ksize_t max);

private bool close_on_same_line(cstring line) {
    string end_without_o = str_copy(line);
    bool result = false;

    while (end_without_o[str_len(end_without_o) - 1] == ' ' && str_len(end_without_o) > 0)
        str_remove_char_at(&end_without_o, str_len(end_without_o) - 1);
    ksize_t len = str_len(end_without_o);
    result = str_end_with(end_without_o, "/>");
    kfree(end_without_o);
    return result;
}

private string copy_without_spaces(cstring str) {
    string result = str_copy(str);

    str_remove_first_chars(&result, ' ');
    str_remove_first_chars(&result, '\t');
    return result;
}

private ksize_t get_end_balise_pos(text_t lines, cstring tag, ksize_t line) {
    int amount_found = 0;
    string end_balise = str_create_string("</");
    string start_balise = str_create_string("<");

    if (close_on_same_line(text_get_line(lines, line)) == true) {
        kfree(end_balise);
        kfree(start_balise);
        return line;
    }
    line++;
    str_add_str(&end_balise, tag);
    str_add_str(&start_balise, tag);
    str_add_char(&end_balise, '>');
    line++;
    for(; line < lines->size; line++) {
        string line_str = copy_without_spaces(text_get_line(lines, line));
        if (str_start_with(line_str, end_balise) == true) {
            if (amount_found == 0) {
                kfree(end_balise);
                kfree(line_str);
                kfree(start_balise);
                return line;
            }
            amount_found--;
        } else if (str_start_with(line_str, start_balise) == true)
            amount_found++;
        kfree(line_str);
    }
    kfree(end_balise);
    kfree(start_balise);
    return lines->size;
}

private void xml_get_attributes(cstring line, xml_node_t *node) {
    ksize_t index = str_index_of_string(line, node->tag_name);
    node->attributes = map_create();
    index += str_len(node->tag_name) + 1;
    if (index >= str_len(line))
        return;
    for (; index < str_len(line); index++) {
        if (line[index] == '>')
            break;
        if (line[index] == ' ' || line[index] == '\t')
            continue;
        string key = str_create_empty();
        string value = NULL;
        while (line[index] != '=') {
            if (index >= str_len(line) || line[index] == ' ' || line[index] == '\t' || line[index] == '>')
                break;
            str_add_char(&key, line[index]);
            index++;
        }
        index++;
        if (index < str_len(line)) {
            string delim = str_create_char(line[index]);
            if (str_is_equal(delim, "'", true) || str_is_equal(delim, "\"", true)) {
                value = str_value_between(line + index, delim, delim);
                index += str_len(value) + 2;
            }
            kfree(delim);
        }
        map_node_t *nd_mp = map_insert(node->attributes, key, value, false);
        nd_mp->destroy = &kapfree;
        kfree(key);
    }
}

private xml_node_t *xml_parse_node(xml_f *file, cstring line, ksize_t *line_index) {
    if (!str_start_with(line, "<") || str_start_with(line, "</") || str_start_with(line, "<!") || str_start_with(line, "<?"))
        return NULL;
    xml_node_t *xml_node = calloc(1, sizeof(xml_node_t));
    ksize_t end_balise = file->file_content->size;
    ksize_t end_tag = 0;

    while (line[end_tag] != ' ' && line[end_tag] != '>')
        end_tag++;
    end_tag--;
    xml_node->tag_name = str_copy_from_to(line, 1, end_tag);
    xml_node->children = list_create();
    xml_node->parent = NULL;
    xml_node->file = file;
    xml_node->destroyed = false;
    xml_get_attributes(line, xml_node);
    end_balise = get_end_balise_pos(file->file_content, xml_node->tag_name, *line_index);
    xml_parse_from(xml_node, file, (*line_index + 1), end_balise);
    *line_index = end_balise;
    return xml_node;
}

private void xml_parse_from(xml_node_t *parent, xml_f *file, ksize_t line, ksize_t max) {
    if (file == NULL || file->file_content == NULL)
        return;
    list_t *parent_list = file->xml;

    if (parent != NULL)
        parent_list = parent->children;
    for (ksize_t i = line; i < max; i++) {
        string line_str = copy_without_spaces(text_get_line(file->file_content, i));
        if (str_len(line_str) == 0) {
            kfree(line_str);
            continue;
        }
        xml_node_t *node = xml_parse_node(file, line_str, &i);
        if (node != NULL) {
            list_node_t *lnd = list_push(parent_list, node);
            lnd->destroy = &xml_node_destroy;
        }
        kfree(line_str);
    }
}

void xml_parse(xml_f *xml_file) {
    xml_parse_from(NULL, xml_file, 0, xml_file->file_content->size);
}
