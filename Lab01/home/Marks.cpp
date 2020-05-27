/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include "Marks.h"

sdds::Marks::Marks()
{
}

sdds::Marks::Marks(const char *incoming_assessment_name, int incoming_num_marks)
{
    this->num_of_marks = incoming_num_marks;
    this->assessment_name = new char[utility.str_size(incoming_assessment_name)];

    this->marks_arr = new int[incoming_num_marks];
}

sdds::Marks::~Marks()
{
    delete[] this->assessment_name;
    this->assessment_name = nullptr;
}

int sdds::Marks::getNumMarks() const
{
    return this->num_of_marks;
}

double sdds::Marks::getAverage()
{
    this->mark_average = utility.calculate_average(&this->marks_arr[0], this->num_of_marks_stored);
    return this->mark_average;
}

char *sdds::Marks::getAssessmentName() const
{
    return this->assessment_name;
}

void sdds::Marks::addMark(int incoming_mark)
{
    this->marks_arr[this->num_of_marks_stored++] = incoming_mark;
}

void sdds::Marks::sort_marks()
{
    for (int index = 0; index < num_of_marks_stored; index++)
    {
        if (marks_arr[index] >= 50)
        {
            this->num_passing++;
        }
    }
}

void sdds::Marks::displayMarks(std::ostream& incoming_ostream_obj) const
{
    for (int index = 0; index < num_of_marks_stored; index++)
    {
        incoming_ostream_obj << marks_arr[index] << ", ";
    }
}

std::ostream &sdds::operator<<(std::ostream &os, sdds::Marks &marks_obj)
{
    marks_obj.displayMarks(os);
    return os;
}
