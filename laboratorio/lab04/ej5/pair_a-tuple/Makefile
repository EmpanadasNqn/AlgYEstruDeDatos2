CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS-SIN-WERROR = -Wall -Wextra -pedantic -std=c99

CNAME = swap

all: compilar

main.o: main.c
	gcc $(CFLAGS) -c main.c

pair.o: pair.c
	gcc $(CFLAGS) -c pair.c

compilar: main.o pair.o
	gcc $(CFLAGS) *.o -o $(CNAME)

compilar-sin-Werror: main.o pair.o
	gcc $(CFLAGS-SIN-WERROR) *.o -o $(CNAME)

limpiar:
	rm -f *.o $(CNAME)

.PHONY: limpiar
