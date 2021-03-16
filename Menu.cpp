/*******************************************************************************
** Author: Yi Chang Liao
** Date: 11/12/2019
** Description: Menu.hpp is the Menu class implementation file.
**              It contains:
**              (1). constructor and destructor
**              (2). method to copy all option descriptions 
**              (3). method to display menu
**              (4). method to get user options and check user input
*******************************************************************************/


#include "Menu.hpp"
#include "getInteger.hpp"
#include <iostream>

/*******************************************************************************
** Description: default constructor
*******************************************************************************/
Menu::Menu()
{
    option = 0;
}

/*******************************************************************************
** Description: One parameter constructor
*******************************************************************************/
Menu::Menu(int optNum)
{
    option = optNum;
    optionArray = new std::string[option];
}

/*******************************************************************************
** Description: set menu
*******************************************************************************/
void Menu::setMenu(int optNum)
{
    option = optNum;
    optionArray = new std::string[option];
}

/*******************************************************************************
** Description: Destructor
*******************************************************************************/
Menu::~Menu()
{
    delete [] optionArray;
    optionArray = nullptr;
}

/*******************************************************************************
** Description: Add option descriptions to menu
*******************************************************************************/
void Menu::addOption(std::string input[], int number)
{
    if(option != number) // check number of options is correct
    {
        std::cout<<"Please check amount of options"<<std::endl;
    }
    else // copy descriptions
    {
        for(int i=0; i<option; i++)
        {
            optionArray[i] = input[i];
        }
    }
}

/*******************************************************************************
** Description: Display menu
*******************************************************************************/
void Menu::showMenu()
{
    std::cout<<"Choose from following options:\n";
    for(int i=0; i<option; i++)
    {
        std::cout<<"  "<< i <<". "<< optionArray[i] << std::endl;
    }
}

/*******************************************************************************
** Description: Get user options and check user input
*******************************************************************************/
int Menu::getUserOption()
{
    int choice = getInteger();
    while(choice < 0 || choice > option-1)
    {
        std::cout<<"Please enter within range 0 to "<<option-1<<std::endl;
        choice = getInteger();
    }

    return choice;
}

