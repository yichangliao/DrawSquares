/*******************************************************************************
** Program name: Draw Square Game 
** Author: Yi Chang Liao
** Date: 12/10/2019
** Description: 
**              (1). 
**              (2).
**              (3).
** Constraint:  
*******************************************************************************/

#include "Game.hpp"
#include "Space.hpp"
#include "Line.hpp"
#include "Eraser.hpp"
#include "Refill.hpp"
#include "Pop.hpp"
#include "Blow.hpp"
#include "Board.hpp"
#include "Draw.hpp"
#include "getInteger.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    srand(time(0));

    Game game;

    game.drawSquare();
 }
