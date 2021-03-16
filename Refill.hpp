/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Refill.hpp is the Refill object header file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/

#ifndef REFILL_HPP
#define REFILL_HPP
#include "Space.hpp" 

class Refill: public Space
{
    public:
        // member initialized constructor
        Refill(int x_t, int y_t); 
         
        // function for object to interact 
        virtual void interact();
};

#endif
