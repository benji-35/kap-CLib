/*
** KAP PROJECT, 2023
** C Lib - String Tests
** File description:
** kap_string_tests
*/

#include <criterion/criterion.h>
#include "kapstring.h"

//create empty and create char tests
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

//add char and add string tests
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
    str_add_str(&str, " World!");
    cr_assert_str_eq(str, "Hello World!", "Expected \"Hello World!\", got \"%s\"", str);
}

//last index of char and last index of string tests
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

//contains char and contains string tests
Test(string_tests, string_contains_char) {
    string str = str_create_string("Hello World!");
    cr_assert_eq(str_contains_char(str, 'o'), true, "Expected true, got %d", str_contains_char(str, 'o'));
}

Test(string_tests, string_contains_string) {
    string str = str_create_string("Hello World!");
    cr_assert_eq(str_contains_string(str, "World"), true, "Expected true, got %d", str_contains_string(str, "World"));
}

//index of char and index of string tests
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

//is empty and is not empty tests
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

//equals and not equals tests
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

//remove tests
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

// upper and lower tests
Test(string_tests, string_to_upper) {
    string str = str_create_string("Hello World!");
    str_to_upper(str);
    cr_assert_str_eq(str, "HELLO WORLD!", "Expected \"HELLO WORLD!\", got \"%s\"", str);
}

Test(string_tests, string_to_lower) {
    string str = str_create_string("Hello World!");
    str_to_lower(str);
    cr_assert_str_eq(str, "hello world!", "Expected \"hello world!\", got \"%s\"", str);
}

//substring tests
Test(string_tests, string_substring) {
    string str = str_create_string("Hello World!");
    string sub = str_substring(str, 6, 10);
    cr_assert_str_eq(sub, "World", "Expected \"World\", got \"%s\"", sub);
}

Test(string_tests, string_substring_from) {
    string str = str_create_string("Hello World!");
    string sub = str_substring_from(str, 6);
    cr_assert_str_eq(sub, "World!", "Expected \"World!\", got \"%s\"", sub);
}

Test(string_tests, string_substring_size) {
    string str = str_create_string("Hello World!");
    string sub = str_substring_size(str, 6, 5);
    cr_assert_str_eq(sub, "World", "Expected \"World\", got \"%s\"", sub);
}

//reverse tests
Test(string_tests, string_reverse) {
    string str = str_create_string("Hello World!");
    str_reverse(str);
    cr_assert_str_eq(str, "!dlroW olleH", "Expected \"!dlroW olleH\", got \"%s\"", str);
}

//length tests
Test(string_tests, string_length) {
    string str = str_create_string("Hello World!");
    size_t len = str_len(str);
    cr_assert_eq(len, 12, "Expected 12, got %d", len);
}

//get between
Test(string_tests, string_get_between) {
    string str = str_create_string("Hello World!");
    string sub = str_value_between(str, "H", "!");
    cr_assert_str_eq(sub, "ello World", "Expected \"ello World\", got \"%s\"", sub);
}

Test(string_tests, string_get_between_from) {
    string str = str_create_string("Hello World!");
    string sub = str_value_between(str, "W", "!");
    cr_assert_str_eq(sub, "orld", "Expected \"orld\", got \"%s\"", sub);
}

//split str
Test(string_tests, string_split) {
    string str = str_create_string("Hello World!");
    text_t split = str_split(str, ' ');
    string line0 = text_get_line(split, 0);
    string line1 = text_get_line(split, 1);

    cr_assert_str_eq(line0, "Hello", "Expected \"Hello\", got \"%s\"", line0);
    cr_assert_str_eq(line1, "World!", "Expected \"World!\", got \"%s\"", line1);
}

Test(string_tests, string_split_from) {
    string str = str_create_string("Hello World!");
    text_t split = str_split_str_from(str, " ", 6);
    string line0 = text_get_line(split, 0);

    cr_assert_str_eq(line0, "World!", "Expected \"World!\", got \"%s\"", line0);
}

Test(string_tests, string_split_str) {
    string str = str_create_string("Hello World!");
    text_t split = str_split_str(str, " ");
    string line0 = text_get_line(split, 0);
    string line1 = text_get_line(split, 1);

    cr_assert_str_eq(line0, "Hello", "Expected \"Hello\", got \"%s\"", line0);
    cr_assert_str_eq(line1, "World!", "Expected \"World!\", got \"%s\"", line1);
}

//string copy
Test(string_tests, string_copy) {
    string str = str_create_string("Hello World!");
    string copy = str_copy(str);
    cr_assert_str_eq(copy, str, "Expected \"%s\", got \"%s\"", str, copy);
}

Test(string_tests, string_copy_from) {
    string str = str_create_string("Hello World!");
    string result = str_create_string("            ");

    result = str_copy_to(result, str);
    cr_assert_str_eq(result, str, "Expected \"%s\", got \"%s\"", str, result);
}

Test(string_tests, string_copy_from_to) {
    string str = str_create_string("Hello World!");
    string result = str_copy_from_to(str, 6, 10);

    cr_assert_str_eq(result, "World", "Expected \"World\", got \"%s\"", result);
}

Test(string_tests, string_copy_from_to_null) {
    string result = str_copy_from_to(NULL, 6, 10);
    
    cr_assert_null(result, "Expected NULL, got \"%s\"", result);
}
