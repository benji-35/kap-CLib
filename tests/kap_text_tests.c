/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_text_tests
*/

#include <criterion/criterion.h>
#include "kapstring.h"

Test (text_tests, text_create_empty) {
    text_t text = text_create();
    cr_assert_str_eq(text_to_string(text), "", "Expected \"\", got \"%s\"", text_to_string(text));
}

Test (text_tests, text_create_string) {
    text_t text = str_split("Hello World!", ' ');

    cr_assert_eq(text->size, 2, "Expected 2, got %d", text->size);
}

Test(text_tests, text_remove_line_tst) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_line(text, 0);
    cr_assert_eq(text->size, 1, "Expected 1, got %d", text->size);
    string str = text_to_string(text);
    cr_assert_str_eq(str, "World!", "Expected \"World!\", got \"%s\"", str);
}

Test(text_tests, text_remove_lines_tst) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines(text, 0, 1);
    cr_assert_eq(text->size, 0, "Expected 0, got %d", text->size);
}

Test(text_tests, text_remove_lines_tst2) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines(text, 0, 2);
    cr_assert_eq(text->size, 0, "Expected 0, got %d", text->size);
}

Test(text_tests, text_remove_lines_tst3) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines(text, 1, 2);
    cr_assert_eq(text->size, 1, "Expected 1, got %d", text->size);
    string str = text_to_string(text);
    cr_assert_str_eq(str, "Hello", "Expected \"Hello\", got \"%s\"", str);
}

Test(text_tests, text_remove_lines_at_tst) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines_at(text, 0, 1);
    cr_assert_eq(text->size, 1, "Expected 1, got %d", text->size);
    string str = text_to_string(text);
    cr_assert_str_eq(str, "World!", "Expected \"World!\", got \"%s\"", str);
}

Test(text_tests, text_remove_lines_at_tst2) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines_at(text, 0, 2);
    cr_assert_eq(text->size, 0, "Expected 0, got %d", text->size);
}

Test(text_tests, text_remove_lines_from_tst) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines_from(text, 0);
    cr_assert_eq(text->size, 0, "Expected 0, got %d", text->size);
}

Test(text_tests, text_remove_lines_from_tst2) {
    text_t text = str_split("Hello World!", ' ');

    text_remove_lines_from(text, 1);
    cr_assert_eq(text->size, 1, "Expected 1, got %d", text->size);
    string str = text_to_string(text);
    cr_assert_str_eq(str, "Hello", "Expected \"Hello\", got \"%s\"", str);
}

Test(text_tests, text_add_text_back) {
    text_t text = str_split("Hello World!", ' ');
    text_t txt2 = str_split("Hello World!", ' ');

    text_add_text(text, txt2);
    cr_assert_eq(text->size, 4, "Expected 4, got %d", text->size);
    string str = text_to_string(text);
    string result_want = "Hello\nWorld!\nHello\nWorld!";
    cr_assert_str_eq(str, result_want, "Expected \"%s\", got \"%s\"", result_want, str);
}

Test(text_tests, text_add_text_sep) {
    text_t text = str_split("Hello World!", ' ');
    text_t txt2 = str_split("Hello World!", ' ');

    text_add_text(text, txt2);
    cr_assert_eq(text->size, 4, "Expected 4, got %d", text->size);
    string str = text_to_string_separator(text, " ");
    string result_want = "Hello World! Hello World!";
    cr_assert_str_eq(str, result_want, "Expected \"%s\", got \"%s\"", result_want, str);
}
