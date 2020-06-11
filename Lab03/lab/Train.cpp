/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.1: Train.cpp  */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#include <iostream>
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

            std::strncpy(this->train_cargo[0].description, car.description, MAX_DESC - 1);
            this->train_cargo[0].description[MAX_DESC] = '\0';
            this->train_cargo[0].weight = car.weight;
        }
    }
    void Train::unloadCargo()
    {
        delete[] this->train_cargo;
        this->train_cargo = nullptr;
    }
    void Train::display() const
    {
        if (!this->isValid())
        {
            std::cout << "***Train Summary***" << std::endl;
            std::cout << "This is an invalid train." << std::endl;
        }
        else
        {
            std::cout << "***Train Summary***" << std::endl;
            std::cout << "Name: " << this->train_name << std::endl;
            std::cout << "ID: " << this->train_id << std::endl;
            if (this->train_cargo == nullptr)
            {
                std::cout << "No cargo on this train." << std::endl;
            }
            else
            {
                std::cout << "Cargo: " << this->train_cargo[0].description << std::endl;
                std::cout << "Weight: " << this->train_cargo[0].weight << std::endl;
            }
        }
    }
} // namespace sdds