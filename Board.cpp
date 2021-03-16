/************************************************************************************
** Author: Yi Chang Liao
** Date: 10/07/2019
** Description: Board.cpp is the board class function implementation file. The board 
**              is built from dynamic 2D array.
**              It contains:
**              (1). A default constructor for the board.
**              (2). A two parameters function to set user assign size board.
**              (3). setBoardMark function that takes three parameters to mark white
**                   ,black or current ant location.
**              (4). printBoard function to show current board.
**              (5). A deconstructor to free the memory.
*************************************************************************************/

#include "Board.hpp"
#include <iostream>

/*************************************************************************************
** Description: Default constructor
*************************************************************************************/
Board::Board()
{
    array = nullptr; 
}

/*************************************************************************************
** Description: Two parameters function, set board to user assign size array, and
**              mark whole board to white.
*************************************************************************************/
void Board::setBoard(int assignRows, int assignColumns)
{
    rows = assignRows;
    columns = assignColumns;
    
    // Dynamic 2d array
    array = new char* [rows];

    for (int i=0; i<rows; i++)
    {
        array[i] = new char [columns];
   
    }
    
    // Make whole board white
    for (int i=0; i<rows; i++)
    {   
        for (int j=0; j<columns; j++)
        {
            array[i][j]= ' ';
        }
    }   
}

/*************************************************************************************
** Description: setBoardMark function that takes three parameters(row, column and 
**              character of 'space', '#' or '*') to mark on the board.
*************************************************************************************/
void Board::setBoardMark(int markRow, int markColumn, char mark)
{
    array[markRow][markColumn]=mark;
}

/*************************************************************************************
** Description: getBoardMark function that takes two parameters(row and column) to
**              return location's mark.
*************************************************************************************/
char Board::getBoardMark(int markRow, int markColumn)
{
    return array[markRow][markColumn];
}

/*************************************************************************************
** Description: printBoard function to show current board and border
*************************************************************************************/
void Board::printBoard()
{
    // print top border
    for (int i=0; i<(columns+2); i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int i=0; i<rows; i++)
    {
        std::cout << "|"; // left border

        for (int j=0; j<columns; j++)
        {
	        std::cout << array[i][j];
        }

        std::cout << "|" << std::endl; // right border + next line
    }

    // print bottom border
    for (int i=0; i<(columns+2); i++)
    {
         std::cout << "-";
    }
    std::cout << std::endl;
}

/*************************************************************************************
** Description: Deconstructor to free the memory
*************************************************************************************/
Board::~Board()
{
    for (int i=0; i<rows; i++)
    {
        delete [] array[i];
    }
    delete [] array;

    array = nullptr;
}

