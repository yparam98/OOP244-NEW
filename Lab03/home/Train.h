/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.2: Train.h    */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include "Cargo.h"

namespace sdds
{
	const int MAX_NAME{30};

	class Train
	{
	private:
		char train_name[MAX_NAME];
		int train_id{0};
		Cargo *train_cargo{nullptr};

	public:
		Train();
		~Train();

		void initialize(const char *, int);
		bool isValid() const;
		void loadCargo(Cargo);
		void unloadCargo();
		void display() const;

		bool swapCargo(Train&);
		bool increaseCargo(double);
		bool decreaseCargo(double);
	};
} // namespace sdds

#endif // SDDS_TRAIN_H
