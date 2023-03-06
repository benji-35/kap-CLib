/*
** KAP PROJECT, 2023
** C Lib
** File description:
** text_add_line
*/

#include "kapstring.h"

void text_add_line(text_t text, char *line)
{
    list_push(text, line);
}
