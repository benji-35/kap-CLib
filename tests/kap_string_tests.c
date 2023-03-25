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

Test(string_tests, string_contains_char_from) {
    bool result = str_contains_char_from("Hello World!", 'o', 5);
    cr_assert_eq(result, true, "Expected true, got %d", result);
}

Test(string_tests, string_contains_string_from) {
    bool result = str_contains_string_from("Hello World!", "World", 6);
    cr_assert_eq(result, true, "Expected true, got %d", result);
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

Test(string_test, string_index_of_str_null) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_index_of_string_from(str, NULL, 6);
    ksize_t result = str_len(str);
    cr_assert_eq(index, result, "Expected %ld, got %ld", result, index);
}

Test(string_test, last_index_of_char) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_last_index_of_char(str, 'o');
    cr_assert_eq(index, 7, "Expected 7, got %ld", index);
}

Test(string_test, last_index_of_string) {
    string str = str_create_string("Hello World!");
    ksize_t index = str_last_index_of_string(str, "World");
    cr_assert_eq(index, 6, "Expected 6, got %ld", index);
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

Test(string_tests, string_is_equal_ignore_case_false) {
    string str = str_create_string("Hello World!");
    bool result = str_is_equal(str, "Hello Worud!", false);

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

Test(string_tests, string_end_with_lower) {
    string str = "Hello";
    string to_find = "hello world!";
    bool result = str_end_with(str, to_find);

    cr_assert_eq(result, false, "Expected false, got %d", result);
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

Test(string_tests, string_substring_to_higher) {
    string str = str_create_string("Hello World!");
    string sub = str_substring(str, 6, 20);
    cr_assert_str_eq(sub, "World!", "Expected \"World!\", got \"%s\"", sub);
}

//reverse tests
Test(string_tests, string_reverse) {
    string str = str_create_string("Hello World!");
    str_reverse(str);
    cr_assert_str_eq(str, "!dlroW olleH", "Expected \"!dlroW olleH\", got \"%s\"", str);
}

Test(string_test, string_reverse_copy) {
    string str = str_create_string("Hello World!");
    string rev = str_reverse_copy(str);
    cr_assert_str_eq(rev, "!dlroW olleH", "Expected \"!dlroW olleH\", got \"%s\"", rev);
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

Test(string_tests, string_get_between_null) {
    string str = NULL;
    string sub = str_value_between(str, "W", "!");

    cr_assert_null(sub, "Expected NULL, got \"%s\"", sub);
}

Test(string_tests, string_get_between_empty_start) {
    string str = str_create_string("Hello World!");
    string sub = str_value_between(str, "", "o");

    string result = "Hell";
    cr_assert_str_eq(sub, result, "Expected \"%s\", got \"%s\"", result, sub);
}

Test(string_tests, string_get_between_empty_end) {
    string str = str_create_string("Hello World!");
    string sub = str_value_between(str, "o ", "");

    string result = "World!";
    cr_assert_str_eq(sub, result, "Expected \"%s\", got \"%s\"", result, sub);
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

//test string clear

Test(string_tests, string_clear) {
    string str = str_create_string("Hello World!");
    str_clear(&str);
    cr_assert_str_eq(str, "", "Expected \"\", got \"%s\"", str);
}

Test(string_tests, string_clear_null) {
    string str = NULL;
    str_clear(&str);
    cr_assert_null(str, "Expected NULL, got \"%s\"", str);
}

//test string count
Test(string_tests, string_count) {
    string str = str_create_string("Hello World!");
    ksize_t count = str_count_str(str, "l");
    cr_assert_eq(count, 3, "Expected 3, got %d", count);
}

Test(string_tests, string_count_null) {
    string str = NULL;
    ksize_t count = str_count_str(str, "l");
    cr_assert_eq(count, 0, "Expected 0, got %d", count);
}

Test(string_tests, string_count_char) {
    ksize_t count = str_count_char("Hello World!", 'l');
    cr_assert_eq(count, 3, "Expected 3, got %d", count);
}

//str is number
Test(string_tests, string_is_number) {
    bool is_number = str_is_number("123");
    cr_assert(is_number == true, "Expected true, got false");
}

Test(string_tests, string_is_number_false) {
    bool is_number = str_is_number("123a");
    cr_assert(is_number == false, "Expected false, got true");
}

Test(string_tests, string_is_number_null) {
    bool is_number = str_is_number(NULL);
    cr_assert(is_number == false, "Expected false, got true");
}

Test(string_tests, string_is_number_negative) {
    bool is_number = str_is_number("-123");
    cr_assert(is_number == true, "Expected true, got false");
}

//str is decimal
Test(string_tests, string_is_decimal) {
    bool is_decimal = str_is_decimal("123.123");
    cr_assert(is_decimal == true, "Expected true, got false");
}

Test(string_tests, string_is_decimal_no_dot) {
    bool is_decimal = str_is_decimal("123");
    cr_assert(is_decimal == true, "Expected true, got false");
}

Test(string_tests, string_is_decimal_false) {
    bool is_decimal = str_is_decimal("123a");
    cr_assert(is_decimal == false, "Expected false, got true");
}

Test(string_tests, string_is_decimal_null) {
    bool is_decimal = str_is_decimal(NULL);
    cr_assert(is_decimal == false, "Expected false, got true");
}

Test(string_tests, string_is_decimal_several_dot) {
    bool is_decimal = str_is_decimal("123.123.123");
    cr_assert(is_decimal == false, "Expected false, got true");
}

Test(string_tests, string_is_decimal_negative) {
    bool is_decimal = str_is_decimal("-123.123");
    cr_assert(is_decimal == true, "Expected true, got false");
}

//replace tests
Test(string_tests, string_replace) {
    string str = str_create_string("Hello World!");
    string result = str_replace(str, "l", "a");
    string to_find = "Heaao Worad!";
    
    cr_assert_str_eq(result, to_find, "Expected \"%s\", got \"%s\"", to_find, result);
}

Test(string_tests, string_replace_null) {
    string str = NULL;
    string result = str_replace(str, "l", "a");
    
    cr_assert_null(result, "Expected NULL, got \"%s\"", result);
}

Test(string_test, string_replace_no_exists) {
    string str = str_create_string("Hello World!");
    string result = str_replace(str, "a", "l");
    
    cr_assert_str_eq(result, str, "Expected \"%s\", got \"%s\"", str, result);
}

//ints to string
Test(string_tests, string_int_to_string) {
    string str = int_to_str(123);
    cr_assert_str_eq(str, "123", "Expected \"123\", got \"%s\"", str);
}

Test(string_tests, string_int_to_string_negative) {
    string str = int_to_str(-123);
    cr_assert_str_eq(str, "-123", "Expected \"-123\", got \"%s\"", str);
}

Test(string_tests, string_int_to_string_zero) {
    string str = int_to_str(0);
    cr_assert_str_eq(str, "0", "Expected \"0\", got \"%s\"", str);
}

//unsigned ints to string
Test(string_tests, string_uint_to_string) {
    string str = ulong_int_to_str(123);
    cr_assert_str_eq(str, "123", "Expected \"123\", got \"%s\"", str);
}

Test(string_tests, string_uint_to_string_zero) {
    string str = ulong_int_to_str(0);
    cr_assert_str_eq(str, "0", "Expected \"0\", got \"%s\"", str);
}

//long ints to string
Test(string_tests, string_long_int_to_string) {
    string str = long_int_to_str(123);
    cr_assert_str_eq(str, "123", "Expected \"123\", got \"%s\"", str);
}

Test(string_tests, string_long_int_to_string_negative) {
    string str = long_int_to_str(-123);
    cr_assert_str_eq(str, "-123", "Expected \"-123\", got \"%s\"", str);
}

Test(string_tests, string_long_int_to_string_zero) {
    string str = long_int_to_str(0);
    cr_assert_str_eq(str, "0", "Expected \"0\", got \"%s\"", str);
}

//long long ints to string
Test(string_tests, string_long_long_int_to_string) {
    string str = long_long_int_to_str(123);
    cr_assert_str_eq(str, "123", "Expected \"123\", got \"%s\"", str);
}

Test(string_tests, string_long_long_int_to_string_negative) {
    string str = long_long_int_to_str(-123);
    cr_assert_str_eq(str, "-123", "Expected \"-123\", got \"%s\"", str);
}

Test(string_tests, string_long_long_int_to_string_zero) {
    string str = long_long_int_to_str(0);
    cr_assert_str_eq(str, "0", "Expected \"0\", got \"%s\"", str);
}