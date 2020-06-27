/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 5.1: Engine.h   */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 26, 2020            */
/*****************************************/

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
    const int TYPE_MAX_SIZE{30};

    class Engine
    {
    private:
        double m_size{0.0};
        char m_type[TYPE_MAX_SIZE];

    public:
        Engine();
        Engine(const char *, double);

        double get() const;
        void display() const;
    };
} // namespace sdds

#endif // SDDS_ENGINE_H