##
## EPITECH PROJECT, 2024
## AbstractVM
## File description:
## Makefile
##

CC = g++ -g -o

SRC_CPP = src/main.cpp	\
		  src/Factory.cpp	\
		  src/Parser.cpp	\
		  src/Operand/Int8.cpp	\
		  src/Operand/Int32.cpp	\
		  src/Operand/Int16.cpp	\
		  src/Operand/Double.cpp	\
		  src/Operand/Float.cpp	\
		  src/Format.cpp	\
		  src/Build.cpp		\
		  src/Vm.cpp	\
		  src/Exception.cpp	\

OBJ_CPP = $(SRC_CPP:.cpp=.o)

SRC_TEST =	src/Factory.cpp	\
		  src/Parser.cpp	\
		  src/Operand/Int8.cpp	\
		  src/Operand/Int32.cpp	\
		  src/Operand/Int16.cpp	\
		  src/Operand/Double.cpp	\
		  src/Operand/Float.cpp	\
		  src/Format.cpp	\
		  src/Build.cpp		\
		  src/Vm.cpp	\
		  src/Exception.cpp	\

TESTNAME	=	unit_tests	\

TEST_LIST	=	tests/Command_tests.cpp	\

TEST = $(TESTNAME) $(SRC_TEST) $(TEST_LIST) --coverage -lcriterion

OBJ = $(OBJ_CPP)

NAME =	abstractVM	\

CXXFLAGS = -Wall -Wextra

CPPFLAGS = -iquote ./includes/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(NAME) $(OBJ) $(CPPFLAGS) $(CXXFLAGS)

tests_run:
	$(CC) $(TEST) $(CPPFLAGS) $(CXXFLAGS) -I./includes/ -I./includes/Operand
	./$(TESTNAME) && gcovr --branches --exclude tests/

clean:
	rm -f *.o
	rm -f Core/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)
	rm -f $(OBJ)
	rm -f *gc*

re: clean fclean all

.PHONY: all clean fclean re debug tests_run
