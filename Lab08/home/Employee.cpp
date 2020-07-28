/********************************************/
/*  Student:    Yathavan Parameshwaran      */
/*  Student #:  070 692 140                 */
/*  Assignment: Workshop 8.2: Employee.cpp  */
/*  Course:     OOP244 (retake)             */
/*  Professor:  Andrei Sajeniouk            */
/*  Date:       July 27, 2020               */
/********************************************/

#include <iostream>
#include "Employee.h"

namespace sdds
{
	Employee::Employee(double salary, int min_hrs) : min_work_hrs{min_hrs}
	{
		this->hourly_salary_rate = salary;
	}

	Employee::~Employee()
	{
	}

	int Employee::get_min_hours() const
	{
		return this->min_work_hrs;
	}
	double Employee::get_hourly_rate() const
	{
		return this->hourly_salary_rate;
	}

	std::ostream &operator<<(std::ostream &os, Employee &employee)
	{
		return employee.display(os);
	}
} // namespace sdds
