/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kprintf_call
*/

#include "kapprintf.h"
#include "kaplist.h"
#include "kaptools.h"
#include "kapstring.h"

private int nb_spaces(cstring str, ksize_t *position, va_list *args) {
    int nb = 0;
    ksize_t i = *position;

    if (str[i] == '*') {
        nb = va_arg(*args, int);
        (*position)++;
        return (nb);
    }
    for (; i < str_len(str); i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        nb *= 10;
        nb += str[i] - '0';
    }
    *position = i;
    return (nb);
}

private kprintf_flag_t check_flags(cstring str, ksize_t *position) {
    kprintf_flag_t flag = KPRINTF_FLAG_NONE;
    for (; *position < str_len(str); (*position)++) {
        if (str[*position] == ' ' && !(flag & KPRINTF_FLAG_SPACE))
            flag |= KPRINTF_FLAG_SPACE;
        else if (str[*position] == '-' && !(flag & KPRINTF_FLAG_MINUS))
            flag |= KPRINTF_FLAG_MINUS;
        else if (str[*position] == '+' && !(flag & KPRINTF_FLAG_PLUS))
            flag |= KPRINTF_FLAG_PLUS;
        else if (str[*position] == '#' && !(flag & KPRINTF_FLAG_HASH))
            flag |= KPRINTF_FLAG_HASH;
        else if (str[*position] == '0' && !(flag & KPRINTF_FLAG_ZERO))
            flag |= KPRINTF_FLAG_ZERO;
        else
            break;
    }
    return (flag);
}

private kprintf_info_t kprintf_info_init(cstribg str, ksize_t *position, va_list *args) {
    kprintf_info_t info;

    info.flag = check_flags(str, position);
    info.minimum_field_width = nb_spaces(str, position, args);
    if (str[*position] == '.')
        info.precision = nb_spaces(str, position, args);
    else
        info.precision = 0;        
    return (info);
}

private void loop_krpintf(va_list *args, \
    kprint_tool_t tool, cstring format, int fd) {

    for (ksize_t i = 0; i < str_len(format) ; i++) {
        if (format[i] == '%') {
            i++;
            kprintf_info_t intel = kprintf_info_init(format, &i, args);
            string key = str_create_char(format[i]);
            auto func = (KPRINTF_FUNC)map_get(tool.functions, key);
            kfree(key);
            if (func != NULL) {
                func(fd, args, intel);
            } else {
                kprint_string("%", fd, 0);
                kprint_char(format[i], fd, 0);
            }
            i++;
        } else
            kprint_char(format[i], fd, 0);
    }
}

void kprintf_fd(int fd, cstring format, ...) {
    kprint_tool_t kprint_tool = kprint_init();
    va_list args;

    va_start(args, format);
    loop_krpintf(&args, kprint_tool, format, fd);
    va_end(args);
    map_destroy(kprint_tool.functions);
}
