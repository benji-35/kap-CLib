/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_map_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "kaplist.h"
#include "kapstring.h"

Test(map, create) {
    map_t *map = map_create();

    cr_assert_not_null(map);
    cr_assert_null(map->head);
    cr_assert_null(map->tail);
    map_destroy(map);
}

Test(map, add_data) {
    map_t *map = map_create();
    int *data = malloc(sizeof(int));

    *data = 42;
    map_add(map, "test", data, true);
    void *data2 = map_get(map, "test");

    cr_assert_not_null(data2);
    cr_assert_eq(*((int *)data2), 42, "Expected 42, got %d", *((int *)data2));
    map_destroy(map);
}

Test(map, add_data_no_copy) {
    map_t *map = map_create();
    int *data = malloc(sizeof(int));

    *data = 42;
    map_add(map, "test", data, false);
    void *data2 = map_get(map, "test");

    cr_assert_not_null(data2);
    cr_assert_eq(*((int *)data2), 42, "Expected 42, got %d", *((int *)data2));
    map_destroy(map);
}

Test(map, add_null_data) {
    map_t *map = map_create();

    map_add(map, "test", NULL, false);
    void *data2 = map_get(map, "test");

    cr_assert_null(data2);
    map_destroy(map);
}

Test(map, add_data_without_key) {
    map_t *map = map_create();

    map_add(map, NULL, "data failed", false);
    void *data2 = map_get(map, NULL);

    cr_assert_null(data2);
    map_destroy(map);
}

Test(map, several_datas) {
    map_t *map = map_create();
    int *data = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data = 42;
    *data2 = 43;
    *data3 = 44;
    map_add(map, "test", data, true);
    map_add(map, "test2", data2, true);
    map_add(map, "test3", data3, true);
    void *data4 = map_get(map, "test");
    void *data5 = map_get(map, "test2");
    void *data6 = map_get(map, "test3");

    cr_assert_not_null(data4);
    cr_assert_not_null(data5);
    cr_assert_not_null(data6);
    cr_assert_eq(*((int *)data4), 42, "Expected 42, got %d", *((int *)data4));
    cr_assert_eq(*((int *)data5), 43, "Expected 43, got %d", *((int *)data5));
    cr_assert_eq(*((int *)data6), 44, "Expected 44, got %d", *((int *)data6));
    map_destroy(map);
}

Test(map, several_datas_overwrite) {
    map_t *map = map_create();
    int *data = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data = 12;
    *data2 = -8;
    *data3 = 44;
    map_add(map, "test", data, true);
    map_add(map, "test", data2, true);
    map_add(map, "test", data3, true);
    void *data4 = map_get(map, "test");

    cr_assert_not_null(data4);
    cr_assert_eq(*((int *)data4), *((int *)data3), "Expected %d, got %d", *((int *)data3), *((int *)data4));
    map_destroy(map);
}

Test(map, remove_data) {
    map_t *map = map_create();
    int *data = malloc(sizeof(int));

    *data = 42;
    map_add(map, "test", data, true);
    void *data2 = map_get(map, "test");

    cr_assert_not_null(data2);
    cr_assert_eq(*((int *)data2), 42, "Expected 42, got %d", *((int *)data2));
    map_remove(map, "test");
    void *data3 = map_get(map, "test");

    cr_assert_null(data3);
    map_destroy(map);
}
