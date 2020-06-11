/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.2: Train.cpp  */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"

namespace sdds
{
    Train::Train()
    {
        for (int i = 0; i < MAX_NAME; i++)
            this->train_name[i] = '\0';
        this->train_id = 0;
        this->train_cargo = nullptr;
    }
    Train::~Train()
    {
        delete[] this->train_cargo;
        this->train_cargo = nullptr;
    }
    void Train::initialize(const char *name, int id)
    {
        if (name == nullptr || id <= 0)
        {
            for (int i = 0; i < MAX_NAME; i++)
                this->train_name[i] = '\0';
            this->train_id = 0;
            this->train_cargo = nullptr;
        }
        else
        {
            std::strncpy(this->train_name, name, MAX_NAME - 1);
            this->train_name[MAX_NAME] = '\0';
            this->train_id = id;
            this->train_cargo = nullptr;
        }
    }
    bool Train::isValid() const
    {
        if (this->train_id <= 0 || this->train_name[0] == '\0')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void Train::loadCargo(Cargo car)
    {
        if (this->train_cargo == nullptr)
        {
            this->train_cargo = new Cargo[1];
            this->train_cargo[0].setDesc(car.getDesc());
            this->train_cargo[0].setWeight(car.getWeight());
        }
    }
    void Train::unloadCargo()
    {
        delete[] this->train_cargo;
        this->train_cargo = nullptr;
    }
    void Train::display() const
    {
        std::cout.precision(3);

        if (!this->isValid())
        {
            std::cout << "***Train Summary***" << std::endl;
            std::cout << "This is an invalid train." << std::endl;
        }
        else
        {
            std::cout << "***Train Summary***" << std::endl;

            std::cout << std::setw(8) << std::right << "Name: ";
            std::cout << this->train_name << std::endl;

            std::cout << std::setw(8) << std::right << "ID: ";
            std::cout << this->train_id << std::endl;

            if (this->train_cargo == nullptr)
            {
                std::cout << "No cargo on this train." << std::endl;
            }
            else
            {
                std::cout << std::setw(8) << std::right << "Cargo: ";
                std::cout << this->train_cargo[0].getDesc() << std::endl;

                std::cout << std::setw(8) << std::right << "Weight: ";
                std::cout << this->train_cargo[0].getWeight() << std::endl;
            }
        }
    }
    bool Train::swapCargo(Train &other)
    {
        if (this->isValid() && other.isValid() && other.train_cargo != nullptr)
        {
            this->unloadCargo();
            this->loadCargo(other.train_cargo[0]);

            return true;
        }
        else
        {
            return false;
        }
    }
    bool Train::increaseCargo(double weight)
    {
        /* increases the carried cargo by weight tonnes only if the current train is valid, 
        carries valid cargo and the new weight doesn’t exceed MAX_WEIGHT. If the new cargo 
        exceeds the capcity, do not accept more than capacity. Return true if a change has 
        been made, false otherwise */

        if (this->isValid())
        {
            if (this->train_cargo != nullptr)
            {
                if (weight <= MAX_WEIGHT)
                {
                    this->train_cargo[0].setWeight(weight);
                    return true;
                }
            }
        }

        return false;
    }
    bool Train::decreaseCargo(double weight)
    {
        if (this->isValid())
        {
            if (this->train_cargo != nullptr)
            {
                if (weight >= MIN_WEIGHT)
                {
                    this->train_cargo[0].setWeight(weight);
                    return true;
                }
            }
        }

        return false;
    }
} // namespace sdds