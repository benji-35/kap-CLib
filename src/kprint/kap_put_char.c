/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_put_char
*/

#include "kaptools.h"
#include <unistd.h>

void kap_put_char(char c) {
    write(FD_OUT, &c, 1);
}
