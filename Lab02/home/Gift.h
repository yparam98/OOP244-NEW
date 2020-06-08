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
    const int MAX_WRAP{20};

    struct Wrapping
    {
        char *m_pattern{nullptr};

        ~Wrapping();
    };

    struct Gift
    {
        char m_description[MAX_DESC]{'\0'};
        double m_price{0.00};
        int m_units{0};

        ~Gift();

        Wrapping *m_wrap{nullptr};
        int m_wrapLayers{0};
    };

    void gifting(char *);
    void gifting(double &);
    void gifting(int &);
    void display(const Gift &);

    bool wrap(Gift &theGift);
    bool unwrap(Gift &theGift);
    void gifting(Gift &theGift);
} // namespace sdds

#endif //SDDS_GIFT_H
