/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_yml_tests
*/

#include <criterion/criterion.h>
#include "kapparser.h"

Test(kap_yml_tests, test_open_close) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");

    cr_assert_not_null(yml);
    cr_assert_eq(YAML_FAILED(yml), false);
    yaml_close(yml);
    cr_assert_eq(YAML_FAILED(yml), true);
}

Test(kap_yml_tests, test_open_close_null) {
    yaml_f *yml = yaml_open(NULL);

    cr_assert_eq(YAML_FAILED(yml), true);
    yaml_close(yml);
}

Test(kap_yml_tests, get_string_value) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    string str = yaml_get(yml, "test.value1");
    string result = "This is a test";

    cr_assert_str_eq(str, result, "Expected: %s, Got: %s", result, str);
    yaml_close(yml);
}

Test(kap_yml_tests, get_string_value_null) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    string str = yaml_get(yml, NULL);
    string result = NULL;

    cr_assert_eq(str, result, "Expected: %s, Got: %s", result, str);
    yaml_close(yml);
}

Test(kap_yml_tests, get_list_value) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    text_t list = yaml_get_list(yml, "test.obj1.list");
    list_t *result = list_create();

    list_push(result, "v1");
    list_push(result, "v2");
    cr_assert_eq(list->size, result->size, "Expected: %d, Got: %d", result->size, list->size);
    for(ksize_t i = 0; i < result->size; i++) {
        string str1 = list_get(list, i);
        string str2 = list_get(result, i);
        cr_assert_str_eq(str1, str2, "Expected: %s, Got: %s", str2, str1);
    }
    list_destroy(result);
    yaml_close(yml);
}

Test(kap_yml_tests, get_list_value_null) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    text_t list = yaml_get_list(yml, NULL);
    text_t result = NULL;

    cr_assert_eq(list, result, "Expected: %s, Got: %s", result, list);
    yaml_close(yml);
}

Test(kap_yml_tests, get_list_value_null_file) {
    text_t list = yaml_get_list(NULL, "no.file");
    text_t result = NULL;

    cr_assert_eq(list, result, "Expected: %s, Got: %s", result, list);
}

Test(kap_yml_tests, get_string_value_null_file) {
    string list = yaml_get(NULL, "no.file");
    string result = NULL;

    cr_assert_eq(list, result, "Expected: %s, Got: %s", result, list);
}

Test(kap_yml_tests, get_list_value_null_node_destroyed) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    text_t result = NULL;

    yaml_set(yml, "test.obj1.list", NULL);
    text_t list = yaml_get_list(yml, "test.obj1.list");

    cr_assert_eq(list, result, "Expected: %p, Got: %p", result, list);
    yaml_close(yml);
}

Test(kap_yml_tests, destroy_node_null) {
    yaml_destroy_node(NULL);
}

Test(kap_yml_tests, set_new_string_value) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    string result = "This is a test";
    string path = "test.test_value";

    yaml_set(yml, path, result);
    string str = yaml_get(yml, path);
    cr_assert_str_eq(str, result, "Expected: %s, Got: %s", result, str);
    yaml_close(yml);
}

Test(kap_yml_tests, set_new_string_value_save_destroy) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    string result = "This is a test";

    yaml_set(yml, "test.test_value", result);
    string str = yaml_get(yml, "test.test_value");
    cr_assert_str_eq(str, result, "Expected: %s, Got: %s", result, str);
    yaml_save(yml);
    yaml_close(yml);

    yaml_f *yml2 = yaml_open("./tests/configs/test_yaml.yml");
    string str3 = yaml_get(yml2, "test.test_value");
    cr_assert_str_eq(str3, result, "Expected: %s, Got: %s", result, str3);
    yaml_set(yml2, "test.test_value", NULL);
    string str5 = yaml_get(yml2, "test.test_value");
    cr_assert_eq(str5, NULL, "Expected: %s, Got: %s", NULL, str5);
    yaml_save(yml2);
    yaml_close(yml2);

    yaml_f *yml3 = yaml_open("./tests/configs/test_yaml.yml");
    string str4 = yaml_get(yml3, "test.test_value");
    cr_assert_eq(str4, NULL, "Expected: %s, Got: %s", NULL, str4);
    yaml_close(yml3);
}

Test(kap_yml_test, close_yaml_null) {
    yaml_close(NULL);
}

Test(kap_yml_test, yaml_key_exists1) {
    yaml_node_t *node = yaml_key_exists(NULL, "test", str_create_empty());
    cr_assert_eq(node, NULL, "Expected: %p, Got: %p", NULL, node);
}

Test(kap_yml_test, yaml_key_exists_file1) {
    yaml_node_t *node = yaml_key_exists_file(NULL, "test");
    cr_assert_eq(node, NULL, "Expected: %p, Got: %p", NULL, node);
}

Test(kap_yml_test, yaml_key_exists_file2) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    string val = yaml_get(file, "test.value1");
    yaml_node_t *node = yaml_key_exists_file(file, "test.value1");

    string val_content = "This is a test";

    cr_assert_str_eq(val, val_content, "Expected: %s, Got: %s", val_content, val);
    cr_assert_not_null(node);
    yaml_close(file);
}

Test(kap_yml_test, yaml_set_list_good) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    list_t *list = list_create();
    list_push(list, "v1");
    list_push(list, "v2");
    yaml_set_list(file, "test.obj1.list3", list);
    list_t *list_got = yaml_get_list(file, "test.obj1.list3");

    cr_assert_eq(list->size, list_got->size);
    cr_assert_str_eq(list_get(list, 0), list_get(list_got, 0));
    cr_assert_str_eq(list_get(list, 1), list_get(list_got, 1));
}

Test(kap_yml_test, yaml_set_list_null) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    yaml_set_list(file, "test.obj1.list3", NULL);
    list_t *list_got = yaml_get_list(file, "test.obj1.list3");

    cr_assert_eq(list_got, NULL);
}

Test(kap_yml_test, yaml_set_list_null_file) {
    list_t *list = list_create();
    list_push(list, "v1");
    list_push(list, "v2");
    yaml_set_list(NULL, "test.obj1.list3", list);
    list_t *list_got = yaml_get_list(NULL, "test.obj1.list3");

    cr_assert_eq(list_got, NULL);
}

Test(kap_yml_test, yaml_set_null_file) {
    yaml_set(NULL, "test.obj1.list3", "v1");
    string list_got = yaml_get(NULL, "test.obj1.list3");

    cr_assert_eq(list_got, NULL);
}

Test(kap_yml_test, yaml_get_object_good) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    yaml_node_t *node = yaml_get_object(file, "test.obj1");
    cr_assert_not_null(node);
    yaml_close(file);
}

Test(kap_yml_test, yaml_get_object_null) {
    void *node = yaml_get_object(NULL, "test.obj1");
    cr_assert_eq(node, NULL);
}

Test(kap_yml_test, yaml_get_object_destroyed) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    yaml_set_list(file, "test.obj1.list", NULL);
    void *node = yaml_get_object(file, "test.obj1.list");
    yaml_close(file);
    cr_assert_eq(node, NULL);
}

Test(kap_yml_test, yaml_find_first_node_good) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    yaml_get_object(file, "test.obj1");
    yaml_node_t *node = yaml_find_first_node(file, "test.obj1");
    cr_assert_not_null(node);
    yaml_close(file);
}

Test(kap_yml_test, yaml_find_first_node_null) {
    yaml_f *file = yaml_open("./tests/configs/test_yaml.yml");
    void *node = yaml_find_first_node(file, "test.obj2");
    cr_assert_eq(node, NULL);
}
