/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
Kenneth Zhu 685229773
*/

int SecondPlacePrize(int prize1, int prize2, int prize3)
{


	//Checking which prize meets the condition of being middle. 
	int secondprize;

	if (prize1 == prize2 && prize2 == prize3) {
		secondprize = prize2;
	}
	else if ((prize2 >= prize1 && prize2 <= prize3) || (prize2 >= prize3 && prize2 <= prize1)) {
		secondprize = prize2;
	}
	else if ((prize1 >= prize2 && prize1 <= prize3) || (prize1 >= prize3 && prize1 <= prize2)) {

		secondprize = prize1;

	}
	else {
		secondprize = prize3;
	}

	return secondprize;
}

int FourInARow(int values[], int length)
{
	int i;
	for (i = 0; i < length - 3; i++) {

		if (values[i] == values[i + 1] && values[i + 1] == values[i + 2] && values[i + 2] == values[i + 3]) {
			return i;
		}

	}
	return -1;





}

int BinaryToDecimal(int binary)
{
	int newarray[100] = { 0 };
	int remainder;
	int value = binary / 10;
	remainder = binary % 10;
	newarray[0] = remainder;
	int sum = 0;
	int poweroftwo = 1;
	int j;
	int i = 1;




	//Put all the binary numbers into an array
	while (value != 0) {   

		remainder = value % 10;
		value /= 10;
		newarray[i] = remainder;
		i++;

	}

	//Going through each element in the array and calculating 2^n
	for (j = 0; j < i; j++) { 
		sum += newarray[j] * (poweroftwo);

		poweroftwo *= 2;
	}

	return sum;
}

double MedianAbility(double abilities[], int length)
{
	int i = 0;
	int oddmedianposition;
	int evenmedianposition;
	double storedvalue;
	double median;

	if (length == 1) {

		median = abilities[0];
	}
	else {

		while (i != length - 1) {
			// Checking if the next element to current i is greater than the current element i. 
			if (abilities[i + 1] >= abilities[i]) { 
				i++;

			}
			else {
				storedvalue = abilities[i + 1];
				abilities[i + 1] = abilities[i];
				abilities[i] = storedvalue;

				i = 0;

			}
		}

		//If the length of the array is a odd number ( i.e remainder is not equal to zero), then it is just the middle number. 
		// Otherwise if the length of the array is even number(i.e. remainder is zero), 
		//then it will compute the average. 

		if (length % 2 != 0) {
			oddmedianposition = (length + 1) / 2;
			median = abilities[oddmedianposition - 1];

		}
		else {

			evenmedianposition = length / 2;
			median = (abilities[evenmedianposition - 1] + abilities[evenmedianposition]) / 2;
		}

	}

	return median;
}


//Created a function to help remove a character and shift the whole array.  
void RemoveCharacter(char*name, int index, int elements)  
{
	int i;
	for (i = index; i < elements; i++) {

		name[i] = name[i + 1];
	}



}


void RemoveSpaces(char *name)
{
	int i;
	int elements = strlen(name);
	for (i = 0; i < elements - 1; i++) {
		if (name[i] == 32 && name[i + 1] == 32) {

			RemoveCharacter(name, i, elements);  //calls to the Remove Character function. 
			elements -= 1;
			i = -1;
		}


	}


}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int i;
	int j;
	int piecesloc;

	for (i = 0; i < size; i++) { // going through rows

		for (j = 0; j < size; j++) {
			board[i][j] = 0;

		}


	}

	// If the board is even, then this code performs 4 fixed pieces


	if (size % 2 == 0) {						
		piecesloc = size / 2;
		board[piecesloc][piecesloc] = 3;
		board[piecesloc - 1][piecesloc - 1] = 3;
		board[piecesloc][piecesloc - 1] = 3;
		board[piecesloc - 1][piecesloc] = 3;

	}
	//Otherwise if the board is odd, then perform on 1 fixed pieces.
	else {							 
		piecesloc = size / 2;
		board[piecesloc][piecesloc] = 3;

	}

}



