/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Refill.hpp is the Refill object implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/
#include "Refill.hpp"
#include <iostream>

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Refill::Refill(int x_t, int y_t): Space('@', x_t, y_t)
{
}

/*******************************************************************************
** Description: function for object to interact
*******************************************************************************/
void Refill::interact()
{
    std::cout<<"plus 1 point of ink"<<std::endl;
}
