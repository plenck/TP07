
DIRSDL = /usr/local

CFLAGS=-g -Wall -Wextra  -I$(DIRSDL)/include -I$(DIRSDL)/lib
LDFLAGS=-lSDL -lSDLmain -lSDL_draw	-lm
CC = gcc

EXEC = td7

.PHONY : clean mrproper

all : $(EXEC)

td7: fonctions.o td7.o
	$(CC) -o $@ $^  $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean :
	-rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
