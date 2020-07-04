/******************************************/
/*  Student:    Yathavan Parameshwaran    */
/*  Student #:  070 692 140               */
/*  Assignment: Workshop 5.2: Ship.cpp    */
/*  Course:     OOP244 (retake)           */
/*  Professor:  Nathan Misener            */
/*  Date:       June 28, 2020             */
/******************************************/

#include <iostream>
#include <iomanip>
#include <cstring>

#include "Ship.h"

namespace sdds
{
    Ship::Ship()
    {
        this->m_engines = nullptr; // update to dynamic memory
        this->m_type = nullptr; // update to dynamic memory
        this->m_engCnt = 0;

        this->total_output_power = 0.0;
    }

    Ship::~Ship()
    {
        if (this->m_type != nullptr)
        {
            delete[] this->m_type;
            this->m_type = nullptr;
        }

        if (this->m_engines != nullptr)
        {
            delete[] this->m_engines;
            this->m_engines = nullptr;
        }
    }

    Ship::Ship(const char *incoming_type, Engine *incoming_arr, int incoming_size)
    {
        if ((incoming_type != nullptr || incoming_type[0] != '\0') && incoming_arr != nullptr && incoming_size != 0)
        {
            int size = std::strlen(incoming_type) < (TYPE_MAX_SIZE + 1) ? std::strlen(incoming_type) : (TYPE_MAX_SIZE + 1);

            this->m_type = new char[size + 1]; // allocate to whichever is smaller...
            std::strncpy(this->m_type, incoming_type, size);
            this->m_type[size] = '\0';

            this->m_engCnt = incoming_size <= MAX_ENGINES ? incoming_size : MAX_ENGINES;

            this->m_engines = new Engine[this->m_engCnt];

            for (int index = 0; index < this->m_engCnt; index++)
            {
                this->m_engines[index] = incoming_arr[index];
            }

            updateTotalPower();
        }
    }

    Ship::operator bool() const
    {
        if (this->m_engCnt >= 0 && this->m_engines != nullptr && this->m_type != nullptr)
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
        if (this->m_engCnt < MAX_ENGINES && this->m_engines != nullptr && this->m_type != nullptr && incoming_obj.get() > 0)
        {
            // copy over existing data 
            Engine temp[this->m_engCnt];

            for (int index = 0; index < this->m_engCnt; index++)
            {
                temp[index] = this->m_engines[index];
            }

            // deallocate old arr
            delete[] this->m_engines;

            // increase num of engines
            this->m_engCnt++;

            // allocate new memory
            this->m_engines = new Engine[this->m_engCnt];

            // copy over data back to ptr
            for (int index = 0; index < (this->m_engCnt - 1); index++)
            {
                this->m_engines[index] = temp[index];
            }

            // add the new engine
            this->m_engines[this->m_engCnt - 1] = incoming_obj;

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
            std::cout << std::fixed << std::setprecision(2) << this->m_type << " - " << this->total_output_power << std::endl;
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
