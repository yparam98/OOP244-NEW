#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include "ReadWritable.h"

namespace sdds
{
    const int MAX_LICENSE_PLATE{8};

    class Vehicle : public ReadWritable
    {
        private:
            char* license_plate{nullptr};
            char* make_model{nullptr};
            int spot{0};

    protected:
            void setEmpty();
            bool isEmpty() const;
            const char* getLicensePlate() const;
            const char* getMakeModel() const;
            void setMakeModel(const char* incoming_str);

        public:
            Vehicle();
            ~Vehicle();

            Vehicle(const char*, const char*);

            Vehicle(const Vehicle&) = delete; // deleted copy constructor
            Vehicle& operator=(const Vehicle&) = delete; // deleted copy assignment operator

            int getParkingSpot() const;
            void setParkingSpot(int);

            std::istream& read(std::istream& = std::cin);
            std::ostream& write(std::ostream& = std::cout) const;

            friend bool operator==(const Vehicle&, const char*);
            friend bool operator==(const Vehicle&, const Vehicle&);            
    };
}
#endif // SDDS_VEHICLE_H