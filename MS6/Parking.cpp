/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS2: Parking.cpp  */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       July 17, 2020                    */
/*************************************************/

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

        // added for ms6
        for (int index = 0; index < MAX_PARKING_SPOTS; index++)
        {
            this->parking_spots[index] = nullptr;
        }
    }

    /* 1-arg constructor: create Parking object with name of data file <UPDATED FOR MS6> */
    Parking::Parking(const char *incoming_str, int noOfSpots)
    {
        if (incoming_str == nullptr || incoming_str[0] == '\0')
        {
            this->set_invalid();
        }
        else
        {
            int size = std::strlen(incoming_str);
            this->file_name = new char[size + 1];
            std::strncpy(this->file_name, incoming_str, size);
            this->file_name[size] = '\0';
        }

        if (this->load_data_file())
        {
            this->parking_menu = Menu("Parking Menu, select an action:", 0);

            this->parking_menu.add("Park Vehicle");
            this->parking_menu.add("Return Vehicle");
            this->parking_menu.add("List Parked Vehicles");
            this->parking_menu.add("Close Parking (End of day)");
            this->parking_menu.add("Exit Program");

            this->vehicle_selection_menu = Menu("Select type of the vehicle:", 1);

            this->vehicle_selection_menu.add("Car");
            this->vehicle_selection_menu.add("Motorcycle");
            this->vehicle_selection_menu.add("Cancel");
        }
        else
        {
            std::cout << "Error in data file" << std::endl;
            this->set_invalid();
        }

        // added for ms6
        if (noOfSpots < 10 || num_of_spots > MAX_PARKING_SPOTS)
        {
            this->num_of_spots = noOfSpots;
        }
        else
        {
            this->set_invalid();
        }

        // added for ms6
        for (int index = 0; index < MAX_PARKING_SPOTS; index++)
        {
            this->parking_spots[index] = nullptr;
        }
    }

    /* destructor: deallocates (frees) any previously allocated memory */
    Parking::~Parking()
    {
        this->save_data_file();

        if (this->file_name != nullptr)
        {
            delete[] this->file_name;
            this->file_name = nullptr;
        }

        // added for ms6
        for (int index = 0; index < MAX_PARKING_SPOTS; index++)
        {
            if (this->parking_spots[index] != nullptr)
            {
                delete[] this->parking_spots[index];
                this->parking_spots[index] = nullptr;
            }
        }
    }

    /* (deleted) copy constructor: copies existing object into new object */
    // Parking::Parking(const Parking &incoming_obj)
    // {
    // this->file_name = nullptr;
    // this->indentation = 0;
    // this->parking_menu = Menu();
    // this->vehicle_selection_menu = Menu();

    // *this = incoming_obj;
    // }

    /* (deleted) copy assignment operator: copies existing object into another already existing object */
    // Parking &Parking::operator=(const Parking &incoming_obj)
    // {
    // if (this != &incoming_obj)
    // {
    //     this->indentation = incoming_obj.indentation;
    //     this->parking_menu = incoming_obj.parking_menu;                     // should call Menu copy-assignment operator
    //     this->vehicle_selection_menu = incoming_obj.vehicle_selection_menu; // same deal

    //     if (this->file_name != nullptr)
    //     {
    //         delete[] this->file_name;
    //         this->file_name = nullptr;
    //     }

    //     this->file_name = new char[std::strlen(incoming_obj.file_name) + 1];
    //     std::strncpy(this->file_name, incoming_obj.file_name, std::strlen(incoming_obj.file_name));
    //     this->file_name[std::strlen(incoming_obj.file_name)] = '\0';
    // }

    // return *this;
    // }

    /* run function: runs Parking module */
    int Parking::run()
    {
        if (!this->isEmpty()) // if Parking is not in an invalid empty state...
        {
            bool exit_val = false;

            while (exit_val == false)
            {
                this->status();

                switch (this->parking_menu.run())
                {
                case 1:
                    this->park_vehicle();
                    continue;
                case 2:
                    this->return_vehicle();
                    continue;
                case 3:
                    this->list_parked_vehicles();
                    continue;
                case 4:
                    if (this->close_parking())
                    {
                        exit_val = true;
                        break;
                    }
                case 5:
                    if (!this->exit_parking_app())
                    {
                        continue;
                    }
                    else
                    {
                        exit_val = true;
                        break;
                    }
                default:
                    continue;
                }
            }

            return this->isEmpty() == true ? 1 : 0;
        }
        else
        {
            return 1;
        }
    }

    /* isEmpty query: returns true if the object is in an invalid empty state, false is valid and usable */
    bool Parking::isEmpty() const
    {
        if (this->indentation == -1)
        {
            return true;
        }
        else if (this->file_name != nullptr && this->indentation >= 0)
        {
            return false;
        }
        else if (this->file_name == nullptr && this->indentation == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    /* status function */
    void Parking::status() const
    {
        std::cout << "****** Seneca Valet Parking ******" << std::endl;
        std::cout << "*****  Available spots: ";
        std::cout << std::setw(4) << std::left << this->num_of_spots << std::endl;
        std::cout << "*****" << std::endl;
    }

    /* park vehicle */
    void Parking::park_vehicle()
    {
        if (this->num_of_parked_vehicles < this->num_of_spots)
        {
            std::cout << "Parking is full" << std::endl;
        }
        else
        {
            switch (this->vehicle_selection_menu.run())
            {
            case 1:
                std::cout << "Parking Car" << std::endl;

                // dynamically create an instance of Car as Vehicle pointer
                Vehicle *vehicle = new Car();

                // set CSV to false
                vehicle->setCsv(false);

                // read from console
                vehicle->read(std::cin);

                // search parking spots array for first available spot, set it to the Car obj
                for (int index = 0; index < this->num_of_spots; index++)
                {
                    if (parking_spots[index] == nullptr)
                    {
                        parking_spots[index] = vehicle;
                        parking_spots[index]->setParkingSpot(index + 1);

                        this->num_of_parked_vehicles++;

                        std::cout << "Parking Ticket" << std::endl;
                        parking_spots[index]->write(std::cout);

                        break;
                    }
                }

                break;
            case 2:
                std::cout << "Parking Motorcycle" << std::endl;

                // dynamically create an instance of Motorcycle as Vehicle pointer
                Vehicle *vehicle = new Motorcycle();

                // set CSV to false
                vehicle->setCsv(false);

                // read from console
                vehicle->read(std::cin);

                // search parking spots array for first available spot, set it to the Motorcycle obj
                for (int index = 0; index < this->num_of_spots; index++)
                {
                    if (parking_spots[index] == nullptr)
                    {
                        parking_spots[index] = vehicle;
                        parking_spots[index]->setParkingSpot(index + 1);

                        this->num_of_parked_vehicles++;

                        std::cout << "Parking Ticket" << std::endl;
                        parking_spots[index]->write(std::cout);
                        
                        break;
                    }
                }

                break;
            case 3:
                std::cout << "Parking Cancelled" << std::endl;
                break;
            default:
                break;
            }
        }
    }

    /* return vehicle */
    void Parking::return_vehicle()
    {
        std::cout << "Return Vehicle" << std::endl;

        char buffer[10];
        bool found = false;

        std::cout << "Enter Licence Plate Number: ";
        while (std::strlen(buffer) < 1 && std::strlen(buffer) > 8)
        {
            std::cout << "Invalid Licence Plate, try again: ";
            std::cin.getline(buffer, 10, '\n');
        }

        for (int index = 0; index < this->num_of_spots; index++)
        {
            if (this->parking_spots[index] != nullptr)
            {
                if (*this->parking_spots[index] == &buffer[0])
                {
                    found = true;

                    std::cout << "Returning: " << std::endl;
                    this->parking_spots[index]->write(std::cout);

                    delete[] this->parking_spots[index];
                    this->parking_spots[index] = nullptr;
                }
            }
        }

        if (!found)
        {
            std::cout << "License plate " << buffer << " Not found" << std::endl;
        }
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
        char response[16];

        std::cout << "This will terminate the program!" << std::endl;
        std::cout << "Are you sure? (Y)es/(N)o: ";

        while (std::cin.getline(response, 15, '\n'))
        {
            try
            {
                if (std::strlen(response) == 1)
                {
                    if (std::strncmp(response, "Y", 1) == 0 ||
                        std::strncmp(response, "y", 1) == 0 ||
                        std::strncmp(response, "N", 1) == 0 ||
                        std::strncmp(response, "n", 1) == 0)
                    {
                        throw true;
                    }
                    else
                    {
                        throw false;
                    }
                }
                else
                {
                    throw false;
                }
            }
            catch (bool glove)
            {
                if (glove)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    continue;
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                continue;
            }
        }

        if (std::strncmp(response, "y", 1) == 0)
        {
            std::cout << "Exiting program!" << std::endl;
            return true;
        }
        else
        {
            return false;
        }
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
        if (!this->isEmpty())
        {
            std::cout << "Saving data into " << this->file_name << std::endl;
        }
    }

    void Parking::set_invalid()
    {
        this->indentation = -1;
        this->parking_menu = Menu();
        this->parking_menu = Menu();
        this->file_name = nullptr;
    }

} // namespace sdds