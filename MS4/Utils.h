/**********************************************/
/*  Student:    Yathavan Parameshwaran        */
/*  Student #:  070 692 140                   */
/*  Assignment: Final Project: MS1: Utils.h   */
/*  Course:     OOP244 (retake)               */
/*  Professor:  Andrei Sajeniouk              */
/*  Date:       July 11, 2020                 */
/**********************************************/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    struct Utils
    {
        bool sensitive_strncmp(const char* str_1, const char* str_2, int length);
        bool insensitive_strncmp(const char* str_1, const char* str_2, int length);

        const char* toUpperCase(const char* incoming_str);
    };
}

#endif // SDDS_UTILS_H