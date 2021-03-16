/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Blow.hpp is the Blow object header file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/

#ifndef BLOW_HPP
#define BLOW_HPP
#include "Space.hpp" 

class Blow: public Space
{
    public:
        // member initialized constructor
        Blow(int x_t, int y_t); 
         
        // function for object to interact 
        virtual void interact();
};

#endif
