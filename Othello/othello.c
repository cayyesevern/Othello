#include <stdio.h>
#define size 8

char board[size][size];

void drawboard();       //prototype
void redraw_board();
void place_tile(char, int, int);
void flip(char, char, int row, int col);

int x = 62, o = 62;
int s;

int main() {

	int f, g;
	int player1 = 0, player2 = 0;
	int row, col;
	printf("\n\t\t\t\t OTHELLO\n");
	drawboard();

	printf("\n\tPLAYER 1 (O)\t\t\t\t PLAYER 2 (X)\n\n");
	printf("\t62 tiles\t\t\t\t 62 tiles\n\n");


	for (s = 0; s < 64; s++) {

		if (s % 2 == 0) {
			printf("\n\tPLAYER 1, please enter row and column value: ");
			scanf_s("%d%d", &row, &col);
			printf("\n\n\n");
			place_tile('O', row, col);
			flip('X', 'O', row, col);
			redraw_board();
			o--;
		}

		else {
			printf("\n\tPLAYER 2, please enter row and column value: ");
			scanf_s("%d%d", &row, &col);
			printf("\n\n\n");
			place_tile('X', row, col);
			flip('O', 'X', row, col);
			redraw_board();
			x--;
		}

		printf("\n\tPLAYER 1 (O)= %d tiles left \n\tPLAYER 2 (X)= %d tiles left \n", o, x);
	}



	//Winner
	for (f = 0; f < 8; f++)
		for (g = 0; g < 8; g++)
			if (board[f][g] == 'X')
				player2++;
			else if (board[f][g] == 'O')
				player1++;




	printf("\nPLAYER 1 = %d\n", player1);
	printf("PLAYER 2 = %d\n", player2);
	if (player1 > player2) {
		printf("\nPLAYER 1 IS THE WINNER");
	}
	else if (player1 < player2) {
		printf("\nPLAYER 2 IS THE WINNER");
	}
	else {
		printf("\nDRAW");
	}
}

void drawboard() {

	int mid = size / 2;
	int i, k, p;

	for (i = 0; i < size; i++) {
		for (k = 0; k < size; k++) {
			if ((i == mid) && (k == mid)) {
				board[i][k] = 'X';
			}
			else if ((i == (mid - 1)) && (k == (mid - 1))) {
				board[i][k] = 'X';
			}
			else if ((i == mid) && (k == (mid - 1))) {
				board[i][k] = 'O';
			}
			else if ((i == (mid - 1)) && (k == mid)) {
				board[i][k] = 'O';
			}
			else {
				board[i][k] = '.';
			}
		}
	}

	printf("\n");
	for (p = 0; p < size; p++) {
		printf("\t%d", p);
	}
	printf("\n\n");

	for (i = 0; i < size; i++) {
		printf("   %d", i);
		for (k = 0; k < size; k++) {
			printf("\t%c", board[i][k]);
		}
		printf("\n\n");
	}
	printf("\n  ________________________________________________________________\n\n");
}

void redraw_board() {

	int i, k, p;
	int mid = size / 2;


	printf("\n");
	for (p = 0; p < size; p++) {
		printf("\t%d", p);
	}
	printf("\n\n");

	for (i = 0; i < size; i++) {
		printf("   %d", i);
		for (k = 0; k < size; k++) {
			printf("\t%c", board[i][k]);
		}
		printf("\n\n");
	}
	printf("\n  ________________________________________________________________\n\n");
}

void place_tile(char lip, int row, int col) {



	board[row][col] = lip;


}

