/************************************************/
/*  Student:    Yathavan Parameshwaran          */
/*  Student #:  070 692 140                     */
/*  Assignment: Final Project: MS4: Vehicle.cpp */
/*  Course:     OOP244 (retake)                 */
/*  Professor:  Andrei Sajeniouk                */
/*  Date:       August 11, 2020                 */
/************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include "Vehicle.h"

namespace sdds
{
	Vehicle::Vehicle()
	{
		this->license_plate = nullptr;
		this->make_model = nullptr;
		this->spot = 0;
	}

	Vehicle::~Vehicle()
	{
		if (this->license_plate != nullptr)
		{
			delete[] this->license_plate;
			this->license_plate = nullptr;
		}

		if (this->make_model != nullptr)
		{
			delete[] this->make_model;
			this->make_model = nullptr;
		}
	}

	Vehicle::Vehicle(const char* incoming_license_plate, const char* incoming_make_model)
	{
		if (incoming_license_plate != nullptr && incoming_make_model != nullptr)
		{
			if (std::strlen(incoming_license_plate) >= 1 && std::strlen(incoming_license_plate) <= 8 && std::strlen(incoming_make_model) >= 2)
			{
				int size = std::strlen(incoming_license_plate) <= MAX_LICENSE_PLATE ? std::strlen(incoming_license_plate) : MAX_LICENSE_PLATE;

				this->license_plate = new char[size + 1];
				std::strncpy(this->license_plate, incoming_license_plate, size);
				this->license_plate[size] = '\0';

				this->setMakeModel(incoming_make_model);
			}
			else
			{
				this->spot = 0;
				this->license_plate = nullptr;
				this->make_model = nullptr;
			}
		}
		else
		{
			this->spot = 0;
			this->license_plate = nullptr;
			this->make_model = nullptr;
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return this->spot;
	}

	void Vehicle::setParkingSpot(int incoming_spot)
	{
		this->spot = incoming_spot;
	}

	std::istream& Vehicle::read(std::istream& is)
	{
		if (this->isCsv()) // if comma seperated values // valgrind problem most likely in this if statement
		{
			char pos[50], lp[50], mm[50];

			// sample input:
			// 123,abcd,abcd, <-- comma at end!

			is.get(pos, 50, ',');
			is.ignore(50, ',');
			is.get(lp, 50, ',');
			is.ignore(50, ',');
			is.get(mm, 50, ',');
			is.ignore(50, ',');

			this->setParkingSpot(std::atoi(pos));

			if (this->license_plate != nullptr)
			{
				delete[] this->license_plate;
				this->license_plate = nullptr;
			}
			this->license_plate = new char[std::strlen(lp) + 1];
			std::strncpy(this->license_plate, this->utility_obj.toUpperCase(lp), std::strlen(lp));
			this->license_plate[std::strlen(lp)] = '\0';

			this->setMakeModel(mm);

			// // char* license_plate_holder;

			// is.getline(buffer, 100, '\n');
			// // is.read(buffer, 100);

			// // get parking position (first store in temp ptr, then copy it over to the real thing)
			// std::memcpy(pos, &buffer[0], this->utility_obj.get_pos(buffer, ',', 1));
			// pos[this->utility_obj.get_pos(buffer, ',', 1)] = '\0';

			// this->setParkingSpot(std::atoi(pos));


			// // get license plate (first in a temp ptr, then copy it over to the real thing)			
			// if (this->getLicensePlate() != nullptr)
			// {
			// 	delete[] this->license_plate;
			// 	this->license_plate = nullptr;
			// }

			// // license_plate_holder = new char[(this->utility_obj.get_pos(buffer, ',', 2) - this->utility_obj.get_pos(buffer, ',', 1))];
			// char license_plate_holder[50];
			// std::memcpy(
			// 	license_plate_holder,
			// 	&buffer[this->utility_obj.get_pos(buffer, ',', 1) + 1],
			// 	((this->utility_obj.get_pos(buffer, ',', 2) - this->utility_obj.get_pos(buffer, ',', 1)) - 1)
			// );
			// license_plate_holder[(this->utility_obj.get_pos(buffer, ',', 2) - this->utility_obj.get_pos(buffer, ',', 1)) - 1] = '\0';

			// this->license_plate = new char[std::strlen(license_plate_holder) + 1];
			// std::strncpy(
			// 	this->license_plate,
			// 	this->utility_obj.toUpperCase(license_plate_holder),
			// 	((std::strlen(license_plate_holder) < 8) ? std::strlen(license_plate_holder) : 8)
			// );
			// this->license_plate[std::strlen(license_plate_holder)] = '\0';


			// // get make and model from the buffer, store it in a temp array, then store it in the real thing			
			// if (this->make_model != nullptr)
			// {
			// 	delete[] this->make_model;
			// 	this->make_model = nullptr;
			// }

			// int makemodelsize = (this->utility_obj.get_pos(buffer, ',', 3) - this->utility_obj.get_pos(buffer, ',', 2));
			// this->make_model = new char[makemodelsize + 1];
			// std::memcpy(
			// 	this->make_model,
			// 	&buffer[this->utility_obj.get_pos(buffer, ',', 2) + 1],
			// 	(makemodelsize - 1)
			// );
			// this->make_model[makemodelsize - 1] = '\0';

			// // is.putback(buffer[this->utility_obj.get_pos(buffer, ',', 3) + 1]);
			// is.unget();
		}
		else // if not comma seperated values
		{
			char buffer[100];

			// user input for license plate
			std::cout << "Enter Licence Plate Number: ";
			is >> buffer;

			while (std::strlen(buffer) > MAX_LICENSE_PLATE)
			{
				is.ignore(1000, '\n');
				std::cout << "Invalid Licence Plate, try again: ";
				is >> buffer;
			}

			if (this->license_plate != nullptr)
			{
				delete[] this->license_plate;
				this->license_plate = nullptr;
			}

			this->license_plate = new char[MAX_LICENSE_PLATE + 1];
			std::strncpy(this->license_plate, this->utility_obj.toUpperCase(buffer), MAX_LICENSE_PLATE);
			this->license_plate[MAX_LICENSE_PLATE] = '\0';

			// make and model input
			char* holder = new char[60];
			std::cout << "Enter Make and Model: ";
			is.ignore(1000, '\n');
			is.getline(holder, 60, '\n');

			while (std::strlen(holder) < 2 || std::strlen(holder) > 60)
			{
				is.ignore(1000, '\n');
				std::cout << "Invalid Make and model, try again: ";
				is.getline(holder, 20, '\n');
			}

			this->setMakeModel(holder);
			delete[] holder;
			this->setParkingSpot(0);
		}

		return is;
	}

	std::ostream& Vehicle::write(std::ostream& os) const
	{
		if (this->isEmpty()) // if object is empty/invalid
		{
			os << "Invalid Vehicle Object" << std::endl;
		}
		else // if object is valid & not empty
		{
			if (this->isCsv()) // if comma seperated mode
			{
				char comma = ',';

				os << this->getParkingSpot();
				os << comma;
				os << this->license_plate;
				os << comma;
				os << this->make_model;
				os << comma;
			}
			else // if NOT comma seperated mode
			{
				os << "\nParking Spot Number: ";
				if (this->getParkingSpot() == 0)
					os << "N/A" << std::endl;
				else
					os << this->getParkingSpot() << std::endl;

				os << "Licence Plate: " << this->getLicensePlate() << std::endl;
				os << "Make and Model: " << this->getMakeModel() << std::endl;
			}
		}

		return os;
	}

	bool operator==(const Vehicle& incoming_obj, const char* incoming_license_plate)
	{
		sdds::Utils utility;
		return utility.insensitive_strncmp(incoming_obj.getLicensePlate(), incoming_license_plate, std::strlen(incoming_license_plate));
	}

	bool operator==(const Vehicle& obj1, const Vehicle& obj2)
	{
		sdds::Utils utility;
		return utility.insensitive_strncmp(obj1.getLicensePlate(), obj2.getLicensePlate(), std::strlen(obj1.getLicensePlate()));
	}

	void Vehicle::setEmpty()
	{
		this->spot = 0;

		if (this->make_model != nullptr)
		{
			delete[] this->make_model;
			this->make_model = nullptr;
		}

		if (this->license_plate != nullptr)
		{
			delete[] this->license_plate;
			this->license_plate = nullptr;
		}
	}

	bool Vehicle::isEmpty() const
	{
		return (this->license_plate == nullptr || this->make_model == nullptr || this->spot < 0);
	}

	const char* Vehicle::getLicensePlate() const
	{
		if (this->license_plate != nullptr)
		{
			return this->license_plate;
		}
		else
		{
			return "";
		}
	}

	const char* Vehicle::getMakeModel() const
	{
		return this->make_model;
	}

	void Vehicle::setMakeModel(const char* incoming_str)
	{
		if (incoming_str != nullptr)
		{
			if (this->make_model != nullptr)
			{
				delete[] this->make_model;
				this->make_model = nullptr;
			}

			this->make_model = new char[std::strlen(incoming_str) + 1];
			std::strncpy(this->make_model, incoming_str, std::strlen(incoming_str));
			this->make_model[std::strlen(incoming_str)] = '\0';
		}
		else
		{
			this->setEmpty();
		}

	}
}
