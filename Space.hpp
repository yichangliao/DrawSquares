/*******************************************************************************
** Author: Yi Chang Liao
** Date: 12/08/2019
** Description: Space.hpp is the space object base header file
**              It contains:
**              (1). the object and x, y location 
**              (2). 4 space pointers
**              (3). member initialized constructor
**              (4). get methods for x, y and object
**              (5). set methods for 4 pointers
**              (6). Virtual function for object to interact
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

enum Direction{LEFT=1 ,RIGHT=3, UP=5 ,DOWN=2};

class Space
{
    protected:
        char object;
        int x; // location at column
        int y; // location at row
        
        // 4 space pointers
        Space* next;
        Space* prev;
        Space* top;
        Space* bottom;

    public:
        // member initialized constructor
        Space(char object_t, int x_t, int y_t, Space* next_t=nullptr, 
        Space* prev_t=nullptr, Space* top_t=nullptr, Space* bottom_t=nullptr); 
         
        // Get methods for x, y, object
        int getX(int nextNode=0);
        int getY(int nextNode=0);
        char getObject(int nextNode=0);

        // Set methods for 4 pointers
        void setNext(Space*);
        void setPrev(Space*);
        void setTop(Space*);
        void setBottom(Space*);

        // Virtual function for object to interact 
        virtual void interact()=0;
};

#endif
