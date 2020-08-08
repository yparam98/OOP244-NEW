#include <iostream>
#include <cstring>
#include <cctype>
#include "Vehicle.h"

namespace sdds
{
    Vehicle::Vehicle()
    {
        this->license_plate = nullptr;
        this->make_model = nullptr;
        this->spot = 0;
    }

    Vehicle::~Vehicle()
    {
        if (this->license_plate != nullptr)
        {
            delete[] this->license_plate;
            this->license_plate = nullptr;
        }

        if (this->make_model != nullptr)
        {
            delete[] this->make_model;
            this->make_model = nullptr;
        }
    }

    Vehicle::Vehicle(const char* incoming_license_plate, const char* incoming_make_model)
    {
        if (incoming_license_plate != nullptr && incoming_make_model != nullptr)
        {
            int size = std::strlen(incoming_license_plate) <= MAX_LICENSE_PLATE ? std::strlen(incoming_license_plate) : MAX_LICENSE_PLATE;

            this->license_plate = new char[size + 1];
            std::strncpy(this->license_plate, incoming_license_plate, size);
            this->license_plate[size] = '\0';

            this->setMakeModel(incoming_make_model);
        }
    }

    int Vehicle::getParkingSpot() const
    {
        return this->spot;
    }

    void Vehicle::setParkingSpot(int incoming_spot)
    {
        this->spot = incoming_spot;
    }

    std::istream& Vehicle::read(std::istream& is = std::cin)
    {
        if (this->isCsv())
        {

        }
        else
        {
            char buffer[100];

            // user input for license plate
            std::cout << "Enter License Plate Number: ";
            std::cin >> buffer;

            while (std::strlen(buffer) > MAX_LICENSE_PLATE)
            {
                std::cout << "Invalid License Plate, try again: ";
                std::cin.ignore(1000, '\n');
                std::cin >> buffer;
            }
            
            if (this->license_plate != nullptr)
            {
                delete[] this->license_plate;
                this->license_plate = nullptr;
            }

            this->license_plate = new char[MAX_LICENSE_PLATE + 1];
            std::strncpy(this->license_plate, buffer, MAX_LICENSE_PLATE);
            this->license_plate[MAX_LICENSE_PLATE];

            // make and model input
            std::cout << "Enter Make and Model: ";
            std::cin >> buffer;

            while (std::strlen(buffer) < 2 || std::strlen(buffer) > 60)
            {
                std::cout << "Invalid Make and model, try again: ";
                std::cin.ignore(1000, '\n');
                std::cin >> buffer;
            }

            this->setMakeModel(buffer);
        }

    }

    std::ostream& Vehicle::write(std::ostream& os = std::cout) const
    {

    }

    bool operator==(const Vehicle& incoming_obj, const char* incoming_license_plate)
    {
        bool match = false;

        for (int index = 0; index < std::strlen(incoming_license_plate); index++)
        {
            // first check if digit
            if (std::isdigit(incoming_obj.getLicensePlate()[index]))
            {
                if (incoming_obj.getLicensePlate()[index] != incoming_license_plate[index])
                {
                    match = false;
                }
            }
            else // not digit
            {
                // get the ascii values
                int this_ascii_val = (int)incoming_obj.getLicensePlate()[index];
                int that_ascii_val = (int)incoming_license_plate[index];

                // check if uppercase (65 is capital A ascii dec val)
                if (this_ascii_val >= 65)
                {
                    // compare with same character, but lower case
                    match = (this_ascii_val - 32 == that_ascii_val);
                }
                else // not a capital letter
                {
                    // compare with the same character, but upper case
                    match = (this_ascii_val + 32 == that_ascii_val);
                }
            }

            return match;
        }
    }

    bool operator==(const Vehicle& obj1, const Vehicle& obj2)
    {
        return (std::strncmp(obj1.getLicensePlate(), obj2.getLicensePlate(), MAX_LICENSE_PLATE) == 0);
    }

    void Vehicle::setEmpty()
    {
        this->spot = 0;

        if (this->make_model != nullptr)
        {
            delete[] this->make_model;
            this->make_model = nullptr;
        }

        if (this->license_plate != nullptr)
        {
            delete[] this->license_plate;
            this->license_plate = nullptr;
        }
    }

    bool Vehicle::isEmpty() const
    {
        return (this->spot == 0 && this->license_plate == nullptr && this->make_model == nullptr);
    }

    const char* Vehicle::getLicensePlate() const
    {
        if (this->license_plate != nullptr)
        {
            return this->license_plate;
        }
    }

    const char* Vehicle::getMakeModel() const
    {
        if (this->make_model != nullptr)
        {
            return this->make_model;
        }
    }

    void Vehicle::setMakeModel(const char* incoming_str)
    {
        if (this->make_model != nullptr)
        {
            delete[] this->make_model;
            this->make_model = nullptr;
        }

        this->make_model = new char[std::strlen(incoming_str) + 1];
        this->make_model[std::strlen(incoming_str)] = '\0';
    }
}