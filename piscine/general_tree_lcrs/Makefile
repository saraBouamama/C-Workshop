CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99 -pedantic

TARGET_LIB=libgtree.a

OBJS= gtree.o print.o serialize.o

all:library

library: $(OBJS)
	ar csr $(TARGET_LIB) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET_LIB)
