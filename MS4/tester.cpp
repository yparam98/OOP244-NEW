#include <iostream>
#include "Utils.h"

int main()
{
    sdds::Utils utils;

    char name1[] = "Yathavan";
    char name2[] = "YaThAvAn";

    char pizza1[] = "pizza";
    char pizza2[] = "Pizza";

    {
        std::cout << "Testing sensitive comparison" << std::endl;

        std::cout << name1 << " vs " << name2 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(name1, name2, 8) << std::endl;

        std::cout << name1 << " vs " << name1 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(name1, name1, 8) << std::endl;

        std::cout << name2 << " vs " << name2 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(name2, name2, 8) << std::endl;

        std::cout << pizza1 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(pizza1, pizza2, 8) << std::endl;

        std::cout << pizza1 << " vs " << pizza1 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(pizza1, pizza1, 8) << std::endl;

        std::cout << pizza2 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.sensitive_strncmp(pizza2, pizza2, 8) << std::endl;
    }

    {
        std::cout << "Testing insensitive comparison" << std::endl;

        std::cout << name1 << " vs " << name2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name1, name2, 8) << std::endl;

        std::cout << name1 << " vs " << name1 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name1, name1, 8) << std::endl;

        std::cout << name2 << " vs " << name2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name2, name2, 8) << std::endl;

        std::cout << pizza1 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(pizza1, pizza2, 8) << std::endl;

        std::cout << pizza1 << " vs " << pizza1 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(pizza1, pizza1, 8) << std::endl;

        std::cout << pizza2 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(pizza2, pizza2, 8) << std::endl;

        std::cout << name1 << " vs " << pizza1 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name1, pizza1, 5) << std::endl;

        std::cout << name1 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name1, pizza2, 5) << std::endl;

        std::cout << name2 << " vs " << pizza1 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name2, pizza1, 5) << std::endl;

        std::cout << name2 << " vs " << pizza2 << std::endl;
        std::cout << "Match = " << utils.insensitive_strncmp(name2, pizza2, 5) << std::endl;
    }

    {
        std::cout << "To Uppercase" << std::endl;

        std::cout << name1 << " to upper case" << std::endl;
        std::cout << utils.toUpperCase(name1) << std::endl;

        std::cout << name2 << " to upper case" << std::endl;
        std::cout << utils.toUpperCase(name2) << std::endl;

        std::cout << pizza1 << " to upper case" << std::endl;
        std::cout << utils.toUpperCase(pizza1) << std::endl;

        std::cout << pizza2 << " to upper case" << std::endl;
        std::cout << utils.toUpperCase(pizza2) << std::endl;
    }



    return 0;
}