/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Student #:  070 692 140             */
/*  Assignment: Workshop 2.1: Gift.cpp  */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       June 3, 2020            */
/****************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Gift.h"

namespace sdds
{
    void gifting(char *desc)
    {
        std::cout << "Enter gift description: ";
        std::cin.width(MAX_DESC + 1);
        std::cin >> desc;
        desc[strlen(desc) + 1] = '\0';
    }

    void gifting(double &print)
    {
        do
        {
            std::cout << "Enter gift price: ";
            if (std::cin >> print && (print < 0 || print > MAX_PRICE))
            {
                std::cout << "Gift price must be between 0 and " << MAX_PRICE << std::endl;
            }
        } while (print < 0 || print > MAX_PRICE);
    }

    void gifting(int &units)
    {
        do
        {
            std::cout << "Enter gift units: ";
            if (std::cin >> units && units < 1)
            {
                std::cout << "Gift units must be at least 1" << std::endl;
            }
        } while (units < 1);
    }

    void display(const Gift &theGift)
    {
        std::cout.precision(3);

        std::cout << "Gift Details:" << std::endl;
        std::cout << std::setw(14) << std::right << "Description: " << theGift.m_description << std::endl;
        std::cout << std::setw(14) << std::right << "Price: " << std::noshowpoint << theGift.m_price << std::endl;
        std::cout << std::setw(14) << std::right << "Units: " << theGift.m_units << std::endl;
    }

    bool wrap(Gift &theGift)
    {
    }

    bool unwrap(Gift &theGift)
    {
    }

    void gifting(Gift &theGift)
    {
    }
} // namespace sdds
