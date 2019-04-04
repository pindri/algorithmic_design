CC = gcc
CFLAGS = -O0 -ggdb -std=c11 -I$(IDIR)
EXE = main.x

SRC = src/main.c src/sort.c src/asvector_methods.c src/utilities.c src/heapify.c src/cptimer.c
IDIR = include

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.x *.out *.dat
