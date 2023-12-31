/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_free
*/

#include "kapmemory.h"
#include <stdlib.h>

void kapfree(void *ptr) {
    if (ptr == NULL)
        return;
    free(ptr);
}
