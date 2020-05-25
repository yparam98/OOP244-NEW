/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H 

namespace sdds
{
	class Marks
	{
		private:
			char* assessment_name{""};
			int sorted_marks[];
			double mark_average{0.0};
			int num_passing{0};
			int total_marks{0};
		public:
			Marks();
			Marks(const char&, int);
			~Marks();
			int getNumMarks() const;
			int getAverage() const;
			void addMark(int);
	};
}

#endif // SDDS_MARKS_H
