/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/10/2019
** Description: Game.hpp is the Game class header file.
**              It contains:
**              (1). private parametes to record data for game 
**              (2). 
**                  
**              (3). 
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Menu.hpp"
#include "Board.hpp"
#include "Draw.hpp"
#include "Eraser.hpp"
#include "Line.hpp"
#include "Pop.hpp"
#include "Refill.hpp"
#include "Space.hpp"
#include "getInteger.hpp"
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <memory>

enum ObjectList{ERASER=1, REFILL, POP};

class Game
{   
    private:
        int ink, findObject, score, location[2]; // record purpose

        Draw draw;

        std::vector<char> pocket; // container hold player's object 

        std::vector<std::unique_ptr<Space>> container; 
        // hold objects on the board 

        Menu control; // display game control and get user input
        
        // help function to create an array of non repeat random number
        // from zero to (input number-1)
        std::vector<int> randArray(int);

        // help function to create objects on the board
        void startObject();

        // help function to search space object
        int searchObject(int*);

        // help function to check edge
        bool checkEdge(int*);

        // help function to check if square complete. If complete get extra ink
        int checkSquare(int);

        
    public:
        Game(); // default constructor
        ~Game(); // destructor
        
        bool checkInk(); // function to check ink level

        int checkSpace(int); // check provided location surronding 
        
        int drawSquare(); // begin draw square
};

#endif

