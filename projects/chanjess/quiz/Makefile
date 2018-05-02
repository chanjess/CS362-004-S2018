CFLAGS = -Wall -fpic -coverage -lm

all: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

clean:
	-rm -f *.gcda *.gcno testme