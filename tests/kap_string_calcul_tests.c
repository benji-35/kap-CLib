/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_string_calcul_tests
*/

#include "kapstring.h"
#include <criterion/criterion.h>

Test(kap_string_calcul_tests, int_to_bin)
{
    string bin = int_to_bin(0);
    cr_assert_str_eq(bin, "0", "Expected 0, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_bin2)
{
    string bin = int_to_bin(1);
    cr_assert_str_eq(bin, "1", "Expected 1, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_bin3)
{
    string bin = int_to_bin(2);
    cr_assert_str_eq(bin, "10", "Expected 10, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_bin4)
{
    string bin = int_to_bin(3);
    cr_assert_str_eq(bin, "11", "Expected 11, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_bin5)
{
    string bin = int_to_bin(233);
    cr_assert_str_eq(bin, "11101001", "Expected 11101001, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_bin6)
{
    string bin = int_to_bin(1024);
    cr_assert_str_eq(bin, "10000000000", "Expected 10000000000, got %s", bin);
}

Test(kap_string_calcul_tests, int_to_hex)
{
    string hex = int_to_hex(0);
    cr_assert_str_eq(hex, "0", "Expected 0, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex2)
{
    string hex = int_to_hex(1);
    cr_assert_str_eq(hex, "1", "Expected 1, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex3)
{
    string hex = int_to_hex(2);
    cr_assert_str_eq(hex, "2", "Expected 2, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex4)
{
    string hex = int_to_hex(3);
    cr_assert_str_eq(hex, "3", "Expected 3, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex5)
{
    string hex = int_to_hex(233);
    cr_assert_str_eq(hex, "E9", "Expected E9, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex6)
{
    string hex = int_to_hex(1024);
    cr_assert_str_eq(hex, "400", "Expected 400, got %s", hex);
}

Test(kap_string_calcul_tests, int_to_hex7)
{
    string hex = int_to_hex(1024 * 1024);
    cr_assert_str_eq(hex, "100000", "Expected 100000, got %s", hex);
}

//int to str
Test(kap_string_calcul_tests, int_to_string)
{
    string str = int_to_str(0);
    cr_assert_str_eq(str, "0", "Expected 0, got %s", str);
}

Test(kap_string_calcul_tests, int_to_string2)
{
    string str = int_to_str(1);
    cr_assert_str_eq(str, "1", "Expected 1, got %s", str);
}

Test(kap_string_calcul_tests, int_to_string3)
{
    string str = int_to_str(2);
    cr_assert_str_eq(str, "2", "Expected 2, got %s", str);
}

Test(kap_string_calcul_tests, int_to_string4)
{
    string str = int_to_str(42);
    cr_assert_str_eq(str, "42", "Expected 42, got %s", str);
}

Test(kap_string_calcul_tests, int_to_string5)
{
    string str = int_to_str(233);
    cr_assert_str_eq(str, "233", "Expected 233, got %s", str);
}

Test(kap_string_calcul_tests, int_to_string6)
{
    string str = int_to_str(-45);
    cr_assert_str_eq(str, "-45", "Expected -45, got %s", str);
}
