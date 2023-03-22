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

Test(kap_printf, print_string_null, .init = redirect_all_stdout)
{
        kprintf("Hello %s", NULL);
        cr_assert_stdout_eq_str("Hello nil");
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

Test(kap_printf, print_percent, .init = redirect_all_stdout)
{
        kprintf("Hello %%");
        cr_assert_stdout_eq_str("Hello %");
}

Test(kap_printf, print_unknown, .init = redirect_all_stdout)
{
        kprintf("Hello %z");
        cr_assert_stdout_eq_str("Hello %z");
}

//test with spaces

Test(kap_printf, print_char_space, .init = redirect_all_stdout)
{
        kprintf("Hello %2c", 'c');
        cr_assert_stdout_eq_str("Hello  c");
}

Test(kap_printf, print_string_space, .init = redirect_all_stdout)
{
        kprintf("Hello %10s", "world");
        cr_assert_stdout_eq_str("Hello      world");
}

Test(kap_printf, print_int_space, .init = redirect_all_stdout)
{
        kprintf("Hello %5d", 42);
        cr_assert_stdout_eq_str("Hello    42");
}

Test(kap_printf, print_int_space_star, .init = redirect_all_stdout)
{
        kprintf("Hello %*d", 5, 42);
        cr_assert_stdout_eq_str("Hello    42");
}

//testing flags

Test(kap_printf, print_char_flag, .init = redirect_all_stdout)
{
        kprintf("Hello %-2c", 'c');
        cr_assert_stdout_eq_str("Hello c ");
}

Test(kap_printf, print_string_flag, .init = redirect_all_stdout)
{
        kprintf("Hello %-10s", "world");
        cr_assert_stdout_eq_str("Hello world     ");
}

Test(kap_printf, print_int_flag, .init = redirect_all_stdout)
{
        kprintf("Hello %-5d", 42);
        cr_assert_stdout_eq_str("Hello 42   ");
}

Test(kap_printf, print_int_blank, .init = redirect_all_stdout)
{
        kprintf("Hello % d", 42);
        cr_assert_stdout_eq_str("Hello  42");
}

Test(kap_printf, print_int_plus, .init = redirect_all_stdout)
{
        kprintf("Hello %+d", 42);
        cr_assert_stdout_eq_str("Hello +42");
}

Test(kap_printf, print_hex_hash, .init = redirect_all_stdout)
{
        kprintf("Hello %#x", 42);
        cr_assert_stdout_eq_str("Hello 0x2a");
}

Test(kap_printf, print_hex_upper_hash, .init = redirect_all_stdout)
{
        kprintf("Hello %#X", 42);
        cr_assert_stdout_eq_str("Hello 0x2A");
}

Test(kap_printf, print_bin_hash, .init = redirect_all_stdout)
{
        kprintf("Hello %#b", 42);
        cr_assert_stdout_eq_str("Hello 0b101010");
}

Test(kap_printf, print_int_0, .init = redirect_all_stdout)
{
        kprintf("Hello %05d", 42);
        cr_assert_stdout_eq_str("Hello 00042");
}

//testing precision

Test(kap_printf, print_string_precision, .init = redirect_all_stdout)
{
        kprintf("Hello %.5s", "world!");
        cr_assert_stdout_eq_str("Hello world");
}

Test(kap_printf, print_int_precision, .init = redirect_all_stdout)
{
        kprintf("Hello %.5d", 42);
        cr_assert_stdout_eq_str("Hello 00042");
}

Test(kap_printf, print_hexa_precision, .init = redirect_all_stdout)
{
        kprintf("Hello %.5x", 42);
        cr_assert_stdout_eq_str("Hello 0002a");
}
