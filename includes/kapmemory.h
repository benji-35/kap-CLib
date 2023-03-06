/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapmemory
*/

#ifndef KAPMEMORY_H_
    #define KAPMEMORY_H_

    #include "kaptools.h"
    #include <stdlib.h>

    void kapfree(void *ptr);
    void *kapmalloc(size_t size);

#endif /* !KAPMEMORY_H_ */
