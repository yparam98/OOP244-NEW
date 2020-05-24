/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.1: Utils.h   */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	struct Utils
	{
		char ToLower(char);
		int StrCmp(const char *, const char *);
		void StrCpy(char *, const char *);
		int StrLen(const char *);
		bool isAlpha(char);
		void trim(char[]);
		void toLowerCaseAndCopy(char[], const char[]);
	};
} // namespace sdds

#endif // SDDS_UTILS_H
