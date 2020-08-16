/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS6: Utils.h      */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       August 15, 2020                  */
/*************************************************/
/*************************************************/
/* I have done all the coding by myself and only */ 
/*  copied the code that my professor provided   */
/*  to complete this program.                    */
/*************************************************/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	struct Utils
	{
		bool sensitive_strncmp(const char* str_1, const char* str_2, int length);
		bool insensitive_strncmp(const char* str_1, const char* str_2, int length);

		const char* toUpperCase(const char* incoming_str);

		int get_pos(const char* incoming_str, char find, int iteration);
	};
}

#endif // SDDS_UTILS_H
