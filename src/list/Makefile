##
## KAP PROJECT, 2023
## C Lib
## File description:
## Makefile
##

PATH_CHAINED_LIST	=	./src/list/chained/
PATH_MAP			=	./src/list/map/

SRC_CHAINED_LIST	=	$(PATH_CHAINED_LIST)chained_push.c			\
						$(PATH_CHAINED_LIST)init_chained_list.c		\
						$(PATH_CHAINED_LIST)list_get.c				\
						$(PATH_CHAINED_LIST)list_pop.c				\
						$(PATH_CHAINED_LIST)list_remove.c			\

OBJ_CHAINED_LIST	=	$(SRC_CHAINED_LIST:.c=.o)

SRC_MAP	=	$(PATH_MAP)map_destroy.c		\
			$(PATH_MAP)map_init.c			\
			$(PATH_MAP)map_insert.c			\
			$(PATH_MAP)map_key_exists.c		\

SRC_LIST	=	$(SRC_CHAINED_LIST)
SRC_LIST	+=	$(SRC_MAP)

OBJ_LIST	=	$(OBJ_CHAINED_LIST)
