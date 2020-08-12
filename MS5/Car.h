/************************************************/
/*  Student:    Yathavan Parameshwaran          */
/*  Student #:  070 692 140                     */
/*  Assignment: Final Project: MS4: Car.h       */
/*  Course:     OOP244 (retake)                 */
/*  Professor:  Andrei Sajeniouk                */
/*  Date:       August 11, 2020                 */
/************************************************/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
    private:
        bool carwash{ false };
    public:
        Car();
        Car(const char*, const char*);

        Car(const Car&) = delete; // deleted copy constructor
        Car& operator=(const Car&) = delete; // deleted copy assignment operator

        std::istream& read(std::istream & = std::cin);
        std::ostream& write(std::ostream & = std::cout) const;
    };
}

#endif // SDDS_CAR_H