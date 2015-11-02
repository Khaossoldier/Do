C = gcc

CFLAGS = -Wall -Werror -ansi -pedantic

CFLAGS += -D_XOPN_SOURCE=500

CFLAGS += -g

## Cibles principales

all: do

do.o: do.c
	${CC} ${CFLAGS} -c $<

do: do.o
	${CC} ${CFLAGS} -o $@ $^
