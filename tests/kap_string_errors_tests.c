/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_string_errors_tests
*/

#include <criterion/criterion.h>
#include "kapstring.h"

Test(string_error_tests, str_substring_from) {
    string str = "Hello World!";
    string sub = str_substring(str, 6, 3);

    cr_assert_eq(sub, NULL, "Expected NULL, got %s", sub);
}

Test(string_error_tests, str_empty_null) {
    bool is_null = str_is_empty(NULL);

    cr_assert_eq(is_null, true, "Expected true, got %d", is_null);
}

Test(string_error_tests, str_equal_from_bad_size) {
    string str = "Hello World!";
    string str2 = "Hello World!";
    bool result = str_is_equal_from(str, str2, 2, false);

    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_error_tests, str_equal_from_bad_str) {
    string str = "Hello World!";
    string str2 = "Hello WoRld!";
    bool result = str_is_equal_from(str, str2, 0, true);

    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_error_tests, bad_write) {
    string str = "Hello World!";
    bool result = str_write(str, "no_folder/file_not_exist.txt", true);

    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_error, null_path_to_read) {
    string readed = str_read(NULL);

    cr_assert_eq(readed, NULL, "Expected NULL, got %s", readed);
}

Test(string_error, bad_path_to_read) {
    string readed = str_read("no_folder/file_not_exist.txt");

    cr_assert_eq(readed, NULL, "Expected NULL, got %s", readed);
}
