/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_put_char
*/

#include "kaptools.h"
#include "kapstring.h"
#include "kapprintf.h"
#include <unistd.h>

void kprint_char(char c, int fd, kprintf_info_t intel) {
    string str = str_create_char(c);

    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_CHAR);
    kfree(str);
}

void kprint_string(cstring str, int fd, kprintf_info_t intel, kprintf_type_t type) {
    string cpy = str_copy(str);
    ksize_t len = str_len(cpy);
    char more = ' ';

    if (cpy == NULL)
        cpy = str_create_string("nil");
    if (intel.flag & KPRINTF_FLAG_ZERO && (type != KPRINTF_TYPE_PRINT_STRING && type != KPRINTF_TYPE_PRINT_CHAR))
        more = '0';
    if (intel.minimum_field_width > 0) {
        for (int i = intel.minimum_field_width; i > len; i--) {
            if (intel.flag & KPRINTF_FLAG_MINUS) {
                str_add_char(&cpy, ' ');
            } else {
                str_add_char_at_begin(&cpy, more);
            }
        }
    }
    ksize_t nlen = str_len(cpy);
    if (type == KPRINTF_TYPE_PRINT_STRING && intel.precision > 0)
        nlen = intel.precision;
    write(fd, cpy, nlen);
    kfree(cpy);
}

void kap_put_char(int fd, va_list *data, kprintf_info_t intel) {
    char c = (char)va_arg(*data, int);
    string str = str_create_char(c);

    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_CHAR);
    kfree(str);
}

void kap_put_string(int fd, va_list *data, kprintf_info_t intel) {
    string str = va_arg(*data, string);
    
    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_STRING);
}

void kap_put_int(int fd, va_list *data, kprintf_info_t intel) {
    int nb = va_arg(*data, int);
    string str = int_to_str(nb);
    char more = ' ';

    if (intel.flag & KPRINTF_FLAG_ZERO)
        more = '0';
    if (intel.flag & KPRINTF_FLAG_SPACE && nb >= 0)
        str_add_char_at_begin(&str, more);
    if (intel.flag & KPRINTF_FLAG_PLUS && nb >= 0)
        str_add_char_at_begin(&str, '+');
    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_INT);
    kfree(str);
}

void kap_put_hex(int fd, va_list *data, kprintf_info_t intel) {
    int nb = va_arg(*data, int);
    string str = int_to_hex(nb);

    if (intel.flag & KPRINTF_FLAG_HASH)
        str_add_str_at_begin(&str, "0x");
    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_HEX);
    kfree(str);
}

void kap_put_bin(int fd, va_list *data, kprintf_info_t intel) {
    int nb = va_arg(*data, int);
    string str = int_to_bin(nb);

    if (intel.flag & KPRINTF_FLAG_HASH)
        str_add_str_at_begin(&str, "0b");
    kprint_string(str, fd, intel, KPRINTF_TYPE_PRINT_BIN);
    kfree(str);
}
