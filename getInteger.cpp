/*************************************************************************************
** Author: Yi Chang Liao
** Date: 09/29/2019
** Description: getInteger.cpp is the getInteger function definition file.
**              This function request to enter one integer and verify whether the
**              input is an integer. If not, it will keep asking until the entry is 
**              valid. Once it is a valid integer, the function will return the number.
**              
**              Method: take the input as string and check every character whether is
**              a valid digit. If a character is a digit, make the sum plus 1. If all 
**              characters of the input string are digits, the sum will equal to the
**              length of the string.
**************************************************************************************/

#include "getInteger.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

int getInteger()
{
    // Initialize the string and the sum.
    std::string input;
    int flag = 0;

    // Ask for the input
    std::getline(std::cin, input);
    

    // Check the input until it is a valid integer
    do
    {
        if(input.length() == 0)
        {
            std::cout<< "don't press ENTER at the beginning" << std::endl;
            std::getline(std::cin, input);
        }
        else
        {
            // Check if the input is a negative integer
            if (input[0] == '-')
            {
                flag++;
            }
        
            // Check every character
            for (int i=0; i<input.length(); i++)
            {
                if (isdigit(input[i]))
                {
                    flag++;
                }
            }
        
            // Check the sum
            if (flag != input.length())
            {   
                std::cout << "Not a valid integer input" << std::endl;
                std::getline(std::cin, input);
                flag = 0;
            }
        }
    }while (flag == 0);

    return std::stoi(input);
}
