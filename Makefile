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

C_FLAGS = -fprofile-arcs -ftest-coverage -Wnonnull -g

.Phony: all clean fclean re run_tests build_tests

all: $(NAME)

.c.o:
	@$(GCC) -c $< -o $@ $(KAP_INCLUDES) $(C_FLAGS)
	@echo "[KAP C LIB] => $@ Compiling $<"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

build_tests: all $(OBJ_TESTS)
	@$(GCC) -o kap_tests $(OBJ_TESTS) $(NAME) $(KAP_INCLUDES) -lcriterion --coverage
	@echo "[KAP C LIB] =>\033[0;32m Building tests \033[0m"

check_coverage:
	@echo "[KAP C LIB] =>\033[0;32m Checking coverage \033[0m"
	@gcovr -r . $(GCOVR_EXCLUDES)

start_runnig_tests: build_tests
	@echo "[KAP C LIB] =>\033[0;32m Running tests \033[0m"
	@./kap_tests

run_tests: build_tests start_runnig_tests check_coverage fclean

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
