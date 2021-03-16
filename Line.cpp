/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Line.hpp is the Line object implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/
#include "Line.hpp"
#include <iostream>

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Line::Line(int x_t, int y_t): Space('+', x_t, y_t)
{
}

/*******************************************************************************
** Description: function for object to interact
*******************************************************************************/
void Line::interact()
{
    std::cout<<"drawing"<<std::endl;
}
