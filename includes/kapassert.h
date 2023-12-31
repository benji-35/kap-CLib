/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapassert
*/

#ifndef KAPASSERT_H_
    #define KAPASSERT_H_

    #ifndef KAPSTRING_H_
        #include "kapstring.h"
    #endif

    #ifdef __cplusplus
        extern "C" {
        #endif

        extern bool kassert_e(bool isfail, cstring __expr, cstring __fname, int __line);
        extern bool kassert_f(bool isfail, cstring __expr, cstring __fname, int __line);

        #define kassert(__expr) kassert_f(__expr, #__expr, __FILE__, __LINE__)
        #define keassert(__expr) kassert_e(__expr, #__expr, __FILE__, __LINE__)

    #ifdef __cplusplus
        }
    #endif

#endif /* !KAPASSERT_H_ */
