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
    void *kapmalloc(ksize_t size);

    #define kfree(ptr) kapfree(ptr)

#endif /* !KAPMEMORY_H_ */
