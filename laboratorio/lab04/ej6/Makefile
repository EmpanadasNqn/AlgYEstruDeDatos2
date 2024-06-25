CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS-SIN-WERROR = -Wall -Wextra -pedantic -std=c99

CNAME = contador

all: compilar

main.o: main.c
	gcc $(CFLAGS) -c main.c

counter.o: counter.c
	gcc $(CFLAGS) -c counter.c

compilar: main.o counter.o
	gcc $(CFLAGS) *.o -o $(CNAME)

limpiar:
	rm -f *.o $(CNAME)

.PHONY: limpiar
