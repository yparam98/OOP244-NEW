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
    std::string user_input = "";
    int num_of_marks = 0;
    int holder = 0;

    std::cout << "Mark Stats Program" << std::endl;

    std::cout << "\nPlease enter the assessment name: ";

    while (assessment_name == "")
    {
        try
        {
            std::getline(std::cin, assessment_name);
        }
        catch (...)
        {
            assessment_name = "";
            std::cout << "You have entered an invalid name... Please try again: ";
        }
    }

    std::cout << "Please enter the number of marks: ";
    std::cin >> user_input;
    std::cin.ignore(1000, '\n');
    while ((num_of_marks = utility.is_valid(user_input.c_str())) == -1)
    {
        std::cin >> user_input;
        std::cin.ignore(1000, '\n');
    }

    sdds::Marks marks_obj(assessment_name.c_str(), num_of_marks);

    std::cout << "Please enter " << marks_obj.getNumMarks() << " marks (0<=Mark<=100):" << std::endl;

    for (int i = 0; i < marks_obj.getNumMarks(); i++)
    {
        holder = 0;

        std::cout << i + 1 << "> ";

        while (holder == 0)
        {
            std::cin >> holder;
            std::cin.ignore(1000, '\n');
            if (holder < 0 || holder > 100)
            {
                std::cout << "Invalid value (0<=value<=100), try again: ";
                holder = 0;
            }
        }

        marks_obj.addMark(holder);
    }

    std::cout << "Thank you..." << std::endl;

    std::cout << marks_obj << std::endl;
}

// constructor
sdds::Marks::Marks()
{
}

// constructor that accepts the assessment name and number of marks
sdds::Marks::Marks(const char *incoming_assessment_name, int incoming_num_marks)
{
    this->num_of_marks = incoming_num_marks;
    this->assessment_name = new char[utility.str_size(incoming_assessment_name)];

    utility.str_copy(this->assessment_name, incoming_assessment_name);

    this->marks_arr = new int[incoming_num_marks];
}

// destructor, frees any previously allocated memory
sdds::Marks::~Marks()
{
    delete[] this->assessment_name;
    this->assessment_name = nullptr;
}

// return number of marks
int sdds::Marks::getNumMarks() const
{
    return this->num_of_marks;
}

// returns average of all marks stored in object
double sdds::Marks::getAverage()
{
    this->mark_average = utility.calculate_average(&this->marks_arr[0], this->num_of_marks_stored);
    return this->mark_average;
}

// returns number of marks with value above 50
int sdds::Marks::getPassing()
{
    calculate_passing();

    return this->num_passing;
}

// returns name of the assessment
char *sdds::Marks::getAssessmentName() const
{
    return this->assessment_name;
}

// adds mark to the object's array
void sdds::Marks::addMark(int incoming_mark)
{
    this->marks_arr[this->num_of_marks_stored++] = incoming_mark;
}

// internal function, calculates number of marks with values above 50
void sdds::Marks::calculate_passing()
{
    for (int index = 0; index < num_of_marks_stored; index++)
    {
        if (marks_arr[index] >= 50)
        {
            this->num_passing++;
        }
    }
}

// prints out all the marks after sorting it from least to greatest
void sdds::Marks::displayMarks(std::ostream &incoming_ostream_obj) const
{
    std::vector<int> sort_vector(this->marks_arr, this->marks_arr + num_of_marks_stored);
    std::sort(sort_vector.begin(), sort_vector.end());
    std::reverse(sort_vector.begin(), sort_vector.end());

    for (int index = 0; index < num_of_marks_stored; index++)
    {
        incoming_ostream_obj << sort_vector.at(index);
        incoming_ostream_obj << (index < num_of_marks_stored - 1 ? ", " : "");
    }

    incoming_ostream_obj << std::endl;
}

// ostream overload, prints the object in the format as defined in the specifications
std::ostream &sdds::operator<<(std::ostream &os, sdds::Marks &marks_obj)
{
    os << "Assessment Name: " << marks_obj.getAssessmentName() << std::endl;
    os << "----------------" << std::endl;
    marks_obj.displayMarks(os);
    os << "Average: " << std::fixed << std::setprecision(1) << marks_obj.getAverage() << std::endl;
    os << "Number of Passing Marks: " << marks_obj.getPassing() << std::endl;

    return os;
}