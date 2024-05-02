CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS-SIN-WERROR = -Wall -Wextra -pedantic -std=c99

all: sort

main.o: main.c
	gcc $(CFLAGS) -c main.c

pair.o: pair.c
	gcc $(CFLAGS) -c pair.c

sort: main.o pair.o
	gcc $(CFLAGS) *.o -o $@

sort-sin-Werror: main.o pair.o
	gcc $(CFLAGS-SIN-WERROR) *.o -o $@

limpiar:
	rm -f *.o sort

.PHONY: limpiar