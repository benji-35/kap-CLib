/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_save
*/

#include "kapparser.h"

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

private void add_keys_parent(yaml_node_t *node, list_t *list) {
    if (node == NULL)
        return;
    if (node->parent != NULL) {
        add_keys_parent(node->parent, list);
    }
    list_push(list, node->key);
}

private void write_yml_line(text_t *txt, ksize_t line, yaml_node_t *node, ksize_t spaces) {
    string new_line = str_create_empty();

    while (spaces > 0) {
        str_add_char(&new_line, ' ');
        spaces--;
    }
    str_add_str(&new_line, node->key);
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
    text_set_line(*txt, new_line, line);
    kfree(new_line);
}

private void apply_modifications(yaml_node_t *node, text_t *txt) {
    text_t keys = text_create();
    ksize_t nb = nb_parent(node);
    ksize_t index_key = 0;

    add_keys_parent(node, keys);
    for(ksize_t i = 0; i < ((text_t)*txt)->size; i++) {
        if (node->value == NULL)
            break;
        string line = text_get_line(*txt, i);
        ksize_t nb_spaces = str_count_char_from(line, ' ', 0);
        string without_spaces = str_create_string(line + nb_spaces);

        if (nb_spaces == index_key * 2 && str_start_with(without_spaces, text_get_line(keys, index_key))) {
            if (str_start_cwith_from(without_spaces, ':', str_len(text_get_line(keys, index_key)))) {
                index_key++;
                if (index_key == keys->size) {
                    write_yml_line(txt, i, node, nb_spaces);
                    kfree(without_spaces);
                    break;
                }
            }
        }
        kfree(without_spaces);
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
