/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 5.1: Engine.cpp */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 26, 2020            */
/*****************************************/

#include <iostream>
#include <cstring>

#include "Engine.h"

namespace sdds
{
    Engine::Engine()
    {
        this->m_size = 0.0;
        this->m_type[0] = '\0';
    }

    Engine::Engine(const char *incoming_type, double incoming_size)
    {
        if ((incoming_type != nullptr || incoming_type[0] != '\0') && incoming_size > 0)
        {
            std::strncpy(this->m_type, incoming_type, TYPE_MAX_SIZE);
            this->m_type[TYPE_MAX_SIZE] = '\0';

            this->m_size = incoming_size;
        }
    }

    double Engine::get() const
    {
        return this->m_size;
    }

    void Engine::display() const
    {
        if (this->m_size > 0 && this->m_type[0] != '\0')
        {
            std::cout << this->m_size << " liters - " << this->m_type << std::endl;
        }
    }
} // namespace sdds