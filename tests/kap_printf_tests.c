/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_printf_tests
*/

#include "kapprintf.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(kap_printf, print_char, .init = redirect_all_stdout)
{
        kprintf("Hello %c", 'c');
        cr_assert_stdout_eq_str("Hello c");
}

Test(kap_printf, print_string, .init = redirect_all_stdout)
{
        kprintf("Hello %s", "world");
        cr_assert_stdout_eq_str("Hello world");
}

Test(kap_printf, print_int, .init = redirect_all_stdout)
{
        kprintf("Hello %d", 42);
        cr_assert_stdout_eq_str("Hello 42");
}

Test(kap_printf, print_hexa, .init = redirect_all_stdout)
{
        kprintf("Hello %x", 42);
        cr_assert_stdout_eq_str("Hello 2a");
}

Test(kap_printf, print_hexa_upper, .init = redirect_all_stdout)
{
        kprintf("Hello %X", 42);
        cr_assert_stdout_eq_str("Hello 2A");
}

Test(kap_printf, print_binary, .init = redirect_all_stdout)
{
        kprintf("Hello %b", 42);
        cr_assert_stdout_eq_str("Hello 101010");
}
