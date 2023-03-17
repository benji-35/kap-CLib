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

Test(kap_yml_tests, set_new_string_value) {
    yaml_f *yml = yaml_open("./tests/configs/test_yaml.yml");
    string str = "This is a test";
    string result = "This is a test";

    yaml_set(yml, "test.test_value", str);
    str = yaml_get(yml, "test.test_value");
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
