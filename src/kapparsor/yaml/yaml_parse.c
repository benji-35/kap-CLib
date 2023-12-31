/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_parse
*/

#include "kapparser.h"
#include <stdio.h>

private void create_all_children(yaml_f *file, ksize_t *line, yaml_node_t *parent);
private void yml_check_list(yaml_node_t *node, yaml_f *file, ksize_t *line);
private void yml_check_string(yaml_node_t *node, yaml_f *file, ksize_t line);

private ksize_t nb_first_spaces(cstring str) {
    ksize_t result = 0;

    if (str == NULL || str_is_empty(str))
        return 0;
    for(ksize_t i = 0; i < str_len(str); i++) {
        if (str[i] == ' ')
            result++;
        else
            break;
    }
    return result;
}

private yaml_node_t *yaml_find_parent(yaml_f *file, cstring key) {
    yaml_node_t *result = NULL;
    string key_parent = str_create_empty();
    text_t keys = str_split(key, '.');

    if (file == NULL || key == NULL || str_is_empty(key) || str_contains_char(key, '.') == false) {
        text_destroy(keys);
        kfree(key_parent);
        return NULL;
    }
    for(ksize_t i = 0; i < keys->size - 1; i++) {
        if (i > 0)
            str_add_char(&key_parent, '.');
        str_add_str(&key_parent, text_get_line(keys, i));
    }
    result = yaml_parser(file, key_parent);
    kfree(key_parent);
    text_destroy(keys);
    return result;
}

private void yml_check_string(yaml_node_t *node, yaml_f *file, ksize_t line) {
    if (node == NULL || node->type == YML_LIST)
        return;
    string line_s = str_copy(text_get_line(file->file_content, line));
    ksize_t index_eq = str_index_of_string(line_s, ": ");
    if (index_eq == str_len(line_s)) {
        node->type = YML_OBJECT;
        kfree(line_s);
        return;
    }
    index_eq += 2;
    while (line_s[index_eq] == ' ')
        index_eq++;
    string sep = str_create_char(line_s[index_eq]);
    if (str_is_equal(sep, "\"", true) == true || str_is_equal(sep, "'", true) == true)
        node->value = str_value_between(line_s, sep, sep);
    else
        node->value = str_copy_from_to(line_s, index_eq, str_len(line_s));
    kfree(sep);
    kfree(line_s);
}

private void yml_check_list(yaml_node_t *node, yaml_f *file, ksize_t *line) {
    string line_s = text_get_line(file->file_content, *line);
    ksize_t index_eq = str_index_of_string(line_s, ":");
    text_t list = text_create();
    if (index_eq == str_len(line_s) || index_eq == str_len(line_s) - 2) {
        ksize_t n_line = *line + 1;
        string txt_line = text_get_line(file->file_content, n_line);
        string n_line_s = str_copy_from_to(txt_line, nb_first_spaces(txt_line), str_len(txt_line));        
        while (n_line_s != NULL && n_line_s[0] == '-' && n_line < file->file_content->size) {
            string cpy = str_copy_from_to(n_line_s, 2, str_len(n_line_s));
            text_add_line(list, cpy);
            kfree(n_line_s);
            kfree(cpy);
            n_line++;
            txt_line = text_get_line(file->file_content, n_line);
            n_line_s = str_copy_from_to(txt_line, nb_first_spaces(txt_line), str_len(txt_line));
        }
        kfree(n_line_s);
    } else if (line_s[index_eq + 2] == '[') {
        string str_content = str_value_between(line_s, "[", "]");
        text_t content = str_split(str_content, ',');
        for(ksize_t i = 0; i < content->size; i++) {
            string cpy = str_copy(text_get_line(content, i));
            str_remove_first_chars(&cpy, ' ');
            text_add_line(list, cpy);
            kfree(cpy);
        }
        text_destroy(content);
        kfree(str_content);
    }
    if (list_size(list) == 0)
        list_destroy(list);
    else {
        node->type = YML_LIST;
        node->value = list;
    }
}

