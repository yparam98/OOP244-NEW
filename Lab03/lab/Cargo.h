/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.1: Cargo.cpp  */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	const int MAX_DESC{20};
	struct Cargo
	{
		char description[MAX_DESC];
		double weight;
	};

} // namespace sdds

#endif // SDDS_CARGO_H
