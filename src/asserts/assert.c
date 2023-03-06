/*
** KAP PROJECT, 2023
** C Lib
** File description:
** assert
*/

#include "kapassert.h"
#include "kapprintf.h"

bool kassert_f(bool isfail, cstring __expr, cstring __fname, int __line)
{
    if (!isfail)
        return (false);
    kfprintf(KERROR, "Assertion failed in [%s:%d] -> (%s)\n", \
    __fname, __line, __expr);
    return (true);
}

bool kassert_e(bool isfail, cstring __expr, cstring __fname, int __line)
{
    if (!isfail)
        return (false);
    kfprintf(KERROR, "Assertion failed in [%s:%d] -> (%s)\n", \
    __fname, __line, __expr);
    exit (84);
    return (true);
}
