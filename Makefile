DIRSDL = /home/kocevt/Documents/tdinfo/local

CFLAGS=-g -Wall -Wextra -Iinclude/
LDFLAGS=-lSDL -lSDLmain -lSDL_draw	-lm
CC = gcc

EXEC = td7
SRC =$(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

.PHONY : clean mrproper

all : $(EXEC)

td7: $(OBJ)
	$(CC) -o $@ $^  $(LDFLAGS)

%.o: src/%.c
	$(CC) -c $< $(CFLAGS)

clean :
	-rm -rf src/*.o

mrproper: clean
	rm -rf bin/$(EXEC)
