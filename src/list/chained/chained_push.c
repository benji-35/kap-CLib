/*
** KAP PROJECT, 2023
** C Lib
** File description:
** chained_push
*/

#include "kaplist.h"

void list_push(list_t *list, void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));

    if (node == NULL)
        return;
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
    list->size++;
}

void list_push_front(list_t *list, void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));

    if (node == NULL)
        return;
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
    list->size++;
}
