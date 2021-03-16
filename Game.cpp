/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/10/2019
** Description: Game.cpp is the Game class implementation file.
**              (1). private parametes to record data for game 
**              (2). 
**                  
**              (3). 
*******************************************************************************/

#include <iostream>
#include "Game.hpp"
#include <algorithm>

/*******************************************************************************
** Description: help function to to create an array of non repeat random number
**              from zero to (input number-1)
*******************************************************************************/
std::vector<int> Game::randArray(int max)
{
    std::vector<int> temp(max);
    
    for(int i=0; i<max; i++)
    {
        temp[i] = i;    
    }

    std::random_shuffle(temp.begin(), temp.end());

    return temp;
}

/*******************************************************************************
** Description: help function to create objects on the board
*******************************************************************************/
void Game::startObject()
{
    std::vector<int> x,y; // create 40 locations on the boards
    x = randArray(82); // x range is 0-81
    y = randArray(40); // y range is 0-39

    for(int i=0; i<15; i++) // create 15 ERASER on the boards
    {
        std::unique_ptr<Eraser> e(new Eraser(x[i],y[i]));
        container.push_back(std::move(e));
    }

    for(int i=15; i<30; i++) // create 15 REFILL on the boards
    {
        std::unique_ptr<Refill> r(new Refill(x[i],y[i]));
        container.push_back(std::move(r));
    }

    for(int i=30; i<40; i++) // create 10 POP on the boards
    {
        std::unique_ptr<Pop> p(new Pop(x[i],y[i]));
        container.push_back(std::move(p));
    }

}

/*******************************************************************************
** Description: help function to search space object
*******************************************************************************/
int Game::searchObject(int* loc)
{
    for(int i=0; i<container.size(); i++) // search container object
    {
        char mark;
        int x=loc[0];
        int y=loc[1];

        mark = container[i]->getObject();
        int xx = container[i]->getX();
        int yy = container[i]->getY();

        if(xx==x && yy==y)
        {
            if(mark == '/')
            { 
                findObject = i;
                return ERASER;
            }
            else if(mark == '@')
            {
                findObject = i;
                return REFILL;
            }
            else if(mark == '?')
            {
                findObject = i;
                return POP;
            }
        }
    }

    return 0;
}

/*******************************************************************************
** Description: Help function to check edge.
*******************************************************************************/
bool Game::checkEdge(int* loc)
{
    int x=loc[0];
    int y=loc[1];

    // If move out of board, return false
    if ( x < 0 || x > 81 || y < 0 || y > 39 )
    {
        return false;
    }
    else
    {
	    return true;
    }
}


/*******************************************************************************
** Description: help function to check if square complete. if complete get extra
**              ink.
*******************************************************************************/
int Game::checkSquare(int getScore)
{
    if(getScore > 0)
    {
        ink += getScore;
    }

    return getScore;
}

/*******************************************************************************
** Description: Default constructor
*******************************************************************************/
Game::Game()
{
    score = findObject = location[0] = location[1] = 0;
    ink = 20;

    // Create control menu
    control.setMenu(6);
    std::string option[6];
    option[0] = "0: Quit";
    option[1] = "1: Left";
    option[2] = "2: Down";
    option[3] = "3: Right";
    option[4] = "4: Use Pocket's Items";
    option[5] = "5: Up";
    control.addOption(option, 6);

    

}

/*******************************************************************************
** Description: destructor
*******************************************************************************/
Game::~Game()
{
    container.clear();
}

/*******************************************************************************
** Description: function to check ink level.
*******************************************************************************/
bool Game::checkInk()
{
    if(ink > 0)
    {
        return true;
    }

    return false;
}


/*******************************************************************************
** Description: check provided location and provided next line space. 
**              return 0 if next space is empty.
*******************************************************************************/
int Game::checkSpace(int direct)
{
    if(direct == UP)
    {
        draw.getLocation(location);
        location[1]--; // move up
        
        return searchObject(location);
    }
    else if(direct == DOWN)
    {
        draw.getLocation(location);
        location[1]++; // move down
        
        return searchObject(location);
    }
    else if(direct == LEFT)
    {
        draw.getLocation(location);
        location[0]--; // move left
        
        return searchObject(location);
    }
    else if(direct == RIGHT)
    {
        draw.getLocation(location);
        location[0]++; // move right
        
        return searchObject(location);
    }
}

/*******************************************************************************
** Description: begin draw square 
*******************************************************************************/
int Game::drawSquare()
{
    std::cout<<"Draw Square Game Start!"<<std::endl;
    std::cout<<"Press 6 start"<<std::endl;
    
    int input = getInteger();
    while(input != 6)
    {
        std::cout<<"Press 6 start"<<std::endl;
        input = getInteger();
    }
    std::cout<<"\033[2J\033[1;1H";

    startObject(); // Create objects on the board

    while(input)
    {
        if(input == UP || input == DOWN || input == LEFT || input == RIGHT)
        {
            if(!checkSpace(input)) // if surronding is empty
            {
                if(!checkEdge(location)) // if new location out of edge
                {
                    std::cout<<"Can't draw this line, try again!"<<std::endl;
                    control.showMenu();
                    input = control.getUserOption();
                }
                else // draw line to the empty space
                {
                    ink--;
                    score += checkSquare(draw.drawLine(input));
                }
            }
            else if(checkSpace(input) == 1) // if hit eraser
            {
                ink--; 
                ink--;
                score += checkSquare(draw.drawLine(input));
                container.erase(container.begin()+findObject);
            }
            else if(checkSpace(input) == 2) // if hit refill
            {
                ink+=3; 
                score += checkSquare(draw.drawLine(input));
                container.erase(container.begin()+findObject);
            }
            else if(checkSpace(input) == 3) // if hit pop
            {
                ink--; 
                score += checkSquare(draw.drawLine(input));
                
                if(pocket.size()<3) 
                {
                    container.erase(container.begin()+findObject);
                    char question = '?';
                    pocket.push_back(question);
                }
            }
        }
        else if(input == 4)// Use Pop object, regenerate the container
        {
                     
            if(pocket.size()>0)
            {
                container.clear();
                startObject();
                pocket.pop_back();
            }
            else
            {
                std::cout<<"no object in your pocket!"<<std::endl;
            }
        }
        
        std::list<Line> trace; // hold drawing object
        std::list<Line>::iterator it;
        trace = draw.showLine();

        Board b; // create board
        b.setBoard(40,82);

        // draw line on board
        for(it = trace.begin();it != trace.end(); it++)
        {
            char mark;
            int x;
            int y;

            mark = it->getObject();
            x = it->getX();
            y = it->getY();
            
            b.setBoardMark(y,x,mark);
        }

        // draw object on board
        for(int i =0; i<container.size(); i++)
        {
            char mark;
            int x;
            int y;

            mark = container[i]->getObject();
            x = container[i]->getX();
            y = container[i]->getY();
            
            b.setBoardMark(y,x,mark);
        }

        // print board
        b.printBoard();
        
        std::cout<<"Score: "<<score<<"   Ink level: "<<ink<<"    Object: ";
        for(int i=0; i<pocket.size(); i++)
        {
            std::cout<<"? ";
        }
        std::cout<< std::endl;
        
        if(checkInk())
        {
            control.showMenu();
            input=control.getUserOption();
            std::cout<<"\033[2J\033[1;1H";
        }
        else
        {
            std::cout<<"\033[2J\033[1;1H";
            std::cout<<"Your Score is: "<<score<<std::endl;
            input = 0;    
        }
    }
}
