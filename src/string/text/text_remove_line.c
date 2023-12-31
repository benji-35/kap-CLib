/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_remove_line
*/

#include "kapstring.h"

void text_remove_line(text_t text, ksize_t index) {
    if (text == NULL || index >= list_size(text))
        return;
    text_remove_lines_at(text, index, 1);
}

void text_remove_lines(text_t text, ksize_t from, ksize_t to) {
    if (text == NULL || from >= list_size(text) || from > to)
        return;
    if (to > list_size(text))
        to = list_size(text);
    ksize_t size = to - from;
    size++;
    text_remove_lines_at(text, from, size);
}

void text_remove_lines_at(text_t text, ksize_t index, ksize_t size) {
    if (text == NULL || index >= list_size(text) || size == 0)
        return;
    while (list_get(text, index) != NULL && size > 0) {
        if (index >= list_size(text))
            break;
        list_remove(text, index);
        size--;
        if (size <= 0)
            break;
    }
}

void text_remove_lines_from(text_t text, ksize_t index) {
    if (text == NULL || index >= list_size(text))
        return;
    text_remove_lines_at(text, index, list_size(text) - index);
}
