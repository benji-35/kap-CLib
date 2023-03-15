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

private void loop_krpintf(va_list args, \
    kprint_tool_t tool, cstring format, int fd) {
    string str = NULL;

    for (ksize_t i = 0; i < str_len(format) ; i++) {
        str = str_copy(&format[i]);
        if (format[i] == '%') {
            auto func = (KPRINTF_FUNC)map_get(tool.functions, &format[i + 1]);
            if (func != NULL) {
                func(fd, args);
            } else {
                kap_put_char(fd, "%");
                kap_put_char(fd, &str[i]);
            }
            i++;
        } else
            kap_put_char(fd, &str[i]);
        kfree(str);
    }
}

void kprintf_fd(int fd, cstring format, ...) {
    kprint_tool_t kprint_tool = kprint_init();
    va_list args;

    va_start(args, format);
    loop_krpintf(args, kprint_tool, format, fd);
    va_end(args);
    map_destroy(kprint_tool.functions);
}
