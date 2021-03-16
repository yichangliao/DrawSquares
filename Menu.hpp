/*******************************************************************************
** Author: Yi Chang Liao
** Date: 11/12/2019
** Description: Menu.hpp is the Menu class header file.
**              It contains:
**              (1). constructor and destructor
**              (2). method to copy all option descriptions 
**              (3). method to display menu
**              (4). method to get user options and check user input
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <string>

class Menu
{
    private:
        int option;
        std::string *optionArray;
    
    public:
        Menu();

        // One parameter constructor, set how many options for menu
        Menu(int);
        
        // Destructor
        ~Menu();

        // Set menu
        void setMenu(int);

        // Add option descriptions to menu
        void addOption(std::string [], int);

        // Display menu
        void showMenu();

        // Get user options, input validation
        int getUserOption();
};

#endif
