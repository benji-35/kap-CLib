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
        #define bool char
        #define true 1
        #define false 0
    #endif

    #ifndef KERROR
        #define KERROR 1
    #endif

    #ifndef KSUCCESS
        #define KSUCCESS 0
    #endif

    #define FD_IN 0
    #define FD_OUT 1
    #define FD_ERR 2

    #ifndef ksize_t
        #define ksize_t unsigned long
    #endif

    #ifndef auto
        #define auto __auto_type
    #endif

    #ifndef private
        #define private static
    #endif

    #ifndef ABS
        #define ABS(x) ((x) < 0 ? -(x) : (x))
    #endif

#endif /* !KAPTOOLS_H_ */
