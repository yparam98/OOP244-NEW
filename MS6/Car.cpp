/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS6: Car.cpp      */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       August 15, 2020                  */
/*************************************************/
/*************************************************/
/* I have done all the coding by myself and only */ 
/*  copied the code that my professor provided   */
/*  to complete this program.                    */
/*************************************************/

#include <iostream>
#include <cstring>
#include "Car.h"

namespace sdds
{
    Car::Car() : Vehicle()
    {
        this->carwash = false;
    }

    Car::Car(const char* incoming_license_plate, const char* incoming_make_model) : Vehicle(incoming_license_plate, incoming_make_model)
    {
        if (incoming_license_plate != nullptr || incoming_make_model != nullptr)
        {
            Vehicle(incoming_license_plate, incoming_make_model);
        }
        else
        {
            Vehicle::setEmpty();
        }
    }

    std::istream& Car::read(std::istream &is)
    {
        if (Vehicle::isCsv())
        {
            Vehicle::read(is);

            char carwash_flag = '\0';
            is.get(carwash_flag);
            // is.ignore(1000);

            this->carwash = ((carwash_flag != 0) ? false : true);
        }
        else
        {
            char* carwash_entry = new char[10];

            std::cout << "\nCar information entry" << std::endl;
            Vehicle::read();
            // is.ignore(1000, '\n');
            std::cout << "Carwash while parked? (Y)es/(N)o: ";
            is.getline(carwash_entry, 10, '\n');
            while ((std::strlen(carwash_entry) > 1) && (carwash_entry[0] != 'Y' || carwash_entry[0] != 'N' || carwash_entry[0] != 'y' || carwash_entry[0] != 'n'))
            {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                is.getline(carwash_entry, 10, '\n');
            }
            
            this->carwash = ((carwash_entry[0] == 'y' || carwash_entry[0] == 'Y') ? true : false);
            
            delete[] carwash_entry;
        }

        return is;
    }

    std::ostream& Car::write(std::ostream &os) const
    {
        if (Vehicle::isEmpty())
        {
            os << "Invalid Car Object" << std::endl;
        }
        else
        {
            os << (Vehicle::isCsv() ? "C," : "Vehicle type: Car");
            Vehicle::write(os);
            if (Vehicle::isCsv())
            {
                os << this->carwash << std::endl;
            }
            else
            {
                os << "With" << (this->carwash ? " " : "out ") << "Carwash" << std::endl;
            }
        }

        return os;
    }
}