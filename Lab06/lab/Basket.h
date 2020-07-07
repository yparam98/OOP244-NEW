/******************************************/
/*  Student:    Yathavan Parameshwaran    */
/*  Student #:  070 692 140               */
/*  Assignment: Workshop 6.1: Basket.h    */
/*  Course:     OOP244 (retake)           */
/*  Professor:  Andrei Sajeniouk          */
/*  Date:       July 07, 2020             */
/******************************************/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include "Fruit.h"

namespace sdds
{
    class Basket
    {
    private:
        Fruit *m_fruits{nullptr}; // array of Fruit objects
        int m_cnt{0};             // size of m_fruits array
        double m_price{0.00};     // price of Fruit basket

    public:
        Basket();
        ~Basket();

        Basket(Fruit[], int, double);
        Basket(const Basket &);
        Basket &operator=(const Basket &);

        void setPrice(double);
        explicit operator bool() const;
        Basket &operator+=(Fruit);

        friend std::ostream &operator<<(std::ostream &, Basket &);
    };
} // namespace sdds

#endif // SDDS_BASKET_H