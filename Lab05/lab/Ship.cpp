/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 5.1: Ship.cpp   */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 26, 2020            */
/*****************************************/

#include <iostream>
#include <cstring>

#include "Ship.h"

namespace sdds
{
    Ship::Ship()
    {
        this->m_engines[0] = Engine();
        this->m_type[0] = '\0';
        this->m_engCnt = 0;

        this->total_output_power = 0.0;
    }

    Ship::Ship(const char *incoming_type, Engine *incoming_arr, int incoming_size)
    {
        if ((incoming_type != nullptr || incoming_type[0] != '\0') && incoming_arr != nullptr && incoming_size != 0)
        {
            std::strncpy(this->m_type, incoming_type, TYPE_MAX_SIZE);

            this->m_engCnt = incoming_size <= MAX_ENGINES ? incoming_size : MAX_ENGINES;

            for (int index = 0; index < this->m_engCnt; index++)
            {
                this->m_engines[index] = incoming_arr[index];
            }

            updateTotalPower();
        }
    }

    Ship::operator bool() const
    {
        if (this->m_engCnt >= 0 && this->m_engines[0].get() >= 0 && this->m_type[0] != '\0')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Ship &Ship::operator+=(Engine incoming_obj)
    {
        if (this->m_engCnt < MAX_ENGINES && this->m_type[0] != '\0' && incoming_obj.get() > 0)
        {
            this->m_engines[this->m_engCnt] = incoming_obj;
            this->m_engCnt++;

            updateTotalPower();
        }
        else
        {
            std::cout << "The object is not valid! Engine cannot be added!" << std::endl;
        }

        return *this;
    }

    bool Ship::operator<(double incoming_num) const
    {
        return this->total_output_power < incoming_num;
    }

    void Ship::display() const
    {
        if (this->m_engCnt > 0)
        {
            std::cout << this->m_type << " - " << this->total_output_power << std::endl;
            for (int index = 0; index < this->m_engCnt; index++)
            {
                this->m_engines[index].display();
            }
        }
        else
        {
            std::cout << "No available data" << std::endl;
        }
    }

    void Ship::updateTotalPower()
    {
        this->total_output_power = 0.0;

        for (int index = 0; index < this->m_engCnt; index++)
        {
            this->total_output_power = this->total_output_power + this->m_engines[index].get();
        }
        this->total_output_power = this->total_output_power * 5;
    }

    bool operator<(double power, const Ship &theShip)
    {
        return power < theShip.total_output_power;
    }
} // namespace sdds