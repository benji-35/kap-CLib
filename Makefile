##
## KAP PROJECT, 2023
## C Lib - Makefile
## File description:
## Makefile for kap C Lib
##

include ./includes/Makefile
include ./src/string/Makefile
include ./tests/Makefile

NAME = libkap.a
GCC = gcc

all: $(NAME)

.c.o:
	@$(GCC) -c $< -o $@ $(KAP_INCLUDES)
	@echo "Kap C-Lib => $@ Compiling $<"

$(NAME): $(OBJ_STRING)
	@ar rc $(NAME) $(OBJ_STRING)

build_tests: all $(OBJ_TESTS)
	$(GCC) -o kap_tests $(OBJ_TESTS) $(NAME) $(KAP_INCLUDES) -lcriterion
	@echo "Kap C-Lib => $@ Compiling $<"

clean:
	@rm -f $(OBJ_STRING)
	@rm -f $(OBJ_TESTS)
	@echo "Kap C-Lib => $@ Cleaning"

fclean: clean
	@rm -f $(NAME)
	@rm -f kap_tests
	@echo "Kap C-Lib => $@ Cleaning"

re: fclean all
