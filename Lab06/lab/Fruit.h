#ifndef FRUIT_H
#define FRUIT_H

const int NAME_SIZE{30};

struct Fruit
{
	char m_name[NAME_SIZE + 1]; // the name of the fruit
	double m_qty;		 // quantity in kilograms
};

#endif // FRUIT_H
