/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapmath
*/

#ifndef KAPMATH_H_
    #define KAPMATH_H_

    #ifndef ABS
        #define ABS(x) ((x) < 0 ? -(x) : (x))
    #endif

    #ifndef MIN
        #define MIN(x, y) ((x) < (y) ? (x) : (y))
    #endif

    #ifndef MAX
        #define MAX(x, y) ((x) > (y) ? (x) : (y))
    #endif

    extern int power(int nb, int p);

#endif /* !KAPMATH_H_ */
