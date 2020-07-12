/******************************************/
/*  Student:    Yathavan Parameshwaran    */
/*  Student #:  070 692 140               */
/*  Assignment: Workshop 6.2: Fruit.cpp   */
/*  Course:     OOP244 (retake)           */
/*  Professor:  Andrei Sajeniouk          */
/*  Date:       July 07, 2020             */
/*										  */
/*  Notes: Fruit object created by Prof.  */
/******************************************/

#ifndef FRUIT_H
#define FRUIT_H

namespace sdds
{
	const int NAME_SIZE{30};

	struct Fruit
	{
		char m_name[NAME_SIZE + 1]; // the name of the fruit
		double m_qty;				// quantity in kilograms
	};
} // namespace sdds

#endif // FRUIT_H
