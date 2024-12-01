# Fully posix complaint makefile

.POSIX:

CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O2

OBJ = src/dynarray.o src/linkedlist.o src/stack.o

all: libds.a

libds.a: $(OBJ)
	$(AR) -rcs $@ $?

.c.o:
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm -f src/*.o libds.a

.PHONY: all clean
