/***************************************************/
/*  Student:    Yathavan Parameshwaran             */
/*  Student #:  070 692 140                        */
/*  Assignment: Final Project: MS6: Motorcycle.h   */
/*  Course:     OOP244 (retake)                    */
/*  Professor:  Andrei Sajeniouk                   */
/*  Date:       August 15, 2020                    */
/***************************************************/
/***************************************************/
/* I have done all the coding by myself and only   */ 
/*  copied the code that my professor provided     */
/*  to complete this program.                      */
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