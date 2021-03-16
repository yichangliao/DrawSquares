/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Eraser.hpp is the Eraser object header file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/

#ifndef ERASER_HPP
#define ERASER_HPP
#include "Space.hpp" 

class Eraser: public Space
{
    public:
        // member initialized constructor
        Eraser(int x_t, int y_t); 
         
        // function for object to interact 
        virtual void interact();
};

#endif
