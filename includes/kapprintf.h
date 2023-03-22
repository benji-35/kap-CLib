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

    typedef struct {
        map_t *functions;
    } kprint_tool_t;

    #ifndef KAP_PRINTF_FUNCS
        #define KAP_PRINTF_FUNCS

        #define KPRINTF_FUNC void (*)(int fd, va_list *list)
        #define KPRINTF_FUNC_DATA void *
        #define KPRINTF_FUNC_COUNT 5

        kprint_tool_t kprint_init(void);

        void kap_put_char(int fd, va_list *data);
        void kap_put_int(int fd, va_list *data);
        void kap_put_string(int fd, va_list *data);
        void kap_put_hex(int fd, va_list *data);
        void kap_put_bin(int fd, va_list *data);

        extern void kprint_string(cstring str, int fd, int nb_spaces);
        extern void kprint_char(char c, int fd, int nb_spaces);

    #endif


#endif /* !KAPPRINTF_H_ */
