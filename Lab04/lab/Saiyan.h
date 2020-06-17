/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 4.1: Saiyan.h   */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 17, 2020            */
/*****************************************/

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
    const int MAX_NAME = 32;

    class Saiyan
    {
    private:
        char *m_name{nullptr};
        unsigned int m_dob{0};
        int m_power{0};
        bool m_super{false};

    public:
        Saiyan();
        ~Saiyan();
        Saiyan(const char *, int, int);
        void set(const char *, int, int, bool = false);
        bool isValid() const;
        void display();
        bool fight(const Saiyan &);
    };
} // namespace sdds

#endif //SDDS_SAIYAN_H