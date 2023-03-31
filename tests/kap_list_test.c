/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_list_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

#include "kaplist.h"
#include "kapprintf.h"

void redirect_all_stdout_list(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(test_list, create_empty_list) {
    list_t *list = list_create();

    cr_assert_not_null(list);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list_get_first(list));
    cr_assert_null(list_get_last(list));
    cr_assert_null(list_get(list, 0));
    list_destroy(list);
}

//add elements to the list
Test(test_list, add_one_data) {
    list_t *list = list_create();
    int data = 42;

    list_node_t *node = list_push(list, &data);
    cr_assert_not_null(node);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(*(int *)list->head->data, 42);
    cr_assert_eq(*(int *)list->tail->data, 42);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)node->data, 42);
    list_destroy(list);
}

Test(test_list, add_data_in_null_list) {
    list_t *list = NULL;
    int data = 42;

    list_node_t *node = list_push(list, &data);
    cr_assert_null(list);
    cr_assert_null(node);
    void *data_g = list_get(list, 0);
    cr_assert_null(data_g);
    data_g = list_get_first(list);
    cr_assert_null(data_g);
    data_g = list_get_last(list);
    cr_assert_null(data_g);
    list_destroy(list);
}

Test(test_list, add_data_front) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;

    list_push(list, &data1);
    list_node_t *node = list_push_front(list, &data2);
    cr_assert_not_null(node);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(*(int *)list_get(list, 0), 43);
    cr_assert_eq(*(int *)list_get(list, 1), 42);
}

Test(test_list, add_data_end) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;

    list_push(list, &data1);
    list_node_t *node = list_push(list, &data2);
    cr_assert_not_null(node);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
}

Test(test_list, insert_data) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_node_t *node = list_insert(list, &data3, 1);
    cr_assert_not_null(node);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 44);
    cr_assert_eq(*(int *)list_get(list, 2), 43);
}

Test(test_list, insert_data_null_list) {
    list_t *list = NULL;

    int data1 = 42;

    list_node_t *node = list_insert(list, &data1, 1);
    cr_assert_null(node);
}

Test(test_list, add_data_front_null_list) {
    list_t *list = NULL;

    int data1 = 42;

    list_node_t *node = list_push_front(list, &data1);
    cr_assert_null(node);
}

Test(test_list, last_push_insert_test) {
    list_t *list = list_create();

    list_node_t *node1 = list_push_front(list, "42");
    cr_assert_not_null(node1);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);

    list_node_t *node2 = list_insert(list, "43", 3);
    list_node_t *node0 = list_insert(list, "41", 0);

    cr_assert_not_null(node2);
    cr_assert_not_null(node0);

    cr_assert_eq(list->size, 3);
    cr_assert_str_eq((char *)list_get(list, 0), "41");
    cr_assert_str_eq((char *)list_get(list, 1), "42");
    cr_assert_str_eq((char *)list_get(list, 2), "43");
}

//concat list
Test(test_list, concat_list) {
    list_t *list1 = list_create();
    list_t *list2 = list_create();

    list_push(list1, "42");
    list_push(list1, "43");
    list_push(list2, "44");
    list_push(list2, "45");

    list_t *list3 = list_concat(list1, list2);
    cr_assert_eq(list3->size, 4);
    cr_assert_str_eq((char *)list_get(list3, 0), "42");
    cr_assert_str_eq((char *)list_get(list3, 1), "43");
    cr_assert_str_eq((char *)list_get(list3, 2), "44");
    cr_assert_str_eq((char *)list_get(list3, 3), "45");
}

Test(test_list, add_list) {
    list_t *list1 = list_create();
    list_t *list2 = list_create();

    list_push(list1, "42");
    list_push(list1, "43");
    list_push(list2, "44");
    list_push(list2, "45");

    list_add_list(list1, list2);
    cr_assert_eq(list1->size, 4);
    cr_assert_str_eq((char *)list_get(list1, 0), "42");
    cr_assert_str_eq((char *)list_get(list1, 1), "43");
    cr_assert_str_eq((char *)list_get(list1, 2), "44");
    cr_assert_str_eq((char *)list_get(list1, 3), "45");
    cr_assert_str_eq((char *)list_get_first(list1), "42");
    cr_assert_str_eq((char *)list_get_last(list1), "45");
}

