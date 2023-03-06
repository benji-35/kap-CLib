/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapstring include
*/

#ifndef KAPSTRING_H_
#define KAPSTRING_H_

#include "kaplist.h"
#include "kapmemory.h"

typedef char *string;
typedef const char *cstring;

typedef struct text_s {
    string *str;
    int len;
} text_t;

#ifndef KAP_STRING_FUNC
    #define KAP_STRING_FUNC

    /**
     * @brief Create an empty string
     * 
    */
    extern string str_create_empty(void);
    /**
     * @brief Create a string from a char
     * @param c char
    */
    extern string str_create_char(char c);
    /**
     * @brief Create a string from a cstring
     * @param cstr constant cstring
    */
    extern string str_create_string(cstring cstr);
    /**
     * @brief get length of a string
     * @param str constant string
    */
    extern ksize_t str_len(cstring str);
    /**
     * @brief copy a string into another
     * @param src constant string to copy
    */
    extern string str_copy(cstring src);
    /**
     * @brief copy a string into another
     * @param dest string to copy into
     * @param src constant string to copy
    */
    extern string str_copy_to(string dest, cstring src);
    /**
     * @brief add char to string
    */
    extern void str_add_char(string *str, char c);
    /**
     * @brief add string to string
    */
    extern void str_add_string(string *str, cstring cstr);
    /**
     * @brief check if string is empty
    */
    extern bool str_is_empty(cstring str);
    /**
     * @brief check if string is a number
    */
    extern bool str_is_number(cstring str);
    /**
     * @brief check if string is a decimal
    */
    extern bool str_is_decimal(cstring str);
    /**
     * @brief check if string is equal to another
     * @param str1 constant string
     * @param str2 constant string
     * @param case_sensitive bool
     * @return bool
     * @note if case_sensitive is true, the function will check if the strings are equal
     */
    extern bool str_is_equal(cstring str1, cstring str2, bool case_sensitive);
    /**
     * @brief check if string is equal to another from index
     * @param str1 constant string
     * @param str2 constant string
     * @param from ksize_t index
     * @param case_sensitive bool (true if case sensitive)
    */
    extern bool str_is_equal_from(cstring str1, cstring str2, ksize_t from, bool case_sensitive);
    /**
     * @brief check if string is not equal to another
     * @param str1 constant string
     * @param str2 constant string
     * @param case_sensitive bool
     * @return bool
     * @note if case_sensitive is true, the function will check if the strings are not equal
     */
    extern bool str_is_not_equal(cstring str1, cstring str2, bool case_sensitive);
    /**
     * @brief check if string is not empty
    */
    extern bool str_is_not_empty(cstring str);
    /**
     * @brief checj if string contains a char
    */
    extern bool str_contains_char(cstring str, char c);
    /**
     * @brief check if string contains a string
    */
    extern bool str_contains_string(cstring str, cstring cstr);
    /**
     * @brief check if string contains a char from a specific index
    */
    extern bool str_contains_char_from(cstring str, char c, ksize_t from);
    /**
     * @brief check if string contains a string from a specific index
    */
    extern bool str_contains_string_from(cstring str, cstring cstr, ksize_t from);
    /**
     * @brief get index of a char in a string
    */
    extern ksize_t str_index_of_char(cstring str, char c);
    /**
     * @brief get index of a string in a string
    */
    extern ksize_t str_index_of_string(cstring str, cstring cstr);
    /**
     * @brief get index of a char in a string from a specific index
    */
    extern ksize_t str_index_of_char_from(cstring str, char c, ksize_t from);
    /**
     * @brief get index of a string in a string from a specific index
    */
    extern ksize_t str_index_of_string_from(cstring str, cstring cstr, ksize_t from);
    /**
     * @brief get index of a char in a string from a specific index
    */
    extern ksize_t str_last_index_of_char(cstring str, char c);
    /**
     * @brief get index of a string in a string from a specific index
    */
    extern ksize_t str_last_index_of_string(cstring str, cstring cstr);
    /**
     * @brief remove a char from a string
     * @param str string to remove char from
     * @param c char to remove
     * @param all bool (if true, remove all occurences of the char)
    */
    extern void str_remove_char(string *str, char c, bool all);
    /**
     * @brief remove a string from a string
     * @param str string to remove string from
     * @param cstr string to remove
     * @param all bool (if true, remove all occurences of the string)
    */
    extern void str_remove_string(string *str, cstring cstr, bool all);
    /**
     * @brief remove a char from a string from a specific index
     * @param str string to remove char from
     * @param c char to remove
     * @param from ksize_t (index to start removing from)
     * @param all bool (if true, remove all occurences of the char)
    */
    extern void str_remove_char_from(string *str, char c, ksize_t from, bool all);
    /**
     * @brief remove a string from a string from a specific index
     * @param str string to remove string from
     * @param cstr string to remove
     * @param from ksize_t (index to start removing from)
     * @param all bool (if true, remove all occurences of the string)
    */
    extern void str_remove_string_from(string *str, cstring cstr, ksize_t from, bool all);
    /**
     * @brief check if string starts with a char
    */
    extern bool str_start_cwith(cstring str, char c);
    /**
     * @brief check if string starts with a string
    */
    extern bool str_start_with(cstring str, cstring cstr);
    /**
     * @brief check if string starts with a char from a specific index
    */
    extern bool str_start_cwith_from(cstring str, char c, ksize_t index);
    /**
     * @brief check if string starts with a string from a specific index
    */
   bool str_start_with_from(cstring str, cstring start, ksize_t index);
    /**
     * @brief check if string ends with a char
    */
    extern bool str_end_cwith(cstring str, char c);
    /**
     * @brief check if string ends with a string
    */
    extern bool str_end_with(cstring str, cstring cstr);

#endif

#endif /* !KAPSTRING_H_ */
