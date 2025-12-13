all:
	gcc -Wall --pedantic src/*.c -o bin/gauss 

tests: all
	gcc -Wall --pedantic -Isrc \
	tests.c \
	src/gauss.c src/pivot.c src/backsubst.c src/mat_io.c \
	-o bin/tests

run: all
	bin/gauss dane/A dane/b

test: tests
	bin/tests
