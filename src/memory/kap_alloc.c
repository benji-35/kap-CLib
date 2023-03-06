/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_alloc
*/

#include "kapmemory.h"

void *kapmalloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL)
        return NULL;
    return ptr;
}
