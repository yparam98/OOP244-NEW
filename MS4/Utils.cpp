/**********************************************/
/*  Student:    Yathavan Parameshwaran        */
/*  Student #:  070 692 140                   */
/*  Assignment: Final Project: MS1: Utils.cpp */
/*  Course:     OOP244 (retake)               */
/*  Professor:  Andrei Sajeniouk              */
/*  Date:       July 11, 2020                 */
/**********************************************/

#include <iostream>
#include <cstring>
#include <cctype>

#include "Utils.h"

namespace sdds
{
    bool Utils::sensitive_strncmp(const char* str_1, const char* str_2, int length)
    {
        bool match = false;

        for (int index = 0; index < length; index++)
        {
            int ascii_str_1 = (int)str_1[index];
            int ascii_str_2 = (int)str_2[index];

            if (ascii_str_1 > 65 && ascii_str_1 < 90) // str_1[index] is uppercase
            {
                if (ascii_str_2 > 65 && ascii_str_2 < 90) // str_2[index] is uppercase
                {
                    match = (ascii_str_1 == ascii_str_2);
                }
                else if (ascii_str_2 > 97 && ascii_str_2 < 122) // str_2[index] is lowercase
                {
                    match = (ascii_str_1 + 32 == ascii_str_2);
                }
            }
            else if (ascii_str_1 > 97 && ascii_str_1 < 122) // str_1[index] is lowercase
            {
                if (ascii_str_1 > 65 && ascii_str_1 < 90) // str_1[index] is uppercase
                {
                    match = (ascii_str_2 - 32 == ascii_str_1);
                }
                else if (ascii_str_1 > 97 && ascii_str_1 < 122) // str_1[index] is lowercase
                {
                    match = (ascii_str_2 == ascii_str_1);
                }
            }
            else if (std::isdigit(str_1[index])) // if str_1[index] is a digit
            {
                match = str_1[index] == str_2[index];
            }

            if (match == false)
            {
                break;
            }
        }

        return match;
    }

    bool Utils::insensitive_strncmp(const char* str_1, const char* str_2, int length)
    {
        bool match = false;

        for (int index = 0; index < length; index++)
        {
            int ascii_str_1 = (int)str_1[index];
            int ascii_str_2 = (int)str_2[index];

            if (ascii_str_1 >= 65 && ascii_str_1 <= 90) // str_1[index] is uppercase
            {
                match = ((ascii_str_1 == ascii_str_2) || (ascii_str_1 + 32 == ascii_str_2));
            }
            else if (ascii_str_1 >= 97 && ascii_str_1 <= 122) // str_1[index] is lowercase
            {
                match = ((ascii_str_1 == ascii_str_2) || (ascii_str_2 - 32 == ascii_str_2));
            }
            else if (std::isdigit(str_1[index])) // if str_1[index] is a digit
            {
                match = str_1[index] == str_2[index];
            }

            if (match == false)
            {
                break;
            }
        }

        return match;
    }

    const char* Utils::toUpperCase(const char* incoming_str)
    {
        char* upper_case_str = new char[std::strlen(incoming_str) + 1];

        for (int index = 0; index < std::strlen(incoming_str); index++)
        {
            int ascii_str = (int)incoming_str[index];

            if (ascii_str >= 65 && ascii_str <= 90) // incoming_str[index] is uppercase
            {
                upper_case_str[index] = incoming_str[index];
            }
            else if (ascii_str >= 97 && ascii_str <= 122) // incoming_str[index] is lowercase
            {
                upper_case_str[index] = (char)(ascii_str - 32);
            }
            else if (std::isdigit(incoming_str[index])) // if incoming_str[index] is a digit
            {
                upper_case_str[index] = incoming_str[index];
            }
        }

        upper_case_str[std::strlen(incoming_str)] = '\0';

        return upper_case_str;
    }
}