/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.2            */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	class Utils
	{
	private:
		int validation_num{0};

	public:
		Utils();
		~Utils();
		int str_size(const char *);
		bool str_copy(char *, const char *);
		double calculate_average(int *, int);
		int is_valid(const char *);
	};
} // namespace sdds

#endif // SDDS_MARKS_H