/******************************************/
/*  Student:    Yathavan Parameshwaran    */
/*  Student #:  070 692 140               */
/*  Assignment: Workshop 5.2: Engine.cpp  */
/*  Course:     OOP244 (retake)           */
/*  Professor:  Nathan Misener            */
/*  Date:       June 28, 2020             */
/******************************************/

#include <iostream>
#include <iomanip>
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

    Engine::Engine(const Engine &incomingObj)
    {
        *this = incomingObj;
    }

    Engine &Engine::operator=(const Engine &incomingObj)
    {
        if (this != &incomingObj)
        {
            this->m_size = incomingObj.m_size;
            std::strncpy(this->m_type, incomingObj.m_type, std::strlen(incomingObj.m_type));
            this->m_type[std::strlen(incomingObj.m_type)] = '\0';
        }

        return *this;
    }

    double Engine::get() const
    {
        return this->m_size;
    }

    void Engine::display() const
    {
        if (this->m_size > 0 && this->m_type[0] != '\0')
        {
            std::cout << std::fixed << std::setprecision(2) << this->m_size << " liters - " << this->m_type << std::endl;
        }
    }
} // namespace sdds
