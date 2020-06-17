/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.2: Cargo.cpp  */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#include <iostream>
#include <cstring>
#include "Cargo.h"

namespace sdds
{
    Cargo::Cargo()
    {
        this->description[0] = '\0';
        this->weight = 0.00;
    }

    Cargo::~Cargo()
    {
    }

    void Cargo::initialize(const char *desc, double weight)
    {
        this->setDesc(desc);
        this->setWeight(weight);
    }

    const char *Cargo::getDesc() const
    {
        return &this->description[0];
    }

    double Cargo::getWeight() const
    {
        return this->weight;
    }

    void Cargo::setDesc(const char *description)
    {
        std::strncpy(this->description, description, MAX_DESC - 1);
        this->description[MAX_DESC] = '\0';
    }

    void Cargo::setWeight(double incoming_weight)
    {
        if (incoming_weight >= MIN_WEIGHT && incoming_weight <= MAX_WEIGHT) // if weight is invalid
        {
            this->weight = incoming_weight;
        }
        else
        {
            this->weight = MIN_WEIGHT;
        }
    }
} // namespace sdds