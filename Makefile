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
	@echo "Kap C-Lib => $@ Compiling $<"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

build_tests: all $(OBJ_TESTS)
	$(GCC) -o kap_tests $(OBJ_TESTS) $(NAME) $(KAP_INCLUDES) -lcriterion --coverage
	@echo "Kap C-Lib => $@ Compiling $<"

start_runnig_tests: build_tests
	./kap_tests
	gcovr -r . -e $(SRC_TESTS)

run_tests: build_tests start_runnig_tests fclean

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_TESTS)
	@find . -name "*.gcda" -type f -delete
	@find . -name "*.gcno" -type f -delete
	@echo "Kap C-Lib => $@ Cleaning"

fclean: clean
	@rm -f $(NAME)
	@rm -f kap_tests
	@echo "Kap C-Lib => $@ Cleaning"

re: fclean all
