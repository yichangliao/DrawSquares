/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Eraser.hpp is the Eraser object implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/
#include "Eraser.hpp"
#include <iostream>

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Eraser::Eraser(int x_t, int y_t): Space('/', x_t, y_t)
{
}

/*******************************************************************************
** Description: function for object to interact
*******************************************************************************/
void Eraser::interact()
{
    std::cout<<"minus 1 point of ink"<<std::endl;
}
