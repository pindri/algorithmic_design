CC = gcc
CFLAGS = -O0 -ggdb -Wall -Wextra -I$(IDIR)
EXE = chain_test.x
BENCHMARK = benchmark.x
D_FLAG = BENCHMARK

SRC = src/main.c src/matrix.c src/chain.c
IDIR = include

all: $(EXE)

benchmark: $(BENCHMARK)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(BENCHMARK): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ -D$(D_FLAG)

.PHONY: clean

clean:
	rm -f *.x *.dat
