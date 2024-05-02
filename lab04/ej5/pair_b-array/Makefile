CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

CNAME = sort

SRC = *.c
OBJS = $(SRC:.c=.o)

all: compilar

objetos:
	gcc $(CFLAGS) -c $(SRC)

compilar: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(CNAME)

limpiar:
	rm -f $(OBJS) $(CNAME)

.PHONY: limpiar