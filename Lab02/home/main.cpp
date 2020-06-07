/***********************************************************************
// Workshop 2: Dynamic Memory & Function Overloading
// Version 2.0
// Date	2020/05/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Gift.h"
#include "Gift.h" // intentional
using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(40);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(40);
	cout << "" << endl;
	cout.fill(oldFill);
}

int main() {

	Gift g1; // Unwrapped Gift

	{
		printHeader("T1: Checking Constants");

		cout << "MAX_DESC: " << sdds::MAX_DESC << endl;
		cout << "MAX_PRICE: " << sdds::MAX_PRICE << endl;
		cout << "MAX_WRAP: " << sdds::MAX_WRAP << endl;
		cout << endl;
	}

	{
		printHeader("T2: Display Wrapped Gift");

		gifting(g1.m_description);
		gifting(g1.m_price);
		gifting(g1.m_units);
		cout << endl;

		g1.m_wrap = nullptr;
		g1.m_wrapLayers = 0;
		display(g1);
		cout << endl;
	}

	{
		printHeader("T3: Wrap a gift");

		if (wrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: wrapping didn't happen!" << endl;
		cout << endl << endl;
	}

	{
		printHeader("T4: Re-wrap a gift");
		
		cout << "Attempting to rewrap the previous Gift: "
		     << g1.m_description << endl;

		if (wrap(g1) == false)
			cout << "Test succeeded!";
		else
			cout << "Test failed: gift it's already wrapped, cannot wrap again!";
		cout << endl << endl;
	}

	{
		printHeader("T5: Unwrap a gift");

		cout << "Attempting to unwrap the previous gift: "
		     << g1.m_description << endl;
		if (unwrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: you should be able to unwrap!";
		cout << endl << endl;
	}


	{
		printHeader("T6: Unwrap again");

		cout << "Attempting to un-unwrap the previous gift: "
		     << g1.m_description << endl;

		if (!unwrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: you should not be able to unwrap again!";
		cout << endl << endl;
	}

	Gift g2; // Unwrapped Gift
	{
		printHeader("T7: Prepare another gift");
		g2.m_wrap = nullptr;
		g2.m_wrapLayers = 0;
		gifting(g2);
		
		cout << endl;
		display(g2);
		cout << endl;
	}

	{
		printHeader("T8: Unwrap the second gift");

		unwrap(g2);
	}

	return 0;
}
