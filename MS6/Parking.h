/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS2: Parking.h    */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       July 17, 2020                    */
/*************************************************/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds
{
    const int MAX_PARKING_SPOTS{100};
    class Parking
    {
    private:
        char *file_name{nullptr};
        int indentation{0};
        Menu parking_menu{Menu()};
        Menu vehicle_selection_menu{Menu()};
        
        // ms6 additions
        int num_of_spots{0};
        int num_of_parked_vehicles{0};
        Vehicle* parking_spots[MAX_PARKING_SPOTS];

        bool invalid{false};
        
        bool isEmpty() const;
        void status() const;
        void park_vehicle();
        void return_vehicle();
        void list_parked_vehicles() const;
        bool close_parking();
        bool exit_parking_app() const;
        bool load_data_file();
        void save_data_file() const;

        void set_invalid();

    public:
        Parking();
        Parking(const char *, int); // updated for ms6
        ~Parking();

        Parking(const Parking &) = delete;
        Parking &operator=(const Parking &) = delete;

        int run();
    };
} // namespace sdds

#endif // SDDS_PARKING_H