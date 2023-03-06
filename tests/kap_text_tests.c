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

