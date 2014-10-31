#Compiler options
CC=gcc
CFLAGS=-g -Wall -I ./include
LDFLAGS=-lncurses
COMPILE=$(CC) -c $(CFLAGS)
BUILD=$(CC) $(CFLAGS)

# Libraries
OBJS=main.o tablero.o

# Programs
EXE=main

all: main

run: main
	./$(EXE)

main: $(OBJS)
	gcc -g -Wall -o $(EXE) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(COMPILE) -o $@ $<

clean:
	@echo "Cleaning up..."
  #@rm -vf $(BIN)/*.o
