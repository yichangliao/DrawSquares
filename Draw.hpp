/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Draw.hpp is the Draw object header file
**              It contains:
**              (1). 
**              (2).
**              (3). 
*******************************************************************************/

#ifndef DRAW_HPP
#define DRAW_HPP
#include <list> 
#include "Line.hpp"

class Draw 
{
    private:
        // Linked list for record drawing the square
        std::list<Line> drawing;
        std::list<Line>::iterator itr1, itr2;

        // Record which side of square(first, second, third, last)
        int side;

        // Record first and second sides of square, since drawing first and 
        // second sides are the key to make a square
        int firstL;
        int secondL;
        int currentL;

        // Record previous direction and first, second direction
        int pDirect;
        int direct1;
        int direct2;
 
        // Help function to add line by assign direction
        void addLine(int);

        // Help function to check direction, if same direction return 1, 
        // opposite direction return -1, else return 0.
        int checkTurn(int);

        // Help function to clean previous line, and start a new square
        void drawClean();

    public:
        // default constructor
        Draw(); 
 
        // function to drawline by one parameter: direction
        // return 0 if square is not complete
        // return scores if square is complete 
        int drawLine(int);

        // function to get location
        void getLocation(int*);
        
        // function to return the draw
        std::list<Line> showLine();
};

#endif
