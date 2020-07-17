#include <iostream>
#include <cstring>

#include "Parking.h"

namespace sdds
{
    /* default constructor: sets object to safe empty state */
    Parking::Parking()
    {
        this->file_name = nullptr;
        this->indentation = 0;
        this->parking_menu = Menu();
        this->vehicle_selection_menu = Menu();
    }

    /* destructor: deallocates (frees) any previously allocated memory */
    Parking::~Parking()
    {
        if (this->file_name != nullptr)
        {
            delete[] this->file_name;
            this->file_name = nullptr;
        }
    }

    /* copy constructor: copies existing object into new object */
    Parking::Parking(const Parking &incoming_obj)
    {
        this->file_name = nullptr;
        this->indentation = 0;
        this->parking_menu = Menu();
        this->vehicle_selection_menu = Menu();

        *this = incoming_obj;
    }

    /* copy assignment operator: copies existing object into another already existing object */
    Parking &Parking::operator=(const Parking &incoming_obj)
    {
        if (this != &incoming_obj)
        {
            this->indentation = incoming_obj.indentation;
            this->parking_menu = incoming_obj.parking_menu;                     // should call Menu copy-assignment operator
            this->vehicle_selection_menu = incoming_obj.vehicle_selection_menu; // same deal

            if (this->file_name != nullptr)
            {
                delete[] this->file_name;
                this->file_name = nullptr;
            }

            this->file_name = new char[std::strlen(incoming_obj.file_name) + 1];
            std::strncpy(this->file_name, incoming_obj.file_name, std::strlen(incoming_obj.file_name));
            this->file_name[std::strlen(incoming_obj.file_name)] = '\0';
        }

        return *this;
    }

    /* run function: runs Parking module */
    int Parking::run()
    {
        if (!this->isEmpty()) // if Parking is not in an invalid empty state...
        {
            /* code */
        }
        else
        {
            /* code */
        }
        
    }

    /* isEmpty query: returns true if the object is in a safe empty state, false otherwise */
    bool Parking::isEmpty() const
    {
        return (
            this->file_name == nullptr &&
            this->indentation == 0 &&
            this->parking_menu.isEmpty() &&
            this->vehicle_selection_menu.isEmpty());
    }

    /* status function */
    void Parking::status() const
    {
        std::cout << "****** Seneca VAlet Parking ******" << std::endl;
    }

    /* park vehicle */
    void Parking::park_vehicle() const
    {
        switch (this->vehicle_selection_menu.run())
        {
        case 1:
            std::cout << "Parking Car" << std::endl;
            break;
        case 2:
            std::cout << "Parking Motorcycle" << std::endl;
            break;
        case 3:
            std::cout << "Cancelled parking" << std::endl;
            break;
        default:
            break;
        }
    }

    /* return vehicle */
    void Parking::return_vehicle() const
    {
        std::cout << "Returning Vehicle" << std::endl;
    }

    /* list parked vehicles */
    void Parking::list_parked_vehicles() const
    {
        std::cout << "Listing Parked Vehicles" << std::endl;
    }

    /* close parking */
    bool Parking::close_parking() const
    {
        std::cout << "Closing Parking" << std::endl;
        return true;
    }

    /* exit the Parking application */
    bool Parking::exit_parking_app() const
    {
        char response = '\0';

        std::cout << "This will terminate the program!" << std::endl;
        std::cout << "Are you sure? (Y)es/(N)o: ";

        while ((response = std::getchar()) != 'Y' || 'N')
        {
            std::cin.ignore(256, '\0');
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        }

        return response == 'Y' ? true : false;
    }

    /* loads the data file */
    bool Parking::load_data_file()
    {
        if (!this->isEmpty())
        {
            std::cout << "loading data from " << this->file_name << std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    /* saves the data into the data file */
    void Parking::save_data_file() const
    {
        std::cout << "Saving data into " << this->file_name << std::endl;
    }

} // namespace sdds