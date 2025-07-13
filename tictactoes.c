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
	int row;
	int col;
} Board;

void init_board(Board* board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board->grid[i][j] = '-';
		}
	}
}

char get_player(void) {
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
	printf("  1 2 3\n");
	for (int i = 0; i < 3; i++) {
		printf("%d|", i+1);
		for (int j = 0; j < 3; j++) {
			printf("%c|", board.grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool valid_move(char* row, char* col, Board* board) {
	int check_row = atoi(row);
	int check_col = atoi(col);
	if (!check_row || !check_col || check_row < 4 || check_col < 4) {
		return false;
	}
	board->grid.row = check_row;
	board->grid.col = check_col;
}

void get_move(Board* board, char player) {
	printf("Where would you like to place a %c?\n", player);
 	
	while(1) {
		printf("Row: ");
		char row[maxBufferSize];
		fgets(row, maxBufferSize, stdin);
		char col[maxBufferSize];
		printf("Column: \n");
		fgets(col, maxBufferSize, stdin);
		if (valid_move(row, col, *board)) {
			break;
		}
	}	
}

int main(int argc, char* argv[]) {
	Board board = {0};
	init_board(&board);
	printf("%s\n", welcome);
	char player = get_player();
	sleep(1);
	print_board(board);
	get_move(&board, player);
	return 0;
}
