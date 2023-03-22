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

void kprint_char(char c, int fd, int nb_spaces) {
    string str = str_create_char(c);

    kprint_string(str, fd, nb_spaces);
    kfree(str);
}

void kprint_string(cstring str, int fd, int nb_spaces) {
    ksize_t len = str_len(str);

    if (str == NULL)
        len = 4;
    if (nb_spaces > 0) {
        for (int i = nb_spaces; i > len; i--)
            write(fd, " ", 1);
    }
    if (str == NULL)
        write(fd, "NULL", 4);
    else
        write(fd, str, str_len(str));
}

void kap_put_char(int fd, va_list *data) {
    if (data == NULL)
        return (void)write(fd, "NULL", 4);
    char c = (char)va_arg(*data, int);
    string str = str_create_char(c);
    kprint_string(str, fd, 0);
    kfree(str);
}

void kap_put_string(int fd, va_list *data) {
    string str = va_arg(*data, string);
    
    kprint_string(str, fd, 0);
}

void kap_put_int(int fd, va_list *data) {
    int nb = va_arg(*data, int);
    string str = int_to_str(nb);

    kprint_string(str, fd, 0);
    kfree(str);
}

void kap_put_hex(int fd, va_list *data) {
    int nb = va_arg(*data, int);
    string str = int_to_hex(nb);

    kprint_string(str, fd, 0);
    kfree(str);
}

void kap_put_bin(int fd, va_list *data) {
    int nb = va_arg(*data, int);
    string str = int_to_bin(nb);

    kprint_string(str, fd, 0);
    kfree(str);
}
