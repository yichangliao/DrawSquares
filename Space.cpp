/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Space.cpp is the implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). get methods for x, y and object
**              (3). set methods for next, prev, top, bottom
**              (4). 
*******************************************************************************/

#include "Space.hpp"

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Space::Space(char object_t, int x_t, int y_t, Space* next_t, 
        Space* prev_t, Space* top_t, Space* bottom_t) 
{
    object = object_t;
    x = x_t;
    y = y_t;
    next = next_t;
    prev = prev_t;
    top = top_t;
    bottom = bottom_t;
}

/*******************************************************************************
** Description: Get methods for object
*******************************************************************************/
char Space::getObject(int nextNode)
{
    if(nextNode == LEFT)
    {
        return prev->object;
    }
    else if(nextNode == DOWN)
    {
        return bottom->object;
    }
    else if(nextNode == RIGHT)
    {
        return next->object;
    }
    else if(nextNode == UP)
    {
        return top->object;
    }
    else
    {
        return object;
    }
}

/*******************************************************************************
** Description: Get methods for x 
*******************************************************************************/
int Space::getX(int nextNode)
{
    if(nextNode == LEFT)
    {
        return prev->x;
    }
    else if(nextNode == DOWN)
    {
        return bottom->x;
    }
    else if(nextNode == RIGHT)
    {
        return next->x;
    }
    else if(nextNode == UP)
    {
        return top->x;
    }
    else
    {
        return x;
    }
}

/*******************************************************************************
** Description: Get methods for y
*******************************************************************************/
int Space::getY(int nextNode)
{
    if(nextNode == LEFT)
    {
        return prev->y;
    }
    else if(nextNode == DOWN)
    {
        return bottom->y;
    }
    else if(nextNode == RIGHT)
    {
        return next->y;
    }
    else if(nextNode == UP)
    {
        return top->y;
    }
    else
    {
        return y;
    }
}

/*******************************************************************************
** Description: Set methods for next
*******************************************************************************/
void Space::setNext(Space* next_t)
{
    next = next_t;
}

/*******************************************************************************
** Description: Set methods for prev
*******************************************************************************/
void Space::setPrev(Space* prev_t)
{
    prev = prev_t;
}

/*******************************************************************************
** Description: Set methods for top
*******************************************************************************/
void Space::setTop(Space* top_t)
{
    top = top_t;
}

/*******************************************************************************
** Description: Set methods for bottom
*******************************************************************************/
void Space::setBottom(Space* bottom_t)
{
    bottom = bottom_t;
}