void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{

	int i;

	//For each given direction, it checks to see if there is a token placed at position row, then using the for loop
	//to loop down until it hits the fixed piece. 

	if (side == 'N') {

		for (i = 0; i < size; i++) {
			if (board[0][move] == 1 || board[0][move] == 2) {
				*lastRow = -1;
				*lastCol = -1;
				i = size + 1;

			}
			else if (board[i][move] == 3 || board[i][move] == 2 || board[i][move] == 1) {

				board[i - 1][move] = player;
				*lastRow = i - 1;
				*lastCol = move;
				i = size + 1;
			}
			else if (i == size - 1) {   // If there is no token placed and the loop reaches the edge of the board, then place it there. 
				board[i][move] = player;
				*lastRow = i;
				*lastCol = move;
				i = size + 1;
			}


		}



	}
	else if (side == 'W') {
		for (i = 0; i < size; i++) {
			if (board[move][0] == 1 || board[move][0] == 2) {

				*lastRow = -1;
				*lastCol = -1;
				i = size + 1;
			}
			else if (board[move][i] == 3 || board[move][i] == 2 || board[move][i] == 1) {
				board[move][i - 1] = player;
				*lastRow = move;
				*lastCol = i - 1;
				i = size + 1;
			}
			else if (i == size - 1) {
				board[move][i] = player;
				*lastRow = move;
				*lastCol = i;
				i = size + 1;
			}


		}




	}
	else if (side == 'E') {
		for (i = size - 1; i >= 0; i--) {
			if (board[move][size - 1] == 1 || board[move][size - 1] == 2) {

				*lastRow = -1;
				*lastCol = -1;
				i = -1;
			}
			else if (board[move][i] == 3 || board[move][i] == 2 || board[move][i] == 1) {
				board[move][i + 1] = player;
				*lastRow = move;
				*lastCol = i + 1;
				i = -1;
			}
			else if (i == 0) {
				board[move][i] = player;
				*lastRow = move;
				*lastCol = i;
				i = -1;
			}


		}




	}
	else if (side == 'S') {

		for (i = size - 1; i >= 0; i--) {
			if (board[size - 1][move] == 1 || board[size - 1][move] == 2) {

				*lastRow = -1;
				*lastCol = -1;
				i = -1;
			}
			else if (board[i][move] == 3 || board[i][move] == 2 || board[i][move] == 1) {
				board[i + 1][move] = player;
				*lastRow = i + 1;
				*lastCol = move;
				i = -1;
			}
			else if (i == 0) {
				board[i][move] = player;
				*lastRow = i;
				*lastCol = move;
				i = -1;
			}


		}


	}


}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{


	int count = 0;

	int i;
	int j;

	int full = size * size; // Calculating how many elements in the board in the given size. 

// Checking if the last position  cannot be placed. If it cannot be placed, game must not be over. 
	if (row == -1 && col == -1) {

		return 0;
	}


	// Check through rows and columns to see if there is four in the row. 


	//Check the rows. 
	for (i = 0; i < size - 3; i++) { 

		if (board[i][col] == board[i + 1][col] && board[i + 1][col] == board[i + 2][col] && board[i + 2][col] == board[i + 3][col]) {

			if (board[i][col] == 1 || board[i][col] == 2) {
				return player;
			}

		}

	}
	// Check the columns. 
	for (i = 0; i < size - 3; i++) {


		if (board[row][i] == board[row][i + 1] && board[row][i + 1] == board[row][i + 2] && board[row][i + 2] == board[row][i + 3]) {

			if (board[row][i] == 1 || board[row][i] == 2) {
				return player;
			}

		}

	}

	i = row;
	j = col;

	// Finding the start position of (\)
	while (i > 0 && j > 0) {

		i--;
		j--;
	}

	int cr = i; //check rows, cr
	int cc = j; //check columns, cc
	int count1 = 0; //counts all the players ones
	int count2 = 0; // counts all the players two

	//Looping through the  (\) diagonal and checks if there is four in the row. 
	while ((cc <= size - 1) && (cr <= size - 1)) {

		if (board[cr][cc] == 1) {
			count1++;
			count2 = 0;

		}
		else if (board[cr][cc] == 2) {

			count2++;
			count1 = 0;
		}

		cc++;
		cr++;

	}

	if (count1 == 4) {

		return 1;
	}
	else if (count2 == 4) {
		return 2;
	}


	int k = row; // k is the starting position of row for /
	int l = col; // k is the starting position of column for /
	count1 = 0; //counts all the players ones
	count2 = 0;// counts all players two


	//finding the starting position for the left diagonal array. (/)
	while (k < size - 1 && l>0) {

		k++;
		l--;
	}



	//Check columns and rows from top right corner. 
	cr = k;
	cc = l;

	//Looping through the  (/) diagonal and checks if there is four in the row. 

	while (cr >= 0 && cc <= size - 1) {

		if (board[cr][cc] == 1) {
			count1++;
			count2 = 0;

		}
		else if (board[cr][cc] == 2) {

			count2++;
			count1 = 0;
		}


		cr--;
		cc++;


	}


	if (count1 == 4) {

		return 1;
	}
	else if (count2 == 4) {
		return 2;
	}



	count1 = 0;
	count2 = 0;

	// Checking if the game is not filled up if 4 in any directions cannot be found. 
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {

			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3) {
				count++;
			}
		}
	}

	//If all the board is filled, return the current player playing this game. 

	if (full == count) {

		return player;
	}

	// This script goes around and check the edge of the board to see if it is full
	int sidecount = 0;

	// Looping along the first row
	for (i = 0; i < size; i++) {
		if (board[0][i] == 1 || board[0][i] == 2) {
			sidecount++;


		}

		if (board[size - 1][i] == 1 || board[size - 1][i] == 2) {
			sidecount++;
		}


	}

	int sidefull = (size * 4) - 4;

	//Looping through the right edge of the table. 
	for (i = 1; i <= size - 2; i++) {

		if (board[i][size - 1] == 1 || board[i][size - 1] == 2) {

			sidecount++;

		}

		if (board[i][0] == 1 || board[i][0] == 2) {
			sidecount++;
		}

	}
	

	// If all the edges of the board is full after checking it, then returns the players who placed the last token. 
	if (sidefull == sidecount) {
		return player;
	}

	return 0;
}



