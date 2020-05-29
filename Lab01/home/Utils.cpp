/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include "Utils.h"

// constructor
sdds::Utils::Utils()
{
}

// destructor
sdds::Utils::~Utils()
{
}

// returns number of characters in incoming incoming_str
int sdds::Utils::str_size(const char *incoming_str)
{
    return strlen(incoming_str);
}

// copies contents of source into destination
bool sdds::Utils::str_copy(char *destination, const char *source)
{
    try
    {
        for (int index = 0; index < this->str_size(source); index++)
        {
            destination[index] = source[index];
        }
        return true;
    }
    catch (...)
    {
        return false;
    }
}

// calculates average of all values in incoming_ptr
double sdds::Utils::calculate_average(int *incoming_ptr, int number_of_elements)
{
    int total = 0;

    for (int index = 0; index < number_of_elements; index++)
    {
        total += incoming_ptr[index];
    }

    return (double) total / number_of_elements;
}

// returns "filtered" integer after validating using hardcoded specifications 
int sdds::Utils::is_valid(const char *incoming_input)
{
    bool valid = true;

    // check for integer validity
    if (!isdigit(incoming_input[0]))
    {
        std::cout << "Invalid Number, try again: ";
        valid = false;
    }

    // check for trailing chars
    if (valid)
    {
        for (int index = 0; index < str_size(incoming_input); index++)
        {
            if (!isdigit(incoming_input[index]))
            {
                std::cout << "Invalid trailing characters, try again: ";
                valid = false;
                break;
            }
        }
    }

    // check range
    if (valid)
    {
        if (std::atoi(incoming_input) < 5 || std::atoi(incoming_input) > 50)
        {
            std::cout << "Invalid value (5<=value<=50), try again: ";
            valid = false;
        }
    }

    return valid ? std::atoi(incoming_input) : -1;
}