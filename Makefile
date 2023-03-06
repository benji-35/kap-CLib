##
## KAP PROJECT, 2023
## C Lib - Makefile
## File description:
## Makefile for kap C Lib
##

include ./includes/Makefile
include ./src/Makefile
include ./tests/Makefile

NAME = libkap.a
GCC = gcc

.Phony: all clean fclean re run_tests

all: $(NAME)

.c.o:
	@$(GCC) -c $< -o $@ $(KAP_INCLUDES) -fprofile-arcs -ftest-coverage
	@echo "[KAP C LIB] => $@ Compiling $<"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

build_tests: all $(OBJ_TESTS)
	$(GCC) -o kap_tests $(OBJ_TESTS) $(NAME) $(KAP_INCLUDES) -lcriterion --coverage
	@echo "[KAP C LIB] => $@ Compiling $<"

start_runnig_tests: build_tests
	clear
	@(./kap_tests && gcovr -r . -e $(SRC_TESTS)) || echo -e "\n[KAP C LIB] => $@ \033[0;31mTests failed\033[39m"

run_tests: build_tests start_runnig_tests fclean

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_TESTS)
	@find . -name "*.gcda" -type f -delete
	@find . -name "*.gcno" -type f -delete
	@echo "[KAP C LIB] => $@ Cleaning"

fclean: clean
	@rm -f $(NAME)
	@rm -f kap_tests
	@echo "[KAP C LIB] => $@ Cleaning"

re: fclean all
