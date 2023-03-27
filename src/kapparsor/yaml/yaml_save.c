/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_save
*/

#include "kapparser.h"
#include <stdio.h>

private ksize_t nb_parent(yaml_node_t *node) {
    ksize_t nb = 0;

    if (node == NULL)
        return 0;
    if (node->parent != NULL) {
        nb++;
        nb += nb_parent(node->parent);
    }
    return nb;
}

private string get_string_yml_write(yaml_node_t *node, ksize_t spaces) {
    string new_line = str_create_empty();
    text_t keys = str_split(node->key, '.');
    string key = text_get_line(keys, list_size(keys) - 1);

    while (spaces > 0) {
        str_add_char(&new_line, ' ');
        spaces--;
    }
    str_add_str(&new_line, key);
    str_add_char(&new_line, ':');
    if (node->type == YML_STRING) {
        char limiter = '"';
        if (str_contains_char(node->value, '"'))
            limiter = '\'';
        str_add_char(&new_line, ' ');
        str_add_char(&new_line, limiter);
        str_add_str(&new_line, node->value);
        str_add_char(&new_line, limiter);
    } else if (node->type == YML_LIST) {
        str_add_str(&new_line, " [");
        for (ksize_t i = 0; i < ((list_t *)node->value)->size; i++) {
            if (i > 0)
                str_add_str(&new_line, ", ");
            str_add_str(&new_line, text_get_line(node->value, i));
        }
        str_add_str(&new_line, "]");
    }
    text_destroy(keys);
    return new_line;
}

private void write_yml_line(text_t *txt, ksize_t line, yaml_node_t *node, ksize_t spaces) {
    string new_line = NULL;

    if (node->modified == false)
        return;
    new_line = get_string_yml_write(node, spaces);
    if (node->destroyed == true || node->value == NULL) {
        text_remove_line(*txt, line);
    } else {
        text_set_line(*txt, new_line, line);
    }
    node->modified = false;
    node->line = line;
    kfree(new_line);
}

private void create_new_lines_yml(text_t *txt, yaml_node_t *node, ksize_t spaces) {
    ksize_t line = 0;

    if (node->destroyed == true)
        return;
    if (node->parent != NULL) {
        line = node->parent->line + 1;
    } else {
        line = ((text_t)*txt)->size;
    }
    text_add_line_at(*txt, "", line);
    write_yml_line(txt, line, node, spaces);
}

private void apply_modifications(yaml_node_t *node, text_t *txt) {
    text_t keys = str_split(node->key, '.');
    ksize_t nb = nb_parent(node);
    ksize_t index_key = 0;
    bool found = false;

    for(ksize_t i = 0; i < ((text_t)*txt)->size; i++) {
        if (node->modified == false) {
            found = true;
            break;
        }
        string line = text_get_line(*txt, i);
        ksize_t nb_spaces = str_count_char_from(line, ' ', 0);
        string without_spaces = str_create_string(line + nb_spaces);

        if (nb_spaces == index_key * 2 && str_start_with(without_spaces, text_get_line(keys, index_key))) {
            if (str_start_cwith_from(without_spaces, ':', str_len(text_get_line(keys, index_key)))) {
                index_key++;
                if (index_key == keys->size) {
                    write_yml_line(txt, i, node, nb_spaces);
                    kfree(without_spaces);
                    found = true;
                    break;
                }
            }
        }
        kfree(without_spaces);
    }
    if (found == false) {
        create_new_lines_yml(txt, node, (keys->size - 1) * 2);
    }
    text_destroy(keys);
    foreach_l(node->children, child) {
        apply_modifications(child->data, txt);
    }
}

void yaml_save(yaml_f *yaml) {
    if (yaml == NULL || list_size(yaml->yaml) == 0)
        return;
    foreach_l(yaml->yaml, node) {
        apply_modifications(node->data, &yaml->file_content);
    }
    text_write(yaml->file_content, yaml->path, false);
}