void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{


	int totalrow = size + 5;
	char rowcount = 48;
	int elements = 0;


	int i;// rows
	int j; // columns


	// Displaying the first 2 row of the board. 
	for (i = 0; i < 2; i++) {      

		for (j = 0; j < size + 4; j++) {

			if (j < 2 || j == totalrow - 3) {

				boardString[elements] = '-';

			}
			else if (j == totalrow - 2) {
				boardString[elements] = '-';
				elements++;
				boardString[elements] = '\n';

			}
			else if (i == 0 && j > 1 && j < totalrow - 3) {     // Printing the 'Norths'
				boardString[elements] = 'N';


			}
			else if (i == 1 && j > 1 && j < totalrow - 3) {

				boardString[elements] = rowcount;
				rowcount++;


			}


			elements++;

		}

	}

	//Initialise the start of the 0 in character. 
	rowcount = 48;


	//Another for loop for the rest of the tables. 
	for (i = 2; i <= totalrow - 4; i++) {
		for (j = 0; j < size + 4; j++) {

			if (j == 0) {
				boardString[elements] = 'W';
			}
			else if (j == totalrow - 2) {             // If it is the last column, then add an E and a new line

				boardString[elements] = 'E';
				elements++;
				boardString[elements] = '\n';
				rowcount++;
			}
			else if (j == 1 || j == totalrow - 3) {         // if it is in the 2nd column (excuse the index!), then add that number. 
				boardString[elements] = rowcount;


			}
			else if (j > 1 && j < totalrow - 3) {  // if it is in the dot area. 


				if (board[i - 2][j - 2] == 0) {
					boardString[elements] = '.';
				}
				else if (board[i - 2][j - 2] == 1) {
					boardString[elements] = 'X';

				}
				else if (board[i - 2][j - 2] == 2) {
					boardString[elements] = 'O';
				}
				else if (board[i - 2][j - 2] == 3) {

					boardString[elements] = '#';
				}




			}
			elements++;
		}
	}

	rowcount = 48;
	//Printing the last two rows of the column. 
	for (i = totalrow - 3; i < totalrow - 1; i++) {      

		for (j = 0; j < size + 4; j++) {

			if (j < 2 || j == size + 2) {

				boardString[elements] = '-';

			}
			else if (i == totalrow - 2 && j > 1 && j < totalrow - 3) {  //bottom row of the board
				boardString[elements] = 'S';


			}
			else if (i == totalrow - 3 && j > 1 && j < totalrow - 3) {

				boardString[elements] = rowcount;
				rowcount++;


			}
			else if (j == totalrow - 2 && i == totalrow - 3) {

				boardString[elements] = '-';
				elements++;
				boardString[elements] = '\n';

			}
			else if (j == totalrow - 2 && i == totalrow - 2) {

				boardString[elements] = '-';
				elements++;
				boardString[elements] = '\n';
				elements++;
				boardString[elements] = '\0';

			}

			elements++;

		}

	}

}


