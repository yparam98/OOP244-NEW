/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.1: Word.h    */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds
{
	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;
	const int SOFT_BY_OCCURANCE = 1;
	const int SOFT_ALPHABETICALLY = 0;

	struct Word
	{
		char letter[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word, int, const char[]);
	void addWord(Word[], int *, const char[]);
	void title(const char *, int);
	void endList();
	void totalWordsStat(int, int, int);
	void print(const Word *, bool, int);
	int findMaxLen(const Word[], int);
	void listWords(const Word[], int, const char *);
	void swap(Word *, Word *);
	void sort(Word[], int, int);
	int totalCount(const Word *, int);
	void wordStats();
	void programTitle();
} // namespace sdds

#endif // SDDS_WORD_H
