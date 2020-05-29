/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Utils.h"

void markstat();

namespace sdds
{
	class Marks
	{
	private:
		char *assessment_name{nullptr};
		int *marks_arr;
		double mark_average{0.0};
		int num_passing{0};
		int total_marks{0};
		int num_of_marks{0};
		int num_of_marks_stored{0};

		void calculate_passing();

	public:
		Marks();
		Marks(const char *, int);
		~Marks();
		int getNumMarks() const;
		double getAverage();
		int getPassing();
		char *getAssessmentName() const;
		void addMark(int);
		void displayMarks(std::ostream &) const;
	};
	std::ostream &operator<<(std::ostream &, Marks &);
} // namespace sdds

#endif // SDDS_MARKS_H
