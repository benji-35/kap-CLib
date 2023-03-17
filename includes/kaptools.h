/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kaptools
*/

#ifndef KAPTOOLS_H_
    #define KAPTOOLS_H_

    #ifndef NULL
        #define NULL ((void *)0)
    #endif

    #ifndef bool
        #include <stdlib.h>
        #define bool char
        #define true ((char)1)
        #define false ((char)0)

        #define NEW_BOOL(value) ({bool *__retval__ = calloc(1, sizeof(bool)); *__retval__ = value; __retval__;})
    #endif

    #ifndef KERROR
        #define KERROR 1
    #endif

    #ifndef KSUCCESS
        #define KSUCCESS 0
    #endif

    #define K_IN 0
    #define K_OUT 1
    #define K_ERR 2
    #define FD_IN K_IN
    #define FD_OUT K_OUT
    #define FD_ERR K_ERR

    #ifndef ksize_t
        #define ksize_t unsigned long
    #endif

    #ifndef auto
        #define auto __auto_type
    #endif

    #ifndef private
        #define private static
    #endif

    #ifndef public
        #define public
    #endif

    #ifndef unused
        #define unused __attribute__((unused))
    #endif
    #ifndef deprecated
        #define deprecated(message) (__attribute__((deprecated(message))))
    #endif
    #ifndef warning
        #define warning(message) (__attribute__((warning(message))))
    #endif
    #ifndef unavailable
        #define unavailable(message) (__attribute__((unavailable(message))))
    #endif
    #ifndef error
        #define error(message) (__attribute__((error(message))))
    #endif
    #ifndef notnull
        #define notnull (__attribute__((nonnull)))
    #endif

#endif /* !KAPTOOLS_H_ */
