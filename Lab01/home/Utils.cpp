/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include <iostream>
#include <cstring>
#include "Utils.h"

sdds::Utils::Utils()
{

}

sdds::Utils::~Utils()
{

}

int sdds::Utils::str_size(const char* incoming_str)
{
    return strlen(incoming_str);
}

double sdds::Utils::calculate_average(int* incoming_ptr, int number_of_elements)
{
    int total = 0;

    for (int index = 0; index < number_of_elements; index++)
    {
        total += incoming_ptr[index];
    }

    return total / number_of_elements;
}