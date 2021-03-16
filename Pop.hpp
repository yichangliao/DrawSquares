/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Pop.hpp is the Pop object header file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/

#ifndef POP_HPP
#define POP_HPP
#include "Space.hpp" 

class Pop: public Space
{
    public:
        // member initialized constructor
        Pop(int x_t, int y_t); 
         
        // function for object to interact 
        virtual void interact();
};

#endif
