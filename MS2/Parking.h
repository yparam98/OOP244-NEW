#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"

namespace sdds
{
    class Parking
    {
    private:
        char *file_name{nullptr};
        int indentation{0};
        Menu parking_menu;
        Menu vehicle_selection_menu;

        bool isEmpty() const;
        void status() const;
        void park_vehicle() const;
        void return_vehicle() const;
        void list_parked_vehicles() const;
        bool close_parking() const;
        bool exit_parking_app() const;
        bool load_data_file();
        void save_data_file() const;

    public:
        Parking();
        ~Parking();

        Parking(const Parking &);
        Parking &operator=(const Parking &);

        int run();
    };
} // namespace sdds

#endif // SDDS_PARKING_H