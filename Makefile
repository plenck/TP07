DIRSDL = /home/kocevt/Documents/tdinfo/local

CFLAGS=-g -Wall -Wextra -Iinclude/ -Isrc/
LDFLAGS=-lSDL -lSDLmain -lSDL_draw	-lm
CC = gcc

EXEC = td7 exemple
#SRC =$(wildcard src/*c)
SRC = src/fonctions.c src/td7.c
OBJ = $(SRC:.c=.o)
TARGETDIR = bin/
.PHONY : clean mrproper

objex =

COM_COLOR = \033[0;34m
OBJ_COLOR = \033[0;36m
OK_COLOR  = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
NO_COLOR = \033[m
#dont forget to add -e

all : $(EXEC)

td7: $(OBJ)
	@echo
	@echo "$(OBJ_COLOR)===TD07 EDITION DES LIENS===$(NO_COLOR)"
	@echo "$(WARN_COLOR)$(OBJ)$(NO_COLOR)"
	$(CC) -o $(TARGETDIR)$@ $^  $(LDFLAGS)

exemple : $(patsubst %.c,%.o,src/fonctions.c src/exemple.c)
	@echo
	@echo "$(OBJ_COLOR)===exemple EDITION DES LIENS===$(NO_COLOR)"
	@echo "$(WARN_COLOR)$^$(NO_COLOR)"
	$(CC) -o bin/$@ $^ $(LDFLAGS)

%.o: src/%.c
	$(CC) -c $< $(CFLAGS)

clean :
	-rm -rf src/*.o

mrproper: clean
	rm -rf bin/td7 bin/exemple
