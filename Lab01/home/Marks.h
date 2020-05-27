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
#include "Utils.h"

inline void markstat()
{
	std::cout << "Mark Stats Program" << std::endl;
	
}

namespace sdds
{
	class Marks
	{
	private:
		Utils utility;

		char *assessment_name{nullptr};
		int *marks_arr;
		double mark_average{0.0};
		int num_passing{0};
		int total_marks{0};
		int num_of_marks{0};
		int num_of_marks_stored{0};

		void sort_marks();

	public:
		Marks();
		Marks(const char *, int);
		~Marks();
		int getNumMarks() const;
		double getAverage();
		char *getAssessmentName() const;
		void addMark(int);
		void displayMarks(std::ostream&) const;
	};
	std::ostream &operator<<(std::ostream &, Marks &);
} // namespace sdds

#endif // SDDS_MARKS_H
