/***************************************************/
/*  Student:    Yathavan Parameshwaran             */
/*  Student #:  070 692 140                        */
/*  Assignment: Final Project: MS6: Motorcycle.cpp */
/*  Course:     OOP244 (retake)                    */
/*  Professor:  Andrei Sajeniouk                   */
/*  Date:       August 15, 2020                    */
/***************************************************/
/***************************************************/
/* I have done all the coding by myself and only   */ 
/*  copied the code that my professor provided     */
/*  to complete this program.                      */
/***************************************************/

#include <iostream>
#include <cstring>
#include "Motorcycle.h"

namespace sdds
{
    Motorcycle::Motorcycle() : Vehicle()
    {
        this->has_sidecar = false;
    }

    Motorcycle::Motorcycle(const char* incoming_license_plate, const char* incoming_make_model)
    {
        if (incoming_license_plate != nullptr || incoming_make_model != nullptr)
        {
            Vehicle(incoming_license_plate, incoming_make_model);
        }
        else
        {
            this->setEmpty();
        }
    }

    std::istream& Motorcycle::read(std::istream &is)
    {
        if (Vehicle::isCsv())
        {
            Vehicle::read(is);

            char sidecar_flag = '\0';
            is.get(sidecar_flag);
            // is.ignore(1000);            

            this->has_sidecar = ((sidecar_flag != 0) ? false : true);
        }
        else
        {
            char* sidecar_entry = new char[10];

            std::cout << "\nMotorcycle information entry" << std::endl;
            Vehicle::read();
            // is.ignore(1000, '\n');
            std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            is.getline(sidecar_entry, 10, '\n');
            while ((std::strlen(sidecar_entry) > 1) && (sidecar_entry[0] != 'Y' || sidecar_entry[0] != 'N' || sidecar_entry[0] != 'y' || sidecar_entry[0] != 'n'))
            {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                is.getline(sidecar_entry, 10, '\n');
            }
            
            this->has_sidecar = ((sidecar_entry[0] == 'y' || sidecar_entry[0] == 'Y') ? true : false);
            
            delete[] sidecar_entry;
        }

        return is;
    }

    std::ostream& Motorcycle::write(std::ostream &os) const
    {
        if (Vehicle::isEmpty())
        {
            os << "Invalid Motorcycle Object" << std::endl;
        }
        else
        {
            os << (Vehicle::isCsv() ? "M," : "Vehicle type: Motorcycle");
            Vehicle::write(os);
            if (Vehicle::isCsv())
            {
                os << this->has_sidecar << std::endl;
            }
            else
            {
                if (this->has_sidecar)
                {
                    os << "With Sidecar" << std::endl;
                }
            }
        }

        return os;
    }
}