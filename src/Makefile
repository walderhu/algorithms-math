CC = gcc
OS = $(shell uname -o)
FLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
ALL_TESTS = $(wildcard ../tests/s21_math/*.c)

ifeq ($(OS), GNU/Linux)
	TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TEST_FLAGS = -lcheck -lm -lpthread -lrt
endif

all: s21_math.a

clean:
	@rm -rf *.gcda *.gcno *.o *.info *.a report tests gcov

test: s21_math.a
	@$(CC) $(FLAGS) $(ALL_TESTS) ../tests/tests.c --coverage s21_math.a $(TEST_FLAGS) -o tests 
	./tests

s21_math.a:
	$(CC) $(FLAGS) -c funcs/*.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

s21_math.a_gcov:
	$(CC) $(FLAGS) $(GCOV_FLAGS) -c funcs/*.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

gcov_report: s21_math.a_gcov test
	mkdir gcov
	mv s21_*.gcda ./gcov
	mv s21_*.gcno ./gcov
	lcov -t "s21_math" -o s21_math.info -c -d ./gcov/.
	genhtml -o report ./s21_math.info
	rm -fr ./gcov 
	rm *.o *.gcno *.gcda tests

check:
	clang-format --style=Google -n *.h ./funcs/*.c
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ./funcs/*.c *.h

leaks:
	leaks -atExit -- ./tests

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h *.c ./funcs/*.c

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov