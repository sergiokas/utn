#Compiler options
CC=gcc
CFLAGS=-Wall -I ./include
COMPILE=$(CC) -c $(CFLAGS)
BUILD=$(CC) $(CFLAGS)

# Directories
SRC=src
BIN=bin

# Libraries
OBJS=random.o singly.o doubly.o stack.o data.o
OUT_OBJS=$(addprefix $(BIN)/,$(OBJS))

# Programs
PROGS=ex-singly ex-doubly ex-stack

all: $(PROGS)

bin:	
	if [ ! -d $(BIN) ]; then mkdir $(BIN); fi

%: $(OUT_OBJS) $(SRC)/%.c
	$(BUILD) -o $(BIN)/$@ $^

$(BIN)/%.o: $(SRC)/%.c bin
	$(COMPILE) -o $@ $<	

clean:
	@echo "Cleaning up..."
	@rm -vf $(BIN)/*.o
	
kill:
	@rm -vf $(BIN)/*
