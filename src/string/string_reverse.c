/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_reverse
*/

#include "kapstring.h"

void str_reverse(string str) {
    int len = str_len(str);
    int i = 0;
    char tmp = 0;

    for (i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

string str_reverse_copy(cstring str) {
    string cpy = str_copy(str);

    str_reverse(cpy);
    return(cpy);
}
