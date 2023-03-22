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

private void loop_krpintf(va_list *args, \
    kprint_tool_t tool, cstring format, int fd) {

    for (ksize_t i = 0; i < str_len(format) ; i++) {
        if (format[i] == '%') {
            string key = str_create_char(format[i + 1]);
            auto func = (KPRINTF_FUNC)map_get(tool.functions, key);
            kfree(key);
            if (func != NULL) {
                func(fd, args);
            } else {
                kprint_string("%", fd, 0);
                kprint_char(format[i + 1], fd, 0);
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
