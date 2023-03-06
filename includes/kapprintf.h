/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapprintf
*/

#ifndef KAPPRINTF_H_
    #define KAPPRINTF_H_

    #include "kapstring.h"
    #include <stdarg.h>

    void kprintf_fd(int fd, cstring format, ...);

    #define kprintf(format, ...) kprintf_fd(FD_OUT, format, ##__VA_ARGS__)
    #define kprintf_err(format, ...) kprintf_fd(FD_ERR, format, ##__VA_ARGS__)

    #ifndef KAP_PRINTF_FUNCS
        void kap_put_char(char c);
    #endif


#endif /* !KAPPRINTF_H_ */
