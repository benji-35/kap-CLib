/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_get_between
*/

#include "kapstring.h"

string str_value_between(cstring str, cstring start, cstring end) {
    string value = NULL;

    if (str == NULL || start == NULL || end == NULL)
        return NULL;
    int start_index = str_index_of_string(str, start);
    if (str_is_equal(start, "", false))
        start_index = 0;
    int end_index = str_index_of_string_from(str, end, start_index + str_len(start)) - 1;
    if (str_is_equal(end, "", false))
        end_index = str_len(str);

    if (start_index >= str_len(str) || end_index > str_len(str) || end_index < start_index)
        return NULL;
    start_index += str_len(start);
    value = str_substring(str, start_index, end_index);
    return value;
}
