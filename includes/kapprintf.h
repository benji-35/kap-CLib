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

    #define kfprintf(fd, format, ...) kprintf_fd(fd, format, ##__VA_ARGS__)
    #define kprintf(format, ...) kprintf_fd(FD_OUT, format, ##__VA_ARGS__)
    #define kprintf_err(format, ...) kprintf_fd(FD_ERR, format, ##__VA_ARGS__)

    typedef struct {
        map_t *functions;
    } kprint_tool_t;

    #ifndef KAP_PRINTF_FUNCS
        #define KAP_PRINTF_FUNCS

        #define KPRINTF_FUNC void (*)(int fd, va_list *list, kprintf_info_t intel)
        #define KPRINTF_FUNC_DATA void *
        #define KPRINTF_FUNC_COUNT 5

        typedef enum kprintf_flag {
            KPRINTF_FLAG_NONE = 0,
            KPRINTF_FLAG_MINUS = 1,
            KPRINTF_FLAG_ZERO = 2,
            KPRINTF_FLAG_HASH = 4,
            KPRINTF_FLAG_SPACE = 8,
            KPRINTF_FLAG_PLUS = 16,
        } kprintf_flag_t;

        typedef enum krpintf_type_print_e {
            KPRINTF_TYPE_PRINT_CHAR,
            KPRINTF_TYPE_PRINT_INT,
            KPRINTF_TYPE_PRINT_STRING,
            KPRINTF_TYPE_PRINT_HEX,
            KPRINTF_TYPE_PRINT_HEX_LOW,
            KPRINTF_TYPE_PRINT_BIN,
            KPRINTF_TYPE_PRINT_PERCENT,
        } kprintf_type_t;

        typedef struct kprintf_info_s {
            kprintf_flag_t flag;
            int minimum_field_width;
            int precision;
        } kprintf_info_t;

        kprint_tool_t kprint_init(void);

        extern void kap_put_char(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_int(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_string(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_hex(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_hex_low(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_bin(int fd, va_list *data, kprintf_info_t intel);
        extern void kap_put_percent(int fd, va_list *data, kprintf_info_t intel);

        extern void kprint_string(cstring str, int fd, kprintf_info_t intel, kprintf_type_t type);
        extern void kprint_char(char c, int fd, kprintf_info_t intel);

    #endif


#endif /* !KAPPRINTF_H_ */
