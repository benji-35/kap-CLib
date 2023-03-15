/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_alloc
*/

#include "kapmemory.h"

void *kapmalloc(ksize_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL)
        exit(84);
    return ptr;
}
