#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

const char* welcome = "Welcome to tictactoe, try your best to win!";
const char* incorrectInput = "\"%s\" isn't an option, please type either X or O\n";
const char* invalidMove = "Sorry that is not a valid move\n";
const char* takenSpace = "Whoops that spot is taken\n";

const int maxBufferSize = 80;

typedef struct {
	char grid[3][3];
	char player;
} Board;

typedef struct {
	int row;
	int col;
} Move;

void init_board(Board* board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board->grid[i][j] = '-';
		}
	}
}

void get_player(Board* board) {
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
	board->player = player;
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

void update_board(Board* board, int row, int col, char piece) {
	board->grid[row-1][col-1] = piece;
}

bool valid_move(char* row, char* col, Board* board) {
	int check_row = atoi(row);
	int check_col = atoi(col);
	if (!check_row || !check_col || check_row > 3  || check_col > 3) {
		fprintf(stderr, "%s", invalidMove);
		return false;
	}
	if (board->grid[check_row][check_col] != '-') {
		fprintf(stderr, "%s", takenSpace);
		return false;
	}
	update_board(board, check_row, check_col, board->player);
	return true;
}

void get_move(Board* board) {
	printf("Where would you like to place a %c?\n", board->player);
 	
	while(1) {
		printf("Row: ");
		char row[maxBufferSize];
		fgets(row, maxBufferSize, stdin);
		char col[maxBufferSize];
		printf("Column: ");
		fgets(col, maxBufferSize, stdin);
		if (valid_move(row, col, board)) {
			break;
		}
	}	
}

Move get_random() {
	Move random = {0};
	random.row =  rand() % 3;
	random.col = rand() % 3;

void computer_move(Board* board) {
	in	
}

char game_finished(Board board) {
	// Check Rows
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			char previous = board.grid[i][j];
		}
		for (int j = 0; j < 3; j++) {
			if (board.grid[i][j] != previous || board.grid[i][j] == '-') {
			 	break;
			}
		}
		return previous;
	}
	
	// Check Cols
	for (int j = 0; j < 3; j++) {
		if (j == 0) {
			char previous = board.grid[i][j];
		}
		for (int i = 0; i < 3; i++) {
			if (board.grid[i][j] != previous || board.grid[i][j] == '-') {
				break;
			}
		}
		return previous;
	}
	
	// Check diagonals
	if (board.grid[0][0] == board.grid[1][1] && board.grid[0][0] == board.grid[2][2]
		&& board.grid[0][0] != '-') {
		return board.grid[0][0];
	}
	if (board.grid[0][2] == board.grid[1][1] || board.grid[0][2] == board.grid[2][0] 
		&& board.grid[0][2] != '-') {
		return board.grid[0][2];
	}			
			
	return 'z';
}

int main(int argc, char* argv[]) {
	Board board = {0};
	init_board(&board);
	printf("%s\n", welcome);
	get_player(&board);
	sleep(1);
	while(!game_finished(board)){
		print_board(board);
		get_move(&board);
		
	}
	return 0;
}
