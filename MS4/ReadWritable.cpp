/*****************************************************/
/*  Student:    Yathavan Parameshwaran               */
/*  Student #:  070 692 140                          */
/*  Assignment: Final Project: MS3: ReadWritable.cpp */
/*  Course:     OOP244 (retake)                      */
/*  Professor:  Andrei Sajeniouk                     */
/*  Date:       August 5, 2020                       */
/*****************************************************/

#include "ReadWritable.h"

namespace sdds
{
    ReadWritable::ReadWritable()
    {
        this->comma_seperated = false;
    }
    ReadWritable::~ReadWritable()
    {

    }
    bool ReadWritable::isCsv() const
    {
        return this->comma_seperated;
    }
    void ReadWritable::setCsv(bool value)
    {
        this->comma_seperated = value;
    }

    std::ostream& operator<<(std::ostream& os, const ReadWritable& rw)
    {
        return rw.write(os);
    }

    std::istream& operator>>(std::istream& is, ReadWritable& rw)
    {
        return rw.read(is);
    }
}