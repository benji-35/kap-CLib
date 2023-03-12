/*
** KAP PROJECT, 2023
** C Lib
** File description:
** chained_push
*/

#include "kaplist.h"

list_node_t *list_push(list_t *list, void *data) {
    list_node_t *node = calloc(1, sizeof(list_node_t));

    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    node->head = list->head;
    if (list->tail != NULL)
        list->tail->next = node;
    list->tail = node;
    if (list->head == NULL) {
        list->head = node;
        node->head = node;
    }
    node->destroy = NULL;
    node->equal = NULL;
    node->print = NULL;
    list->size++;
    return node;
}

list_node_t *list_push_front(list_t *list, void *data) {
    list_node_t *node = calloc(1, sizeof(list_node_t));

    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = list->head;
    node->prev = NULL;
    node->head = list->head;
    if (list->head != NULL)
        list->head->prev = node;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
        node->head = node;
    }
    node->destroy = NULL;
    node->equal = NULL;
    node->print = NULL;
    list->size++;
    return node;
}

private list_node_t *manage_insert_node_chained(list_t *list,
    list_node_t *node, ksize_t index) {
    list_node_t *tmp = list->head;

    for (ksize_t i = 0; i < index; i++)
        tmp = tmp->next;
    node->next = tmp;
    node->prev = tmp->prev;
    node->head = list->head;
    tmp->prev->next = node;
    tmp->prev = node;
    list->size++;
    return node;
}

list_node_t *list_insert(list_t *list, void *data, ksize_t index) {
    list_node_t *node = calloc(1, sizeof(list_node_t));
    if (node == NULL)
        return NULL;
    node->data = data;
    node->destroy = NULL;
    node->equal = NULL;
    node->print = NULL;
    if (index >= list->size) {
        kfree(node);
        return list_push(list, data);
    }
    if (index == 0) {
        kfree(node);
        return list_push_front(list, data);
    }
    return manage_insert_node_chained(list, node, index);
}
