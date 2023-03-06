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
    typedef list_t *text_t;
    typedef const list_t *ctext_t;

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
        extern void str_add_str(string *str, cstring cstr);
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
        /**
         * @brief set string to lowercase
        */
        extern void str_to_lower(string str);
        /**
         * @brief set string to uppercase
        */
        extern void str_to_upper(string str);
        /**
         * @brief get a substring from a string
         * @param str constant string
         * @param from ksize_t (index to start from)
         * @param to ksize_t (index to end at)
         * @return string
        */
        extern string str_substring(cstring str, ksize_t from, ksize_t to);
        /**
         * @brief get a substring from a string from a specific index
         * @param str constant string
         * @param from ksize_t (index to start from)
         * @return string
        */
        extern string str_substring_from(cstring str, ksize_t from);
        /**
         * @brief get a substring from a string to a specific index
         * @param str constant string
         * @param from ksize_t (index to end at)
         * @param size ksize_t (size of the substring)
         * @return string
        */
        extern string str_substring_size(cstring str, ksize_t from, ksize_t size);
        /**
         * @brief split a string into a text from a char
        */
        extern text_t str_split(cstring str, char c);
        /**
         * @brief split a string into a text from a string
        */
        extern text_t str_split_str(cstring str, cstring cstr);
        /**
         * @brief write a string to a file
         * @param str constant string
         * @param path constant string (path to write to)
        */
        extern void str_write(cstring str, cstring path);
        /**
         * @brief read a string from a file
         * @param path constant string (path to read from)
         * @return string
        */
       extern string str_read(cstring path);
    #endif

    #ifndef KAPSTRING_TEXT_H_
        #define KAPSTRING_TEXT_H_

        extern text_t text_create(void);
        extern void text_destroy(text_t text);
        extern void text_add_line(text_t text, string line);
        extern void text_add_lines_at(text_t text, string *lines, ksize_t index);
        extern void text_add_text(text_t text, ctext_t text2);
        extern void text_add_text_at(text_t text, ctext_t text2, ksize_t index);
        /**
         * @brief remove a line from a text
         * @param text text_t
         * @param index ksize_t (index to remove line from)
         * @note this function will remove the line at the index
        */
        extern void text_remove_line(text_t text, ksize_t index);
        /**
         * @brief remove lines from a text
         * @param text text_t
         * @param from ksize_t (index to remove lines from)
         * @param to ksize_t (index to remove lines to)
         * @note this function will remove lines from the from to the to
        */
        extern void text_remove_lines(text_t text, ksize_t from, ksize_t to);
        /**
         * @brief remove lines from a text
         * @param text text_t
         * @param index ksize_t (index to remove lines from)
         * @param size ksize_t (number of lines to remove)
         * @note this function will remove lines from the index to the index + size
        */
        extern void text_remove_lines_at(text_t text, ksize_t index, ksize_t size);
        /**
         * @brief remove all lines from position in text
         * @param text text_t
         * @param index ksize_t (index to remove lines from)
         * @note this function will remove all lines from the index to the end of the text
        */
        extern void text_remove_lines_from(text_t text, ksize_t index);
        /**
         * @brief clear a text
         * @param text text_t
         * @note this function will remove all lines from the text
        */
        extern void text_clear(text_t text);
        /**
         * @brief get a line from a text
         * @param text text_t
         * @param index ksize_t (index to get line from)
         * @return string
        */
        extern string text_get_line(ctext_t text, ksize_t index);
        /**
         * @brief get a line from a text
         * @param text text_t
         * @param index ksize_t (index to get line from)
         * @param size ksize_t (number of lines to get)
         * @return string
        */
        extern string text_get_line_size(ctext_t text, ksize_t index, ksize_t size);
        /**
         * @brief get a line in text from line to line
         * @param text text_t
         * @param from ksize_t (index to get line from)
         * @param to ksize_t (index to get line to)
        */
        extern string text_get_line_to(ctext_t text, ksize_t from, ksize_t to);
        /**
         * @brief get string of all lines in text
         * @param text text_t
         * @return string
         * @note this function will return a string of all lines in the text
        */
        extern string text_to_string(ctext_t text);
        /**
         * @brief write a text to a file
         * @param text text_t
         * @param path constant string (path to write to)
        */
        extern void text_write(ctext_t text, cstring path);
        /**
         * @brief read a text from a file
         * @param path constant string (path to read from)
         * @return text_t
        */
        extern text_t text_read(cstring path);

    #endif

#endif /* !KAPSTRING_H_ */
