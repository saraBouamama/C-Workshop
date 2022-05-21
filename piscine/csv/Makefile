CC=gcc
CFLAGS= -Wall -Wextra -Werror -std=c99 -pedantic -D_DEFAULT_SOURCE
OBJS= csv.o

all:csv

csv: csv.o
	$(CC) $(CFLAGS) -o csv csv.o

clean:
	$(RM) csv.o csv
