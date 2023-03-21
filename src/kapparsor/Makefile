##
## KAP PROJECT, 2023
## C Lib
## File description:
## Makefile
##

PATH_PARSER	=	./src/kapparsor/
PATH_COMMON	=	$(PATH_PARSER)common/
PATH_YML	=	$(PATH_PARSER)yaml/
PATH_XML	=	$(PATH_PARSER)xml/

SRC_PARSER	=	$(PATH_COMMON)config_open.c	\

SRC_YML	=	$(PATH_YML)yaml_init.c				\
			$(PATH_YML)yaml_key_exists.c		\
			$(PATH_YML)yaml_parse.c				\
			$(PATH_YML)yaml_read.c				\
			$(PATH_YML)yaml_save.c				\
			$(PATH_YML)yaml_get.c				\
			$(PATH_YML)yaml_find_first_node.c	\
			$(PATH_YML)yaml_destroy_node.c		\
			$(PATH_YML)yaml_set.c				\

SRC_XML	=	$(PATH_XML)xml_open.c						\
			$(PATH_XML)xml_close.c						\
			$(PATH_XML)xml_get_element_attribute.c		\
			$(PATH_XML)xml_parse.c						\
			$(PATH_XML)xml_save.c						\
			$(PATH_XML)xml_get_elem_tag.c				\
			$(PATH_XML)xml_add.c						\

SRC_PARSER	+=	$(SRC_YML)
SRC_PARSER	+=	$(SRC_XML)

OBJ_PARSER	=	$(SRC_PARSER:.c=.o)
