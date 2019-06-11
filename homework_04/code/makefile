CC = gcc
CFLAGS = -O0 -ggdb -std=c11 -I$(IDIR)
EXE = main.x
BENCHMARK = benchmark.x
D_FLAG = BENCHMARK

SRC = $(wildcard src/*.c)
IDIR = include

all: $(EXE)

benchmark: $(BENCHMARK)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(BENCHMARK): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ -D$(D_FLAG)

.PHONY: clean

clean:
	rm -f *.x *.out *.dat
