/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_yml_parsor_tests
*/

#include <criterion/criterion.h>
#include "kapparser.h"


Test(yaml_tests, yaml_opening) {
    string path = "tests/configs/test_yaml.yml";
    yaml_f *yaml = yaml_open("tests/configs/test_yaml.yml");
    cr_assert_not_null(yaml, "Expected not null, got null");
    cr_assert_not_null(yaml->path, "Expected not null, got null");
    cr_assert_not_null(yaml->file_content, "Expected not null, got null");
    cr_assert_not_null(yaml->yaml, "Expected not null, got null");
    cr_assert_str_eq(yaml->path, path, "Expected \"%s\", got \"%s\"", path, yaml->path);
}

Test(yaml_tests, yaml_getting_basic_value) {
    yaml_f *yaml = yaml_open("tests/configs/test_yaml.yml");
    string value = yaml_get_value(yaml, "test.value1");
    string result = "\"This is a test\"";

    cr_assert_not_null(value, "Expected not null, got null");
    cr_assert_str_eq(value, result, "Expected \"%s\", got \"%s\"", result, value);
}
