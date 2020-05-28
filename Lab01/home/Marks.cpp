/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include "Marks.h"

sdds::Utils utility;

extern void markstat()
{
    std::string assessment_name = "";
    std::string error_msg = "";
    int num_of_marks = 0;
    int holder = 0;

    std::cout << "Mark Stats Program" << std::endl;

    std::cout << "Please enter the assessment name: ";

    while (assessment_name == "")
    {
        try
        {
            std::cin >> assessment_name;
        }
        catch (...)
        {
            assessment_name = "";
            std::cout << "You have entered an invalid name... Please try again: ";
        }
    }

    std::cout << "Please enter the number of marks: ";
    std::cin << num_of_marks;

    

    sdds::Marks marks_obj(assessment_name.c_str(), num_of_marks);

    std::cout << "Please enter " << marks_obj.getNumMarks() << " marks (0<=Mark<=100):" << std::endl;

    for (int i = 0; i < num_of_marks; i++)
    {
        holder = 0;

        std::cout << i + 1 << " > ";

        while (holder == 0)
        {
            try
            {
                std::cin >> holder;
                if (holder < 0 || holder > 100)
                {
                    throw 1;
                }
            }
            catch (...)
            {
                std::cout << "Invalid value (0<=value<=100), try again: ";
            }
        }

        marks_obj.addMark(holder);
    }

    std::cout << "Thank you..." << std::endl;

    std::cout << "Assessment Name: " << marks_obj.getAssessmentName() << std::endl;

    std::cout << "----------------" << std::endl;

    std::cout << marks_obj << std::endl;

    std::cout << "Average: " << marks_obj.getAverage() << std::endl;

    std::cout << "Number of Passing Marks: " << marks_obj.getPassing() << std::endl;
}

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

int sdds::Marks::getPassing()
{
    sort_marks();

    return this->num_passing;
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

void sdds::Marks::displayMarks(std::ostream &incoming_ostream_obj) const
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
