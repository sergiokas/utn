#Compiler options
CC = gcc
CFLAGS = -Wall -I ./include
COMPILE = $(CC) -c $(CFLAGS)
BUILD = $(CC) $(CFLAGS)

# Directories
SRC = src
BIN = bin

# Libraries
OBJS=random.o singly.o doubly.o stack.o data.o
OUT_OBJS=$(addprefix $(BIN)/,$(OBJS))

# Programs
PROGS=ex-singly ex-doubly ex-stack

all: $(PROGS)

%: $(OUT_OBJS) $(SRC)/%.c
	$(BUILD) -o $(BIN)/$@ $^

$(BIN)/%.o: $(SRC)/%.c
	$(COMPILE) -o $@ $<	

clean:
	@echo "Cleaning up..."
	@rm -vf $(BIN)/*.o
	
kill:
	@rm -vf $(BIN)/*
