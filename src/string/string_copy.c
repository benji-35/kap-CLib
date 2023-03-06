/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_copy
*/

#include "kapstring.h"

string str_copy(cstring src) {
    ksize_t size = str_len(src);
    string dest = malloc(sizeof(char) * (size + 1));

    if (dest == NULL)
        return NULL;
    for (ksize_t i = 0; i < size; i++)
        dest[i] = src[i];
    dest[size] = '\0';
    return dest;
}

string str_copy_to(string dest, cstring src) {
    ksize_t size = str_len(src);

    if (dest == NULL)
        return NULL;
    for (ksize_t i = 0; i < size; i++)
        dest[i] = src[i];
    dest[size] = '\0';
    return dest;
}
