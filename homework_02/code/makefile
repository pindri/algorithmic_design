CC = gcc
CFLAGS = -O0 -ggdb -Wall -Wextra -I$(IDIR)
EXE = chain_test.x

SRC = src/main.c src/matrix.c src/chain.c
IDIR = include

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.x *.dat
