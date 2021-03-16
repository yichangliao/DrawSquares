/************************************************************************************
** Author: Yi Chang Liao
** Date: 10/07/2019
** Description: Board.hpp is the board class specification file. The board is built 
**              from dynamic 2D array.
**		It contains:
**		(1). Three private parameters: double pointers to the 2d array, rows
**		     of the array and the columns of the array.
**		(2). A default constructor for the board.
**		(3). A two parameters function to set user assign size board.
**		(4). setBoardMark function to mark white, black or ant location.
**		(5). getBoardMark function to return location's mark.
**		(6). printBoard function to show current board.
**		(7). A deconstructor to free the memory.
*************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
	    char** array;

	    int rows;

	    int columns;

    public:
	    // Default constructor, make double pointer point to nullptr.
	    Board();

	    // Two parameters function, set board to user assign size array.
        void setBoard(int, int);

	    // setBoardMark function to mark character 'space', '#' or '*' on the board.
	    // It takes three parameters: row, column and character.
        void setBoardMark(int, int, char);

	    // getBoardMark function to get location's mark.
        char getBoardMark(int, int);

	    // printBoard function to show current board.
        void printBoard();

	    // Deconstructor to free the memory.
	    ~Board();
};

#endif
