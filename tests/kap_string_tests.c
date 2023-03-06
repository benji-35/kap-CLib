/*
** KAP PROJECT, 2023
** C Lib - String Tests
** File description:
** kap_string_tests
*/

#include <criterion/criterion.h>
#include "kapstring.h"

Test (string_tests, string_create_empty) {
    string str = str_create_empty();
    cr_assert_str_eq(str, "", "Expected \"\", got \"%s\"", str);
}

Test(string_tests, string_create_char) {
    string str = str_create_char('H');
    cr_assert_str_eq(str, "H", "Expected \"H\", got \"%s\"", str);
}

Test(string_tests, string_create_string) {
    string str = str_create_string("Hello World!");
    cr_assert_str_eq(str, "Hello World!", "Expected \"Hello World!\", got \"%s\"", str);
}

Test(string_tests, string_add_char) {
    string str = str_create_string("Hello");
    str_add_char(&str, ' ');
    str_add_char(&str, 'W');
    str_add_char(&str, 'o');
    str_add_char(&str, 'r');
    str_add_char(&str, 'l');
    str_add_char(&str, 'd');
    str_add_char(&str, '!');
    cr_assert_str_eq(str, "Hello World!", "Expected \"Hello World!\", got \"%s\"", str);
}

Test(string_tests, string_add_string) {
    string str = str_create_string("Hello");
    str_add_string(&str, " World!");
    cr_assert_str_eq(str, "Hello World!", "Expected \"Hello World!\", got \"%s\"", str);
}

Test(string_tests, string_last_index_of_char) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_last_index_of_char(str, 'o');
    cr_assert_eq(index, 7, "Expected 7, got %d", index);
}

Test(string_tests, string_last_index_of_string) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_last_index_of_string(str, "World");
    cr_assert_eq(index, 6, "Expected 6, got %d", index);
}

Test(string_tests, string_contains_char) {
    string str = str_create_string("Hello World!");
    cr_assert_eq(str_contains_char(str, 'o'), true, "Expected true, got %d", str_contains_char(str, 'o'));
}

Test(string_tests, string_contains_string) {
    string str = str_create_string("Hello World!");
    cr_assert_eq(str_contains_string(str, "World"), true, "Expected true, got %d", str_contains_string(str, "World"));
}

Test(string_tests, string_index_of_char) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_index_of_char(str, 'o');
    cr_assert_eq(index, 4, "Expected 4, got %d", index);
}

Test(string_tests, string_index_of_string) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_index_of_string(str, "World");
    cr_assert_eq(index, 6, "Expected 6, got %d", index);
}

Test(string_tests, string_index_of_char_from) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_index_of_char_from(str, 'o', 5);
    cr_assert_eq(index, 7, "Expected 7, got %d", index);
}

Test(string_tests, string_index_of_string_from) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_index_of_string_from(str, "World", 6);
    cr_assert_eq(index, 6, "Expected 6, got %d", index);
}

Test(string_tests, string_is_empty) {
    string str = str_create_string("Hello World!");
    bool result = str_is_empty(str);
    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_tests, string_is_not_empty) {
    string str = str_create_string("Hello World!");
    bool result = str_is_not_empty(str);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_is_equal) {
    string str = str_create_string("Hello World!");
    bool result = str_is_equal(str, "Hello World!", true);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_is_not_equal) {
    string str = str_create_string("Hello World!");
    bool result = str_is_not_equal(str, "Hello World!", true);
    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_tests, string_is_equal_ignore_case) {
    string str = str_create_string("Hello World!");
    bool result = str_is_equal(str, "Hello WorLd!", false);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_is_not_equal_ignore_case) {
    string str = str_create_string("Hello World!");
    bool result = str_is_not_equal(str, "Hello WOrld!", false);
    cr_assert_eq(result, false, "Expected false, got %d", result);
}

Test(string_tests, string_is_equal_from) {
    string str = str_create_string("Hello World!");
    bool result = str_is_equal_from(str, "World!", 6, true);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_remove_char) {
    string str = str_create_string("Hello World!");
    str_remove_char(&str, 'o', true);
    cr_assert_str_eq(str, "Hell Wrld!", "Expected \"Hell Wrld!\", got \"%s\"", str);
}

Test(string_tests, string_remove_string) {
    string str = str_create_string("Hello World!");
    str_remove_string(&str, "World", true);
    cr_assert_str_eq(str, "Hello !", "Expected \"Hello !\", got \"%s\"", str);
}

Test(string_tests, string_remove_char_from) {
    string str = str_create_string("Hello World!");
    str_remove_char_from(&str, 'o', 5, true);
    cr_assert_str_eq(str, "Hello Wrld!", "Expected \"Hello Wrld!\", got \"%s\"", str);
}

Test(string_tests, string_remove_string_from) {
    string str = str_create_string("Hello World!");
    str_remove_string_from(&str, "World", 6, true);
    cr_assert_str_eq(str, "Hello !", "Expected \"Hello !\", got \"%s\"", str);
}

//start tests
Test(string_tests, string_start_with_char) {
    string str = str_create_string("Hello World!");
    bool result = str_start_cwith(str, 'H');
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_start_with_string) {
    string str = str_create_string("Hello World!");
    bool result = str_start_with(str, "Hello");
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_start_with_char_from) {
    string str = str_create_string("Hello World!");
    bool result = str_start_cwith_from(str, 'W', 6);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_start_with_string_from) {
    string str = str_create_string("Hello World!");
    bool result = str_start_with_from(str, "World", 6);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

//end tests
Test(string_tests, string_end_with_char) {
    string str = str_create_string("Hello World!");
    bool result = str_end_cwith(str, '!');
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_end_with_string) {
    string str = str_create_string("Hello World!");
    bool result = str_end_with(str, "World!");
    cr_assert_eq(result, true, "Expected true, got %d", result);
}
