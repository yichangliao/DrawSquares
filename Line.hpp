/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Line.hpp is the Line object header file
**              It contains:
**              (1). member initialized constructor
**              (2). virtual function for object to interact
**              (3). 
*******************************************************************************/

#ifndef LINE_HPP
#define LINE_HPP
#include "Space.hpp" 

class Line: public Space
{
    public:
        // member initialized constructor
        Line(int x_t, int y_t); 
         
        // function for object to interact 
        virtual void interact();
};

#endif
