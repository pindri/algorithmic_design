CC = gcc
CFlags = -O0 -g -Wall -Wextra
EXE = strassen_test.x

SRC = code/main.c code/matrix.c code/strassen.c code/submatrix.c

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.x *.dat
