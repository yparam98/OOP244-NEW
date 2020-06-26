#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER{90.111};
    const double MAX_STD_POWER{99.999};

    class Ship
    {
    private:
        Engine m_engines[10];
        char m_type[TYPE_MAX_SIZE];
        int m_engCnt{0};

    public:
        Ship();
        Ship(const char *, Engine &, int);
        explicit operator bool() const;
        Ship &operator+=(Engine);
        bool operator<(double) const;
        void display() const;
        friend bool operator<(double, const Ship &);
    };
} // namespace sdds

#endif // SDDS_SHIP_H