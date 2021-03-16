/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Pop.hpp is the Pop object implementation file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/
#include "Pop.hpp"
#include <iostream>

/*******************************************************************************
** Description: member initialized constructor.
*******************************************************************************/
Pop::Pop(int x_t, int y_t): Space('?', x_t, y_t)
{
}

/*******************************************************************************
** Description: function for object to interact
*******************************************************************************/
void Pop::interact()
{
    std::cout<<"object of Pop"<<std::endl;
}
