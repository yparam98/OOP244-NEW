#include <iostream>
#include <cstring>
#include "Utils.h"

int main()
{
    char buffer[50];
    char* pos;
    char* license_plate;
    char* makemodel;

    sdds::Utils utility;

    std::cout << "Prompt: ";
    std::cin >> buffer;

    pos = new char[utility.get_pos(buffer, ',', 1)];
    std::memcpy(pos, &buffer[0], utility.get_pos(buffer, ',', 1));
    pos[utility.get_pos(buffer, ',', 1)] = '\0';

    license_plate = new char[(utility.get_pos(buffer, ',', 2) - utility.get_pos(buffer, ',', 1))];
    std::memcpy(license_plate, &buffer[utility.get_pos(buffer, ',', 1) + 1], ((utility.get_pos(buffer, ',', 2) - utility.get_pos(buffer, ',', 1)) - 1));
    license_plate[utility.get_pos(buffer, ',', 2)] = '\0';

    makemodel = new char[(utility.get_pos(buffer, ',', 3) - utility.get_pos(buffer, ',', 2))];
    std::memcpy(makemodel, &buffer[utility.get_pos(buffer, ',', 2) + 1], ((utility.get_pos(buffer, ',', 3) - utility.get_pos(buffer, ',', 2)) - 1));
    makemodel[utility.get_pos(buffer, ',', 3)] = '\0';

    std::cout << pos << std::endl;
    std::cout << license_plate << std::endl;
    std::cout << makemodel << std::endl;






    return 0;
}