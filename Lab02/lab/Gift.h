/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Student #:  070 692 140             */
/*  Assignment: Workshop 2.1: Gift.h    */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       June 3, 2020            */
/****************************************/

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
    const int MAX_DESC{15};
    const double MAX_PRICE{999.999};

    struct Gift
    {
        char m_description[MAX_DESC]{'\0'};
        double m_price{0.00};
        int m_units{0};
    };

    void gifting(char *);
    void gifting(double &);
    void gifting(int &);
    void display(const Gift &);
} // namespace sdds

#endif //SDDS_GIFT_H
