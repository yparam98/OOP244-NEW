/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 5.1: Ship.h     */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 26, 2020            */
/*****************************************/

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER{90.111};
    const double MAX_STD_POWER{99.999};

    const int MAX_ENGINES{10};

    class Ship
    {
    private:
        Engine m_engines[MAX_ENGINES];
        char m_type[TYPE_MAX_SIZE];
        int m_engCnt{0};

        double total_output_power{0.0};

        void updateTotalPower();

    public:
        Ship();
        Ship(const char *, Engine *, int);
        explicit operator bool() const;
        Ship &operator+=(Engine);
        bool operator<(double) const;
        void display() const;
        friend bool operator<(double, const Ship &);
    };
} // namespace sdds

#endif // SDDS_SHIP_H