#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

const char* welcome = "Welcome to tictactoe, try your best to win!";
const char* incorrectInput = "\"%s\" isn't an option, please type either X or O\n";
const int maxBufferSize = 80;

typedef struct {
	char grid[3][3];
} Board;

void init_board(Board* board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board->grid[i][j] = '-';
		}
	}
}

char getPlayer(void) {
        printf("Would you like to play as X or O ?\n");
        char player;
	while(1) {

		char buffer[maxBufferSize];
		fgets(buffer, maxBufferSize, stdin);
		player = toupper(buffer[0]);
		if (player == 'X' || player == 'O') {
			break;
		}
		buffer[strlen(buffer) -1] = '\0';
		printf(incorrectInput, buffer);
	}
	sleep(1);
	printf("Great! You will play as %c\n", player);
	return player;
}  

void print_board(Board board) {
	printf("  0 1 2\n");
	for (int i = 0; i < 3; i++) {
		printf("%d|", i);
		for (int j = 0; j < 3; j++) {
			printf("%c|", board.grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void valid_move(char* move, Board board) {
	while(move[0]) {
		printf("%c\n", move[0]);
		move++;
	}	
}

void get_move(Board* board, char player) {
	printf("Please make a move in the format 1 2, where the former is the row and the latter the column\n");
 	char buffer[maxBufferSize];
	fgets(buffer, maxBufferSize, stdin);
	char* move = strtok(buffer, " ");
	valid_move(move, *board);	
}

int main(int argc, char* argv[]) {
	Board board = {0};
	init_board(&board);
	printf("%s\n", welcome);
	char player = getPlayer();
	sleep(1);
	print_board(board);
	get_move(&board, player);
	return 0;
}
