CC= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -fsanitize=address

all:library


library: vector.o
	ar csr libvector.a vector.o

clean :
	$(RM) vector.o libvector.a
