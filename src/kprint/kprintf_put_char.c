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

void kap_put_char(int fd, void *c) {
    write(fd, (char *)c, 1);
}

void kap_put_string(int fd, void *str) {
    write(fd, (string)str, str_len((string)str));
}

void kap_put_int(int fd, void *nb) {
    string str = int_to_str(*((int *)nb));

    kap_put_string(fd, str);
    kfree(str);
}

void kap_put_hex(int fd, void *nb) {
    string str = int_to_hex(*((int *)nb));

    kap_put_string(fd, str);
    kfree(str);
}

void kap_put_bin(int fd, void *nb) {
    string str = int_to_bin(*((int *)nb));

    kap_put_string(fd, str);
    kfree(str);
}
