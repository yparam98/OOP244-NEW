/********************************************/
/*  Student:    Yathavan Parameshwaran      */
/*  Student #:  070 692 140                 */
/*  Assignment: Workshop 8.1: Employee.h    */
/*  Course:     OOP244 (retake)             */
/*  Professor:  Andrei Sajeniouk            */
/*  Date:       July 22, 2020               */
/********************************************/

#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>

namespace sdds
{
	class Employee
	{
	private:
		const int min_work_hrs{0};
		double hourly_salary_rate{0.0};

	protected:
		int get_min_hours() const;
		double get_hourly_rate() const;

	public:
		Employee(double, int);
		virtual ~Employee();
		virtual double getSalary(int) const = 0;
		virtual std::ostream &display(std::ostream & = std::cout) const = 0;
	};
	std::ostream &operator<<(std::ostream &, Employee &);
} // namespace sdds

#endif // SDDS_EMPLOYEE_H
