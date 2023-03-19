/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_parse
*/

#include "kapparser.h"
#include <stdio.h>

private yaml_node_t *yaml_parse(yaml_f *file, cstring key);

private void look_for_value_yml(text_t txt, ksize_t line, void **value, yml_content_data_t *type) {
    string tmp_value = str_create_string(text_get_line(txt, line));

    while (str_len(tmp_value) > 0 && !str_start_cwith(tmp_value, ':'))
        str_remove_char_at(&tmp_value, 0);
    str_remove_char_at(&tmp_value, 0);
    while (str_len(tmp_value) > 0 && str_start_cwith(tmp_value, ' '))
        str_remove_char_at(&tmp_value, 0);
    string delimiter = str_create_char(tmp_value[0]);
    if (str_is_equal(delimiter, "\"", true) || str_is_equal(delimiter, "'", true)) {
        *value = str_value_between(tmp_value, delimiter, delimiter);
        *type = YML_STRING;
        kfree(tmp_value);
        kfree(delimiter);
        return;
    }
    if (str_is_equal(delimiter, "[", true)) {
        *type = YML_LIST;
        string inside_array = str_value_between(tmp_value, "[", "]");
        *value = str_split(inside_array, ',');
        foreach_l(((list_t *)*value), node) {
            string str = node->data;
            while (str_len(str) > 0 && str_start_cwith(str, ' '))
                str_remove_char_at(&str, 0);
            while (str_len(str) > 0 && str_end_cwith(str, ' '))
                str_remove_char_at(&str, str_len(str) - 1);
            node->data = str;
        }
        kfree(inside_array);
        kfree(tmp_value);
        kfree(delimiter);
        return;
    }
    ksize_t nb_spaces = str_count_char_from(text_get_line(txt, line), ' ', 0);
    nb_spaces += 2;
    line++;
    list_t *list = list_create();
    while (str_count_char_from(text_get_line(txt, line), ' ', 0) == nb_spaces) {
        if (!str_start_cwith_from(text_get_line(txt, line), '-', nb_spaces))
            break;
        list_node_t *node = list_push(list, str_create_string(text_get_line(txt, line) + nb_spaces + 2));
        node->destroy = &kapfree;
        line++;
    }
    if (list_size(list) > 0) {
        *value = list;
        *type = YML_LIST;
        kfree(tmp_value);
        kfree(delimiter);
        return;
    }
    list_destroy(list);
    kfree(delimiter);
    kfree(tmp_value);
    *type = YML_STRING;
}

private yaml_node_t *create_node_yml(text_t txt, ksize_t line, cstring key) {
    yaml_node_t *node = malloc(sizeof(yaml_node_t));

    node->key = str_create_string(key);
    node->value = NULL;
    node->line = line;
    node->children = list_create();
    node->parent = NULL;
    node->modified = false;
    node->destroyed = false;
    look_for_value_yml(txt, line, &node->value, &node->type);
    return node;
}

private void manage_node_parent(yaml_node_t *created, yaml_f *yml, cstring key) {
    text_t keys = str_split(key, '.');
    string tmp_key = str_create_empty();
    yaml_node_t *parent = NULL;

    if (keys->size == 1) {
        list_node_t *node = list_push(yml->yaml, created);
        node->destroy = &yaml_destroy_node;
        text_destroy(keys);
        kfree(tmp_key);
        return;
    }
    foreach_l(keys, k) {
        if (str_len(tmp_key) > 0) {
            str_add_str(&tmp_key, ".");
        }
        str_add_str(&tmp_key, (string)k->data);
        if (str_is_equal(tmp_key, key, true)) {
            created->parent = parent;
            list_node_t *node = list_push(parent->children, created);
            node->destroy = &yaml_destroy_node;
            break;
        }
        parent = yaml_parser(yml, tmp_key);
    }
    text_destroy(keys);
    kfree(tmp_key);
}

private yaml_node_t *yaml_parse(yaml_f *file, cstring key) {
    text_t keys = str_split(key, '.');
    string tmp_key = str_create_string(text_get_line(keys, 0));
    ksize_t index_key = 0;
    bool create_node = false;

    for (ksize_t i = 0; i < file->file_content->size; i++) {
        string line = text_get_line(file->file_content, i);
        ksize_t nb_spaces = str_count_char_from(line, ' ', 0);
        string without_spaces = str_create_string(line + nb_spaces);

        if (nb_spaces == index_key * 2 && str_start_with(without_spaces, text_get_line(keys, index_key))) {
            if (str_start_cwith_from(without_spaces, ':', str_len(text_get_line(keys, index_key)))) {
                index_key++;
                if (index_key == keys->size) {
                    yaml_node_t *node = create_node_yml(file->file_content, i, key);
                    manage_node_parent(node, file, key);
                    text_destroy(keys);
                    kfree(tmp_key);
                    kfree(without_spaces);
                    return node;
                }
            }
        }
        kfree(without_spaces);
    }
    kfree(tmp_key);
    text_destroy(keys);
    return NULL;
}

yaml_node_t *yaml_parser(yaml_f *file, cstring key) {
    yaml_node_t *node = NULL;
    string empty = str_create_empty();

    if (file == NULL || key == NULL || str_is_empty(key)) {
        kfree(empty);
        return NULL;
    }
    foreach_l(file->yaml, n) {
        node = yaml_key_exists(n->data, key, empty);
        if (node != NULL) {
            kfree(empty);
            return node;
        }
    }
    kfree(empty);
    node = yaml_parse(file, key);
    if (node == NULL) {
        node = create_node_yml(file->file_content, 0, key);
        manage_node_parent(node, file, key);
    }
    return node;
}
