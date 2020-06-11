/*****************************************/
/*  Student:    Yathavan Parameshwaran   */
/*  Student #:  070 692 140              */
/*  Assignment: Workshop 3.2: Cargo.cpp  */
/*  Course:     OOP244 (retake)          */
/*  Professor:  Nathan Misener           */
/*  Date:       June 10, 2020            */
/*****************************************/

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	const int MAX_DESC{20};
	const double MAX_WEIGHT{777.555};
	const double MIN_WEIGHT{44.2222};

	class Cargo
	{
	private:
		char description[MAX_DESC];
		double weight{0.0};
	public:
		Cargo();
		~Cargo();

		void initialize(const char*, double);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char*);
		void setWeight(double);
	};

} // namespace sdds

#endif // SDDS_CARGO_H
