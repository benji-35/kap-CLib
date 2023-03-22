/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kprint_put_others
*/

#include "kapprintf.h"

void kap_put_hex_low(int fd, va_list *data, kprintf_info_t intel) {
    int nb = va_arg(*data, int);
    string str = int_to_hex(nb);

    if (intel.flag & KPRINTF_FLAG_HASH)
        str_add_str_at_begin(&str, "0x");
    str_to_lower(str);
    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_HEX_LOW);
    kfree(str);
}

void kap_put_percent(int fd, va_list *data, kprintf_info_t intel) {
    intel.flag = KPRINTF_FLAG_NONE;
    intel.minimum_field_width = 0;
    intel.precision = 0;
    kprint_char('%', fd, intel);
}
