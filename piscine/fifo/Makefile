CC= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -fsanitize=address

library: fifo.o
	ar csr libfifo.a fifo.o

clean :
	$(RM) fifo.o libfifo.a
