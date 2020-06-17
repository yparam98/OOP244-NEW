/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 4.1: Saiyan.cpp */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 17, 2020            */
/*****************************************/

#include <iostream>
#include <cstring>
#include "Saiyan.h"

namespace sdds
{
    Saiyan::Saiyan()
    {
        this->m_name = nullptr;
        this->m_dob = 0;
        this->m_power = 0;
        this->m_super = false;
    }

    Saiyan::~Saiyan()
    {
        delete[] this->m_name;
        this->m_name = nullptr;
    }

    Saiyan::Saiyan(const char *incoming_name, int incoming_dob, int incoming_power)
    {
        // if incoming_name is a nullptr, then just send an empty string to "set" method... makes the validation easier
        this->set(incoming_name == nullptr ? "" : incoming_name, incoming_dob, incoming_power);
    }

    void Saiyan::set(const char *incoming_name, int incoming_dob, int incoming_power, bool incoming_super)
    {
        if (incoming_name[0] != '\0' && (incoming_dob > 0 && incoming_dob < 2020) && incoming_power > 0) // check validity
        {
            // copy over string
            int size = (std::strlen(incoming_name) + 1) <= MAX_NAME ? std::strlen(incoming_name) + 1 : MAX_NAME; // allocate to size of incoming string or MAX_NAME... whichever one is lower
            this->m_name = new char[size];
            std::strncpy(this->m_name, incoming_name, size - 1);
            this->m_name[size - 1] = '\0';

            // copy over dob
            this->m_dob = incoming_dob;

            // copy over power
            this->m_power = incoming_power;

            // copy over super
            this->m_super = incoming_super;
        }
    }

    bool Saiyan::isValid() const
    {
        return (this->m_name != nullptr && (this->m_dob > 0 && this->m_dob < 2020) && this->m_power > 0);
    }

    void Saiyan::display()
    {
        if (this->isValid()) // if valid... duh...
        {
            std::cout << this->m_name << std::endl;
            std::cout << "DOB: " << this->m_dob << std::endl;
            std::cout << "Power: " << this->m_power << std::endl;
            std::cout << "Super: " << (this->m_super ? "yes" : "no") << std::endl;
        }
        else
        {
            std::cout << "Invalid Saiyan!" << std::endl;
        }
    }

    bool Saiyan::fight(const Saiyan &other_saiyan)
    {
        return (this->isValid() && other_saiyan.isValid()) && this->m_power > other_saiyan.m_power;
    }
} // namespace sdds