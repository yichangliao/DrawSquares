/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Draw.cpp is the Draw object implementation file
**              It contains:
**              (1).
**              (2). 
**              (3). 
*******************************************************************************/
#include "Draw.hpp"
#include <iostream>

/*******************************************************************************
** Description: Help function to add line by assign direction.
*******************************************************************************/
void Draw::addLine(int direct)
{
    if(direct == LEFT)
    {
        Line temp= drawing.back();
        int x_t=temp.getX();
        int y_t=temp.getY();

        Line line(x_t-1,y_t);
        drawing.push_back(line);
    }
    else if(direct == RIGHT)
    {
        Line temp= drawing.back();
        int x_t=temp.getX();
        int y_t=temp.getY();

        Line line(x_t+1,y_t);
        drawing.push_back(line);
    }
    else if(direct == UP)
    {
        Line temp= drawing.back();
        int x_t=temp.getX();
        int y_t=temp.getY();

        Line line(x_t,y_t-1);
        drawing.push_back(line);
    }
    else if(direct == DOWN)
    {
        Line temp= drawing.back();
        int x_t=temp.getX();
        int y_t=temp.getY();
    
        Line line(x_t,y_t+1);
        drawing.push_back(line);
    }
}


/*******************************************************************************
** Description: Help function to check direction, if same direction return 1,
**              opposite direction return -1, else turn 0.
*******************************************************************************/
int Draw::checkTurn(int direct)
{
    if(direct == LEFT)
    {
        if(pDirect == direct)
        {
            return 1;
        }
        else if(pDirect == RIGHT)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if(direct == RIGHT)
    {
        if(pDirect == direct)
        {
            return 1;
        }
        else if(pDirect == LEFT)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if(direct == UP)
    {
        if(pDirect == direct)
        {
            return 1;
        }
        else if(pDirect == DOWN) 
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if(direct == DOWN)
    {
        if(pDirect == direct)
        {
            return 1;
        }
        else if(pDirect == UP)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

/*******************************************************************************
** Description: Help function to clean previous line, and start a new square
*******************************************************************************/
void Draw::drawClean()
{
    itr1 = drawing.begin();
    itr2 = drawing.end();
    std::advance(itr2, -1); // Move to the one before the last

    // delete whole list except the last one
    drawing.erase(itr1, itr2);

    // reset whole counting
    side=1; 
    firstL=1;
    secondL=1;
    currentL=1;
    pDirect=0;
    direct1=0;
    direct2=0;
}

/*******************************************************************************
** Description: default constructor.
*******************************************************************************/
Draw::Draw()
{
    side=1; // Begin at first side
    firstL=1;
    secondL=1;
    currentL=1;
    pDirect=0;
    direct1=0;
    direct2=0;

    Line line(41,20);
    // Game begin at location(41,20)
    drawing.push_back(line);
}

/*******************************************************************************
** Description: function to drawline by one parameter: direction.
*******************************************************************************/
int Draw::drawLine(int direct)
{
    if(side==1) // Draw first side of square
    {
        if(direct1==0)
        {
            direct1=pDirect=direct;
            firstL++;
            addLine(direct); // Add new line to drawing
            return 0;
        }
        else
        {
            if(checkTurn(direct)==1) // same direction
            {
                firstL++;
                addLine(direct);
                return 0;
            }
            else if(!checkTurn(direct)) // Move to the second side
            {
                side++;
                pDirect = direct2 = direct;
                secondL++;
                addLine(direct);
                return 0;
            }
            else if(checkTurn(direct)==-1) // opposite: clean and restart
            {
                addLine(direct);
                drawClean();
                return 0;
            }
        }
    }
    else if(side==2) // Draw second side of square
    {
        if(checkTurn(direct)==1) // same direction
        {
            secondL++;
            addLine(direct);
            return 0;
        }
        else if(direct == direct1) // same as first side's direction: clean 
        {
            addLine(direct);
            drawClean();
            return 0;
        }
        else if(checkTurn(direct)==-1) // opposite direction:clean
        {
            addLine(direct);
            drawClean();
            return 0;
        }
        else 
        {
            if(secondL >= firstL) // Move to the third side
            {
                side++;
                pDirect = direct;
                currentL++;
                addLine(direct);
                return 0;
            }
            else // clean and restart
            {
                addLine(direct);
                drawClean();
                return 0;
            }
        }
    }
    else if(side==3) // Draw third side of square
    {
        if(checkTurn(direct)==1) // same direction
        {
            currentL++;
            addLine(direct);

            if(currentL > secondL) // clean and restart
            {
                drawClean();
                return 0;
            }
            else
            {
                return 0;
            }
        }
        else if(direct == direct1) // same as first side's direction: clean 
        {
            addLine(direct);
            drawClean();
            return 0;
        }
        else if(direct == direct2) // same as second side's direction: clean 
        {
            addLine(direct);
            drawClean();
            return 0;
        }
        else 
        {
            if(currentL != secondL) // clean and restart
            {
                addLine(direct);
                drawClean();
                return 0;
            }            
            else // move to the fourth side
            {
                side++;
                pDirect = direct;
                currentL=2; // recount for fourth side
                addLine(direct);

                if(secondL==2) // check if complete the square
                {
                    drawClean();
                    return 4;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    else if(side==4) // Draw fourth side of square
    {
        if(checkTurn(direct)==1) // same direction
        {
            currentL++;
            addLine(direct);
            
            // check if the square complete
            if(currentL == secondL && firstL == secondL) 
            {
                int score = secondL*secondL;
                drawClean();
                return score;
            }
            else
            {
                return 0;
            }
        }
        else if(direct == direct1) // same as first side's direction 
        {
            side++;
            firstL++;
            addLine(direct);
            pDirect = direct1;

            if(currentL != secondL) // clean and restart
            {
                drawClean();
                return 0;
            }
            else // check if complete the square
            {
                if(firstL == secondL) // Complete the square
                {
                    int score= secondL*secondL;
                    drawClean();
                    return score;
                }
                else // move to final round for the last side check
                {
                    return 0;
                }
            }
        }
        else if(direct == direct2) // same as second side's direction: clean 
        {
            addLine(direct);
            drawClean();
            return 0;
        }
        else // clean and restart
        {
            addLine(direct);
            drawClean();
            return 0;
        }
    }
    else //last side check
    {
        if(checkTurn(direct)==1) // same direction
        {
            firstL++;
            addLine(direct);

            if(firstL == secondL) // check if complete the square
            {
                int score = secondL*secondL;
                drawClean();
                return score;
            }
            else
            {
                return 0;
            }
        }
        else // clean and restart
        {
            addLine(direct);
            drawClean();
            return 0;
        }
    }
}

/*******************************************************************************
** Description: function to getLocation
*******************************************************************************/
void Draw::getLocation(int* location)
{
    
    std::list<Line>::iterator it;
    it = drawing.end();
    --it;

    location[0] = it->getX();
    location[1] = it->getY();
}

/*******************************************************************************
** Description: function to return the draw
*******************************************************************************/
std::list<Line> Draw::showLine()
{
    return drawing;
}

