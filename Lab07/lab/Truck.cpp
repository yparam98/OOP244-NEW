#include <iostream>
#include "Truck.h"

namespace sdds
{
    Truck::Truck()
    {
        this->maximum_capacity = 0.0;
        this->current_capacity = 0.0;
    }

    Truck::Truck(const char *license_plate, int year, double capacity, const char *address) : MotorVehicle(license_plate, year)
    {
        this->current_capacity = 0.0;
        this->moveTo(address);
    }

    bool Truck::addCargo(double cargo)
    {
        if (cargo < maximum_capacity)
        {
            this->current_capacity += cargo;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Truck::unloadCargo()
    {
        if (this->current_capacity != 0.0)
        {
            this->current_capacity = 0.0;
            return true;
        }
        else
        {
            return false;
        }
    }

    std::ostream &Truck::write(std::ostream &os) const
    {
        MotorVehicle::write(os);
        os << " | " << this->current_capacity;

        return os;
    }

    std::istream &Truck::read(std::istream &is)
    {
        MotorVehicle::read(is);
        std::cout << "Capacity: ";
        is >> this->current_capacity;

        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Truck &tr)
    {
        return tr.write(os);
    }

    std::istream &operator>>(std::istream &is, Truck &tr)
    {
        return tr.read(is);
    }

} // namespace sdds
