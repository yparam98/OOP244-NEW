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

    Gift::~Gift()
    {
        delete[] this->m_wrap;
        this->m_wrap = nullptr;
    }

    void display(const Gift &theGift)
    {
        std::cout.precision(3);

        std::cout << "Gift Details:" << std::endl;
        std::cout << std::setw(14) << std::right << "Description: " << theGift.m_description << std::endl;
        std::cout << std::setw(14) << std::right << "Price: " << std::noshowpoint << theGift.m_price << std::endl;
        std::cout << std::setw(14) << std::right << "Units: " << theGift.m_units << std::endl;

        if (theGift.m_wrapLayers <= 0)
        {
            std::cout << "Unwrapped!" << std::endl;
        }
        else
        {
            std::cout << "Wrap Layers: " << theGift.m_wrapLayers << std::endl;
            for (int index = 0; index < theGift.m_wrapLayers; index++)
            {
                std::cout << "Wrap #" << index + 1 << " -> " << theGift.m_wrap[index].m_pattern << std::endl;
            }
        }
    }

    bool wrap(Gift &theGift)
    {
        if (theGift.m_wrapLayers <= 0) // if not wrapped
        {
            std::cout << "Wrapping gifts..." << std::endl;
            while (theGift.m_wrapLayers < 1)
            {
                std::cout << "Enter the number of wrapping layers for the Gift: ";
                std::cin >> theGift.m_wrapLayers;
                if (theGift.m_wrapLayers < 1)
                {
                    std::cout << "Layers at minimum must be 1, try again." << std::endl;
                }
            }

            theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];

            for (int index = 0; index < theGift.m_wrapLayers; index++)
            {
                char holder[50];

                std::cout << "Enter wrapping pattern #" << index + 1 << ": ";
                std::cin >> holder;
                std::cin.ignore(1000, '\n');

                theGift.m_wrap[index].m_pattern = new char[strlen(holder) + 1];
                std::strncpy(theGift.m_wrap[index].m_pattern, holder, strlen(holder));
                theGift.m_wrap[index].m_pattern[strlen(holder)] = '\0';
            }

            return true;
        }
        else
        {
            std::cout << "Gift is already wrapped!" << std::endl;

            return false;
        }
    }

    bool unwrap(Gift &theGift)
    {
        if (theGift.m_wrapLayers <= 0) // if not wrapped
        {
            std::cout << "Gift isn't wrapped! Cannot unwrap." << std::endl;

            return false;
        }
        else
        {
            std::cout << "Gift being unwrapped." << std::endl;
            delete[] theGift.m_wrap;
            theGift.m_wrap = nullptr;
            theGift.m_wrapLayers = 0;

            return true;
        }
    }

    void gifting(Gift &theGift)
    {
        std::cout << "Preparing a gift..." << std::endl;
        gifting(theGift.m_description);
        gifting(theGift.m_price);
        gifting(theGift.m_units);
        wrap(theGift);
    }

    Wrapping::~Wrapping()
    {
        delete[] this->m_pattern;
        this->m_pattern = nullptr;
    }
} // namespace sdds
