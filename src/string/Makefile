##
## KAP PROJECT, 2023
## C Lib - String
## File description:
## Makefile for string lib
##

PATH_STRING = ./src/string/
PATH_TEXT 	= ./src/string/text/

SRC_STRING	=	$(PATH_STRING)string_add.c					\
				$(PATH_STRING)string_check.c				\
				$(PATH_STRING)string_contains.c				\
				$(PATH_STRING)string_copy.c					\
				$(PATH_STRING)string_index_of.c				\
				$(PATH_STRING)string_init.c					\
				$(PATH_STRING)string_is_number.c			\
				$(PATH_STRING)string_last_index_of.c		\
				$(PATH_STRING)string_length.c				\
				$(PATH_STRING)string_remove.c				\
				$(PATH_STRING)string_start_with.c			\
				$(PATH_STRING)string_end_with.c				\
				$(PATH_STRING)string_transform.c			\
				$(PATH_STRING)str_substring.c				\
				$(PATH_STRING)string_split.c				\
				$(PATH_STRING)string_io.c					\
				$(PATH_STRING)string_reverse.c				\
				$(PATH_STRING)string_replace.c				\
				$(PATH_STRING)string_clear.c				\

SRC_TEXT	=	$(PATH_TEXT)text_create.c					\
				$(PATH_TEXT)text_add_line.c					\
				$(PATH_TEXT)text_to_string.c				\
				$(PATH_TEXT)text_io.c						\

SRC_CALCUL_STR	=	$(PATH_STRING)calcul/int_to_bin.c		\
					$(PATH_STRING)calcul/int_to_hex.c		\
					$(PATH_STRING)calcul/int_to_string.c	\

SRC_STRING	+=	$(SRC_TEXT)
SRC_STRING	+=	$(SRC_CALCUL_STR)


OBJ_STRING	=	$(SRC_STRING:.c=.o)
