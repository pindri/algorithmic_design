CC = gcc
CFLAGS = -O0 -ggdb -Wall -Wextra
EXE = chain_test.x

SRC = code/main.c code/matrix.c code/chain.c

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.x *.dat
