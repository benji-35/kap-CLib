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
         * @brief add char to string from index
         * @param str string to add char to
         * @param c char to add
        */
        extern void str_add_char_from(string *str, char c, ksize_t from);
        /**
         * @brief add string to string
        */
        extern void str_add_str(string *str, cstring cstr);
        /**
         * @brief add string to string from index
         * @param str string to add string to
         * @param cstr string to add
         * @param from ksize_t index
        */
        extern void str_add_str_from(string *str, cstring cstr, ksize_t from);
        /**
         * @brief add char at begin of string
         * @param str string to add char to
         * @param c char to add
        */
        extern void str_add_char_at_begin(string *str, char c);
        /**
         * @brief add string at begin of string
         * @param str string to add string to
         * @param cstr string to add
        */
        extern void str_add_str_at_begin(string *str, cstring cstr);
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
         * @brief remove a char at a specific index
         * @param str string to remove char from
         * @param index ksize_t (index of the char to remove)
        */
        extern void str_remove_char_at(string *str, ksize_t index);
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
         * @brief remove first chars from a string
         * @param str string to remove chars from
         * @param c char to remove
         * @note remove all chars from the start of the string until the first char that is not c
        */
        extern void str_remove_first_chars(string *str, char c);
        /**
         * @brief check if string starts with a char
        */
        extern bool str_start_cwith(cstring str, char c);
        /**
         * @brief check if string starts with a string
         * @param str constant string
         * @param cstr string must be contains in str
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
         * @brief split a string into a text from a string from a specific index
         * @param str constant string
         * @param c constant string (string to split from)
         * @param from ksize_t (index to start splitting from)
         * @return text_t
         * @note this function will split a string into a text from a string from a specific index
        */
        extern text_t str_split_str_from(cstring str, cstring c, ksize_t from);
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
       /**
        * @brief reverse a string
        * @param str string to reverse
        * @note this function will reverse a string
       */
        extern void str_reverse(string str);

        /**
         * @brief get a reversed copy of a string
         * @param str constant string
         * @return string
         * @note this function will return a reversed copy of a string
        */
        extern string str_reverse_copy(cstring str);

        /**
         * @brief replace a string with another string in string
         * @param source string to replace in
         * @param target string to replace
         * @param replace string to replace with
         * @return string (replaced string) allocated in another string
         * @note this function will replace a string with another string in a string
        */
        extern string str_replace(cstring source, cstring target, cstring replace);

        /**
         * @brief clear a string
         * @param str string to clear
         * @note this function will clear a string
        */
        extern void str_clear(string *str);

        /**
         * @brief get a string between two strings
         * @param str constant string
         * @param start constant string (start string)
         * @param end constant string (end string)
         * @return string (string between two strings)
         * @note this function will return a string between two strings
        */
        extern string str_value_between(cstring str, cstring start, cstring end);
        /**
         * @brief get number of occurences of a char in a string
         * @param str constant string
         * @param c char (char to count)
         * @return ksize_t (number of occurences)
        */
        extern ksize_t str_count_char(cstring str, char c);
        /**
         * @brief get number of occurences of a string in a string
         * @param str constant string
         * @param cstr constant string (string to count)
         * @return ksize_t (number of occurences)
        */
        extern ksize_t str_count_str(cstring str, cstring cstr);


        #define str_length(str) str_len(str)
    #endif

    #ifndef KAPSTRING_CALCULUS_H_
        #define KAPSTRING_CALCULUS_H_

        /**
         * @brief get binary from a number
         * @param nb int (number to convert)
         * @return string (binary)
         * @note this function will return a binary string from a number
        */
        extern string int_to_bin(const int nb);

        /**
         * @brief get octal from a number
         * @param nb int (number to convert)
         * @return string (octal)
         * @note this function will return a octal string from a number
        */
        extern string int_to_oct(const int nb);

        /**
         * @brief get hexadecimal from a number
         * @param nb int (number to convert)
         * @return string (hexadecimal)
         * @note this function will return a hexadecimal string from a number
        */
        extern string int_to_hex(const int nb);

        /**
         * @brief int to string
        */
        extern string int_to_str(const int nb);
    #endif

    #ifndef KAPSTRING_TEXT_H_
        #define KAPSTRING_TEXT_H_

        /**
         * @brief create a text
         * @return text_t
         * @note this function will create a text
        */
        extern text_t text_create(void);
        /**
         * @brief destroy a text
         * @param text text_t
         * @note this function will destroy a text
        */
        extern void text_destroy(text_t text);
        /**
         * @brief add a line to a text
         * @param text text_t
         * @param line string (line to add)
         * @note this function will add a line to a text
        */
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
         * @brief get string of all lines in text with a separator
         * @param text text_t
         * @param separator constant string (separator to use)
         * @return string
         * @note this function will return a string of all lines in the text with a separator
        */
        extern string text_to_string_separator(ctext_t text, cstring separator);
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
