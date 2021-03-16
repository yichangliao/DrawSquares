/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Blow.hpp is the Blow object implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/
#include "Blow.hpp"
#include <iostream>

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Blow::Blow(int x_t, int y_t): Space('~', x_t, y_t)
{
}

/*******************************************************************************
** Description: function for object to interact
*******************************************************************************/
void Blow::interact()
{
    std::cout<<"object of Blow"<<std::endl;
}
