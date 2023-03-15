/*
** KAP PROJECT, 2023
** C Lib
** File description:
** xml_parse
*/

#include "kapparser.h"

#include <stdio.h>

private map_t *get_balise_attributes(cstring line, ksize_t index) {
    string att_name = str_create_empty();
    string att_value = str_create_empty();
    map_t *attributes = map_create();
    bool is_name = true;
    char limitter = ' ';

    for (ksize_t i = index; i < str_len(line); i++) {
        if (line[i] == ' ') {
            if (is_name && str_len(att_name) > 0) {
                map_insert(attributes, str_copy(att_name), "", true);
                str_clear(&att_name);
                continue;
            }
            if (is_name && str_len(att_name) == 0)
                continue;
        }
        if (line[i] == limitter && !is_name) {
            string cpy_name = str_copy(att_name);
            map_insert(attributes, cpy_name, str_copy(att_value), false);
            str_clear(&att_name);
            str_clear(&att_value);
            is_name = true;
            kfree(cpy_name);
            continue;
        }
        if (is_name && line[i] == '=') {
            is_name = false;
            limitter = line[i + 1];
            i++;
            continue;
        }
        if (is_name)
            str_add_char(&att_name, line[i]);
        else
            str_add_char(&att_value, line[i]);
    }
    kfree(att_name);
    kfree(att_value);
    return attributes;
}

private xml_balise_t get_balise_intel(cstring balise) {
    xml_balise_t balise_intel;
    balise_intel.name = str_create_empty();
    ksize_t i = 0;

    if (balise == NULL)
        return balise_intel;
    for (; i < str_len(balise); i++) {
        if (balise[i] == '<' || balise[i] == '>')
            continue;
        if (balise[i] == ' ') {
            if (str_len(balise_intel.name) > 0)
                break;
            continue;
        }
        str_add_char(&balise_intel.name, balise[i]);
    }
    balise_intel.attributes = get_balise_attributes(balise, i);
    return balise_intel;
}

private xml_node_t *get_node_intel(cstring node, cstring balise_name, xml_balise_t intel) {
    xml_node_t *node_intel = malloc(sizeof(xml_node_t));

    if (node_intel == NULL)
        return NULL;
    string bal_nme = str_create_string("</");
    str_add_str(&bal_nme, balise_name);
    str_add_char(&bal_nme, '>');
    string balise_content = str_value_between(node, ">", bal_nme);
    node_intel->name = intel.name;
    node_intel->attributes = intel.attributes;

    kfree(bal_nme);
    kfree(balise_content);
    return node_intel;
}

private list_t *getting_xml_node(cstring file, ksize_t index, cstring parent) {
    list_t *nodes = list_create();
    string end_parent_balise = str_create_string("</");

    str_add_str(&end_parent_balise, parent);
    str_add_char(&end_parent_balise, '>');
    for (ksize_t i = index; i < str_len(file); i++) {
        if (!str_is_empty(parent) && str_is_equal_from(file, end_parent_balise, i, true)) {
            kfree(end_parent_balise);
            return nodes;
        }
        if (file[i] == '<' && i < str_len(file) - 2 && file[i + 1] != '/' && file[i + 1] != '?' && file[i + 1] != '!') {            
            string balise_content = str_value_between(file + i, "<", ">");
            xml_balise_t balise = get_balise_intel(balise_content);
            xml_node_t *new_node = malloc(sizeof(xml_node_t));
            new_node->name = balise.name;
            new_node->attributes = balise.attributes;
            new_node->children = getting_xml_node(file, i + str_len(balise_content) + 2, balise.name);
            list_node_t *node = list_push(nodes, new_node);
            node->destroy = &destroy_xml_node;
            node->print = &xml_print_node;
            kfree(balise_content);
        }
    }
    kfree(end_parent_balise);
    return nodes;
}

list_t *xml_parse(xml_f *xml) {
    string all_lines = text_to_string(xml->file_content);
    list_t *result = list_create();

    if (all_lines == NULL)
        return NULL;
    list_add_list(result, getting_xml_node(all_lines, 0, ""));
    kfree(all_lines);
    return result;    
}
