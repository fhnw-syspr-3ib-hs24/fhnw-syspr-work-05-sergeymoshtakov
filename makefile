CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: my_fork

my_copy: my_fork.c

clean:
	rm -f my_fork