void flip(char lip, char tip, int row, int col) {

	int a;
	int* x1 = &x, * o1 = &o, * s1 = &s; // pointers to control the count in the main function
	int i = col - 1, j = col + 1; // loops
	int m = row - 1, k = row + 1;// loops

	int b1 = row - 1, b2 = col - 1, c1 = row - 1, c2 = col + 1, d1 = row + 1, d2 = col - 1, e1 = row + 1, e2 = col + 1;

	int left = 0, right = 0; // save location
	int up = 0, down = 0; // save location
	int topL = 0, topL1 = 0, topR = 0, topR1 = 0; // save location
	int bottomL = 0, bottomL1 = 0, bottomR = 0, bottomR1 = 0; // save location
	int z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0; // count



	//right
	while (j < 8) {
		if (board[row][col + 1] == lip) {
			if (board[row][j] == tip) {
				right = j;
				z1++;
				break;
			}
		}
		j++;
	}


	// left
	while (i >= 0) {
		if (board[row][col - 1] == lip) {
			if (board[row][i] == tip) {
				left = i;
				z2++;
				break;
			}
		}
		i--;
	}


	// up
	while (m >= 0) {
		if (board[row - 1][col] == lip) {
			if (board[m][col] == tip) {
				up = m;
				z3++;
				break;
			}
		}
		m--;
	}


	//down
	while (k < 8) {
		if (board[row + 1][col] == lip) {
			if (board[k][col] == tip) {
				down = k;
				z4++;
				break;
			}
		}
		k++;

	}


	//top left
	while (b1 >= 0, b2 >= 0) {
		if (board[row - 1][col - 1] == lip) {
			if (board[b1][b2] == tip) {
				topL = b1;
				topL1 = b2;
				z5++;
				break;
			}
		}
		b1--;
		b2--;
	}


	// top right
	while (c1 >= 0, c2 < 8) {
		if (board[row - 1][col + 1] == lip) {
			if (board[c1][c2] == tip) {
				topR = c1;
				topR1 = c2;
				z6++;
				break;
			}
		}
		c1--;
		c2++;
	}


	// bottom left	
	while (d1 < 8, d2 >= 0) {
		if (board[row + 1][col - 1] == lip) {
			if (board[d1][d2] == tip) {
				bottomL = d1;
				bottomL1 = d2;
				z7++;
				break;
			}
		}
		d1++;
		d2--;
	}


	//bottom right
	while (e1 < 8, e2 < 8) {
		if (board[row + 1][col + 1] == lip) {
			if (board[e1][e2] == tip) {
				bottomR = e1;
				bottomR1 = e2;
				z8++;
				break;
			}
		}
		e1++;
		e2++;
	}


	// overwrite array

			   //right
	for (j = right - 1; j >= (col + 1); j--) {
		if (z1 != 0) {
			board[row][j] = tip;
		}
		else {
			break;
		}
	}

	//left
	for (i = left + 1; i <= (col - 1); i++) {
		if (z2 != 0) {
			board[row][i] = tip;
		}
		else {
			break;
		}
	}

	//up
	for (m = up + 1; m <= (row - 1); m++) {
		if (z3 != 0) {
			board[m][col] = tip;
		}
		else {
			break;
		}
	}

	//down

	for (k = down - 1; k >= row + 1; k--) {
		if (z4 != 0) {
			board[k][col] = tip;
		}
		else {
			break;
		}
	}

	//top left
	for (b1 = topL + 1, b2 = topL1 + 1; b1 <= row - 1, b2 <= col - 1; b1++, b2++) {
		if (z5 != 0) {
			board[b1][b2] = tip;
		}
		else {
			break;
		}
	}

	// top right 
	for (c1 = topR + 1, c2 = topR1 - 1; c1 <= row - 1, c2 >= col + 1; c1++, c2--) {
		if (z6 != 0) {
			board[c1][c2] = tip;
		}
	}

	//bottom left 
	for (d1 = bottomL - 1, d2 = bottomL1 + 1; d1 >= row + 1, d2 <= col - 1; d1--, d2++) {
		if (z7 != 0) {
			board[d1][d2] = tip;
		}
	}

	//  bottom right
	for (e1 = bottomR - 1, e2 = bottomR1 - 1; e1 >= row + 1, e2 >= col + 1; e1--, e2--) {
		if (z8 != 0) {
			board[e1][e2] = tip;
		}
	}


	//check for illegal move	
	// go back to original
	// check for the reservation on the board
	if (z1 == 0 && z2 == 0 && z3 == 0 && z4 == 0 && z5 == 0 && z6 == 0 && z7 == 0 && z8 == 0) {
		printf("\t\t\tYou have made an illegal move\n");

		board[row][col] = '.';

		if (tip == 'X') {
			x++;
		}
		else if (tip == 'O') {
			o++;
		}
		s--;
	}

}



