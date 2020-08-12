/***************************************************/
/*  Student:    Yathavan Parameshwaran             */
/*  Student #:  070 692 140                        */
/*  Assignment: Final Project: MS4: Motorcycle.h   */
/*  Course:     OOP244 (retake)                    */
/*  Professor:  Andrei Sajeniouk                   */
/*  Date:       August 11, 2020                    */
/***************************************************/

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include "Vehicle.h"

namespace sdds
{
    class Motorcycle : public Vehicle
    {
    private:
        bool has_sidecar{ false };
    public:
        Motorcycle();
        Motorcycle(const char*, const char*);

        Motorcycle(const Motorcycle&) = delete; // deleted copy constructor
        Motorcycle& operator=(const Motorcycle&) = delete; // deleted copy assignment operator

        std::istream& read(std::istream & = std::cin);
        std::ostream& write(std::ostream & = std::cout) const;
    };
}

#endif // SDDS_MOTORCYCLE_H