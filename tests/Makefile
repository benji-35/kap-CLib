##
## Kap PROJECT, 2023
## C Lib - Tests
## File description:
## Makefile for tests lib
##

PATH_TESTS = ./tests/

SRC_TESTS	=	$(PATH_TESTS)kap_string_tests.c			\
				$(PATH_TESTS)kap_string_errors_tests.c	\
				$(PATH_TESTS)kap_text_tests.c			\
				$(PATH_TESTS)kap_string_calcul_tests.c	\
				$(PATH_TESTS)kap_map_tests.c			\
				$(PATH_TESTS)kap_yml_tests.c			\
				$(PATH_TESTS)kap_config_test.c			\
				#$(PATH_TESTS)kap_memory_tests.c		\

GCOVR_EXCLUDES = 	-e $(PATH_TESTS)kap_string_tests.c			\
					-e $(PATH_TESTS)kap_string_errors_tests.c	\
					-e $(PATH_TESTS)kap_text_tests.c			\
					-e $(PATH_TESTS)kap_string_calcul_tests.c	\
					-e $(PATH_TESTS)kap_map_tests.c				\
					-e $(PATH_TESTS)kap_yml_tests.c				\
					-e $(PATH_TESTS)kap_config_test.c			\

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)
