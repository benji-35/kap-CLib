/*
** KAP PROJECT, 2023
** C Lib 
** File description:
** kap_memory_test
*/

#include <criterion/criterion.h>
#include "kapmemory.h"

Test(kap_memory, kapfree_not_null) {
    void *ptr = kapmalloc(10);
    kapfree(ptr);
    cr_assert_eq(ptr, NULL);
}

Test(kap_memory, kapfree_null) {
    void *ptr = NULL;
    kapfree(ptr);
    cr_assert_eq(ptr, NULL);
}

Test(kap_memory, kapmalloc) {
    void *ptr = kapmalloc(10);
    cr_assert_neq(ptr, NULL);
}