Test(test_list, add_list_null_list) {
    list_t *list1 = NULL;
    list_t *list2 = list_create();

    list_push(list2, "44");
    list_push(list2, "45");

    list_add_list(list1, list2);
    cr_assert_null(list1);
}

Test(test_list, add_list_null_list2) {
    list_t *list1 = list_create();
    list_t *list2 = NULL;

    list_push(list1, "42");
    list_push(list1, "43");

    list_add_list(list1, list2);
    cr_assert_eq(list1->size, 2);
    cr_assert_str_eq((char *)list_get(list1, 0), "42");
    cr_assert_str_eq((char *)list_get(list1, 1), "43");
}

//list pop & clear

Test(test_list, pop_data) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_push(list, &data3);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);

    list_pop(list);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
}

Test(test_list, pop_data_null_list) {
    list_t *list = NULL;

    list_pop(list);
    cr_assert_null(list);
}

Test(test_list, pop_front_data) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_push(list, &data3);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);

    list_pop_front(list);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(*(int *)list_get(list, 0), 43);
    cr_assert_eq(*(int *)list_get(list, 1), 44);
}

Test(test_list, clear_list) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_push(list, &data3);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);

    list_clear(list);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
}

Test(test_list, clear_list_null_list) {
    list_t *list = NULL;

    list_clear(list);
    cr_assert_null(list);
}

//list destroy data
Test(test_list, destroy_data) {
    list_t *list = list_create();

    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data1 = 42;
    *data2 = 43;
    *data3 = 44;

    list_node_t *node = list_push(list, data1);
    node->destroy = &kapfree;
    node = list_push(list, data2);
    node->destroy = &kapfree;
    node = list_push(list, data3);
    node->destroy = &kapfree;

    list_destroy(list);
    cr_assert_eq(1, 1);
}

//reverse list
Test(test_list, reverse_list) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_push(list, &data3);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);

    list_reverse(list);
    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 44);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 42);
}

//check list empty
Test(test_list, check_list_empty) {
    list_t *list = list_create();

    cr_assert_eq(list_is_empty(list), true);

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data2);
    list_push(list, &data3);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);

    cr_assert_eq(list_is_empty(list), false);
}

private int sort_int(const void *a, const void *b) {
    int *a_int = (int *)a;
    int *b_int = (int *)b;

    if (*a_int < *b_int) {
        return -1;
    } else if (*a_int > *b_int) {
        return 1;
    } else {
        return 0;
    }
}

private bool int_equals(void *a, void *b) {
    int *a_int = (int *)a;
    int *b_int = (int *)b;

    return *a_int == *b_int;
}

Test(test_list, simply_sort_list) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_push(list, &data1);
    list_push(list, &data3);
    list_push(list, &data2);

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 44);
    cr_assert_eq(*(int *)list_get(list, 2), 43);

    list_sort(list, &sort_int);
    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
    cr_assert_eq(*(int *)list_get(list, 2), 44);
}

// remove from data
Test(test_list, simply_destroy_data) {
    list_t *list = list_create();

    int data1 = 42;
    int data2 = 43;
    int data3 = 44;

    list_node_t *node1 = list_push(list, &data1);
    list_node_t *node2 = list_push(list, &data3);
    list_node_t *node3 = list_push(list, &data2);

    node1->equal = &int_equals;
    node2->equal = &int_equals;
    node3->equal = &int_equals;

    cr_assert_eq(list->size, 3);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 44);
    cr_assert_eq(*(int *)list_get(list, 2), 43);

    list_remove_data(list, &data3);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(*(int *)list_get(list, 0), 42);
    cr_assert_eq(*(int *)list_get(list, 1), 43);
}
