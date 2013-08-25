# Maze makefile

CC=gcc
CFLAGS=-Wall -c
LFLAGS=-Wall
OUTPUT=maze

all: build
	

run: build
	./$(OUTPUT)

build:
	$(CC) $(CFLAGS) -o camino.o camino.c
	$(CC) $(CFLAGS) -o solucion.o solucion.c
	$(CC) $(CFLAGS) -o main.o main.c
	$(CC) $(LFLAGS) -o $(OUTPUT) camino.o solucion.o main.o

clean:
	rm *.o
	rm $(OUTPUT)