private yaml_node_t *create_yaml_node(yaml_node_t *parent, yaml_f *yml, ksize_t *line) {
    yaml_node_t *node = calloc(1, sizeof(yaml_node_t));
    ksize_t nb_o = nb_first_spaces(text_get_line(yml->file_content, *line));
    ksize_t value_index = str_index_of_char(text_get_line(yml->file_content, *line), ':');

    if (yml == NULL || line == NULL || *line >= yml->file_content->size) {
        kfree(node);
        return NULL;
    }
    node->key = str_copy_from_to(text_get_line(yml->file_content, *line), nb_o, value_index - 1);
    node->value = NULL;
    node->type = YML_STRING;
    node->children = list_create();
    node->parent = parent;
    node->destroyed = false;
    node->line = *line;
    node->modified = false;
    if (node->key == NULL) {
        list_destroy(node->children);
        kfree(node);
        return NULL;
    }
    if (node->parent != NULL) {
        str_add_str_at_begin(&node->key, ".");
        str_add_str_at_begin(&node->key, node->parent->key);
        list_node_t *l_nd = list_push(node->parent->children, node);
        l_nd->destroy = &yaml_destroy_node;
    } else {
        list_node_t *l_nd = list_push(yml->yaml, node);
        l_nd->destroy = &yaml_destroy_node;
    }
    yml_check_list(node, yml, line);
    yml_check_string(node, yml, *line);
    ksize_t n_line = *line + 1;
    yml->last_added = node;
    create_all_children(yml, &n_line, node);
    *line = n_line;
    return node;
}

private void create_all_children(yaml_f *file, ksize_t *line, yaml_node_t *parent) {
    if (file == NULL || line == NULL || parent == NULL || *line >= file->file_content->size)
        return;
    text_t keys = str_split(parent->key, '.');
    ksize_t nb_spaces_parent = (keys->size - 1) * 2;

    for(ksize_t i = *line; i < file->file_content->size; i++) {
        *line = i;
        if (str_contains_char(text_get_line(file->file_content, i), ':') == false)
            continue;
        ksize_t nb_o = nb_first_spaces(text_get_line(file->file_content, i));
        if (nb_o == 0)
            break;
        if (nb_o == nb_spaces_parent + 2) {
            yaml_node_t *node = create_yaml_node(parent, file, line);
            node->parent = parent;
        } else if (nb_o < nb_spaces_parent + 2)
            break;
    }
    text_destroy(keys);
}

private yaml_node_t *yml_create_new_object(yaml_f *file, cstring key) {
    if (file == NULL || key == NULL)
        return NULL;
    yaml_node_t *node = calloc(1, sizeof(yaml_node_t));
    yaml_node_t *parent = yaml_find_parent(file, key);
    if (node == NULL)
        return NULL;
    node->key = str_copy(key);
    node->value = NULL;
    node->type = YML_OBJECT;
    node->destroyed = true;
    node->modified = true;
    node->children = list_create();
    node->parent = parent;
    list_node_t *lnode = NULL;
    if (parent != NULL) {
        lnode = list_push(parent->children, node);
    } else {
        lnode = list_push(file->yaml, node);
    }
    lnode->destroy = &yaml_destroy_node;
    return node;
}

private yaml_node_t *yaml_parse(yaml_f *file, cstring key) {
    yaml_node_t *node = NULL;
    yaml_node_t *parent = yaml_find_parent(file, key);
    text_t keys = str_split(key, '.');
    ksize_t nb_o_needed = (keys->size - 1) * 2;

    if (parent == NULL && keys->size > 1) {
        text_destroy(keys);
        return NULL;
    }
    for (ksize_t i = file->line_read; i < file->file_content->size; i++) {
        if (str_contains_char(text_get_line(file->file_content, i), ':') == false)
            continue;
        node = create_yaml_node(parent, file, &i);
        if (node != NULL && str_is_equal(node->key, key, true)) {
            file->line_read = i;
            text_destroy(keys);
            return node;
        }
    }
    text_destroy(keys);
    return NULL;
}

yaml_node_t *yaml_parser(yaml_f *file, cstring key) {
    yaml_node_t *node = NULL;

    if (file == NULL || key == NULL || str_is_empty(key))
        return NULL;
    node = yaml_key_exists_file(file, key);
    if (node == NULL)
        node = yaml_parse(file, key);
    if (node == NULL)
        node = yaml_key_exists_file(file, key);
    if (node == NULL)
        node = yml_create_new_object(file, key);
    return node;
}
