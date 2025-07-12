CC = gcc

CFLAGS = -Wall -std=gnu99 -pedantic -Wextra

.DEFAULT_GOAL:= tictactoe

tictactoe: tictactoes.o
	$(CC) $(CFLAGS) $^ -o $@
