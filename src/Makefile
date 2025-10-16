OS := $(shell uname)
CC = -Wall -Werror -Wextra -std=c++17
FLAGS = -lgtest -lm -lsubunit -lstdc++ -ftest-coverage -fprofile-arcs
OPEN_CMD = xdg-open

all: clean s21_matrix_oop.a

s21_matrix_oop.a:
	gcc $(CC) -c *.cc
	ar -crs s21_matrix_oop.a *.o

test: clean s21_matrix_oop.a
	gcc $(CC) tests/test.cc s21_matrix_oop.a $(FLAGS) -o test
	./test

gcov_report: clean
	gcc $(CC) tests/test.cc *.cc $(FLAGS) -o test
	./test
	lcov -t "./test"  -o report.info --no-external --ignore-errors mismatch -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcno *gcda *.gco

valgrind: clean s21_matrix_oop.a
	gcc $(CC) tests/test.cc s21_matrix_oop.a $(FLAGS) -o test
	valgrind  --tool=memcheck --track-fds=yes --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

clang-fix:
	cp ../materials/linters/.clang-format .
	clang-format -i *.cc */*.cc

clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cc */*.cc

clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info