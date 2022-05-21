CC= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -fsanitize=address

LDFLAGS = -fsanitize=address

library: dlist.o
	ar csr libdlist.a dlist.o

clean :
	$(RM) dlist.o libdlist.a
