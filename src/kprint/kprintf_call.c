/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kprintf_call
*/

#include "kapprintf.h"

void kprintf_fd(int fd, cstring format, ...)
{
    va_list args;
    va_start(args, format);
    kfprintf_fd(fd, format, args);
    va_end(args);
}
