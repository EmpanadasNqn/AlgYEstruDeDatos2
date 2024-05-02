CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS-SIN-WERROR = -Wall -Wextra -pedantic -std=c99

SRC = *.c

OBJS = $(SRC:.c=.o)

CNAME = sort #NOMBRE DEL ARCHIVO COMPILADO

all: compilar

objetos:
	gcc $(CFLAGS) -c $(SRC)

objetos-sin-Werror:
	gcc $(CFLAGS-SIN-WERROR) -c $(SRC)

compilar: objetos
	gcc $(CFLAGS) $(OBJS) -o $(CNAME)

compilar-sin-Werror: objetos-sin-Werror
	gcc $(CFLAGS-SIN-WERROR) $(OBJS) -o $(CNAME)

limpiar:
	rm -f $(OBJS) $(CNAME)

.PHONY: limpiar