char Direction(int dirnum) {
	char direction;

	if (dirnum == 0) {
		direction = 'N';
	}
	else if (dirnum == 1) {
		direction = 'E';
	}
	else if (dirnum == 2) {
		direction = 'S';

	}
	else {
		direction = 'W';
	}

	return direction;


}

//Define the moving function so it moves and check if that moves gives the winning move
int MovingFunction(int board[MAX_SIZE][MAX_SIZE], int size, char direction, int player, int *position)
{

	int i;
	int rowPos;
	int colPos;
	int gameOver;



	// Loop through  numbers position depending on the direction posed.
	for (i = 0; i < size; i++) {   

		AddMoveToBoard(board, size, direction, i, player, &rowPos, &colPos);
		gameOver = CheckGameOver(board, size, player, rowPos, colPos);

		if (gameOver == player) {
			*position = i;
			i = size + 1;

			return 1;
		}
		else {

			board[rowPos][colPos] = 0;
			*position = 0; 
		}

	}

	return 0;




}





void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int i;
	int rowPos;
	int colPos;
	int randompos;
	int stop = 0;
	int valid;
	char dir;
	char convertdir;
	int position;




	while (stop == 0) {

		for (i = 0; i < 4; i++) {

			dir = Direction(i);


			//Valid means whether it can make a valid move and win the game
			valid = MovingFunction(board, size, dir, player, &position);


			if (valid == 1) {
				*side = dir;
				*move = position;
				stop = 1;
				i = 5;

			}
		}


		// If no winning move is found, then generate a random move. 
		if (stop == 0) {
			while (stop == 0) {
				dir = rand() % 4;    //dir is the random direction 
				convertdir = Direction(dir);
				randompos = rand() % size;

				AddMoveToBoard(board, size, convertdir, randompos, player, &rowPos, &colPos);

				if (rowPos != -1 && colPos != -1) {
					*side = convertdir;
					*move = randompos;

					stop = 1;


				}


			}
		}



	}

}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int i;
	int rowPos;
	int colPos;
	int randompos;
	int stop = 0;
	int valid;
	char dir;
	char convertdir;
	int position;




	while (stop == 0) {

		for (i = 0; i < 4; i++) {

			dir = Direction(i);


			//Valid means whether it can make a valid move and win the game
			valid = MovingFunction(board, size, dir, player, &position);


			if (valid == 1) {
				*side = dir;
				*move = position;
				stop = 1;
				i = 5;

			}
		}


		// If valid move is found but not the winning move, then generate a random move. 
		if (stop == 0) {
			while (stop == 0) {
				dir = rand() % 4;    //dir is the random direction 
				convertdir = Direction(dir);
				randompos = rand() % size;

				AddMoveToBoard(board, size, convertdir, randompos, player, &rowPos, &colPos);

				*side = convertdir;
				*move = randompos;


				if (rowPos != -1 && colPos != -1) {
					*side = convertdir;
					*move = randompos;

					stop = 1;


				}


			}
		}



	}
}
