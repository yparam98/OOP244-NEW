/******************************************************/
/*  Student:    Yathavan Parameshwaran                */
/*  Student #:  070 692 140                           */
/*  Assignment: Final Project: MS6: ReadWritable.h    */
/*  Course:     OOP244 (retake)                       */
/*  Professor:  Andrei Sajeniouk                      */
/*  Date:       August 15, 2020                       */
/******************************************************/
/******************************************************/
/* I have done all the coding by myself and only      */ 
/*  copied the code that my professor provided        */
/*  to complete this program.                         */
/******************************************************/

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
	class ReadWritable
	{
		private:
			bool comma_seperated{false};
		public:
			ReadWritable();
			virtual ~ReadWritable();

			virtual std::istream& read(std::istream& is = std::cin) = 0;
			virtual std::ostream& write(std::ostream& os = std::cout) const = 0;

			bool isCsv() const;
			void setCsv(bool);
	};
	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw);
	std::istream& operator>>(std::istream& is, ReadWritable& rw);
}

#endif // SDDS_READWRITABLE_H
