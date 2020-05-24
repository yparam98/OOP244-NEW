/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.1: Word.cpp  */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include <iostream>
#include <iomanip>

#include "Word.h"

int sdds::searchWords(const Word words[], int num, const char word[])
{
    int i;
    int foundIndex = -1; // will be set to found index; if not found sould be less than 0
    for (i = 0; foundIndex == -1 && i < num; i++)
    { // while not found and i is less than number of words
        if (utils.StrCmp(words[i].letters, word) == 0)
        {                   // if word is already read and found in the list of previous words
            foundIndex = i; // set the index to be returned.
        }
    }
    return foundIndex;
}

void sdds::addWord(Word words[], int *index, const char newWord[])
{
    utils.StrCpy(words[*index].letters, newWord);
    words[*index].count++;
    (*index)++;
}

void sdds::title(const char *value, int len)
{
    std::cout << value << std::endl;
    std::cout << std::setw(len) << std::left << "Word";
    std::cout << "No of  occurrence." << std::endl
              << "------------------------------------------------" << std::endl;
}

void sdds::endList()
{
    std::cout << "------------------------------------------------" << std::endl;
}

void sdds::totalWordsStat(int total_no_words, int total_over_all, int longest_word)
{
    std::cout << "Total number of words used: " << total_no_words << std::endl;
    std::cout << "Total number of words overall: " << total_over_all << std::endl;
    std::cout << "Longest word used had " << longest_word << " characters." << std::endl;
}

void sdds::print(const Word *word, bool goToNextLine, int len)
{
    std::cout << std::setw(len) << std::left << word->letters;
    std::cout << std::setw(3) << std::right << word->count;

    if (goToNextLine)
    {
        std::cout << std::endl;
    }
}

int sdds::findMaxLen(const Word words[], int numOfWords)
{
    int longest = 0;
    int i;

    for (i = 0; i < numOfWords; i++)
    {
        if (longest < utils.StrLen(words[i].letters))
        {
            longest = utils.StrLen(words[i].letters);
        }
    }

    return longest;
}

void sdds::listWords(const Word words[], int numOfWords, const char *the_title)
{
    int i;
    int maxLen = findMaxLen(words, numOfWords);

    title(the_title, maxLen);

    for (i = 0; i < numOfWords; i++)
    {
        print(&words[i], true, maxLen);
    }

    endList();
}

void sdds::swap(Word *p1, Word *p2)
{
    Word w;
    w = *p1;
    *p1 = *p2;
    *p2 = w;
}

void sdds::sort(Word words[], int count, int sortType)
{
    int i, j;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (sortType == sdds::SOFT_BY_OCCURANCE)
            {
                if (words[j].count < words[j + 1].count)
                {
                    swap(&words[j], &words[j + 1]);
                }
            }
            else if (sortType == sdds::SOFT_ALPHABETICALLY)
            {
                if (utils.StrCmp(words[j].letters, words[j + 1].letters) > 0)
                {
                    swap(&words[j], &words[j + 1]);
                }
            }
            else
            {
            }
        }
    }
}

int sdds::totalCount(const Word *words, int num)
{
    int total = 0;

    do
    {
        total += words[--num].count;
    } while (num);

    return total;
}

void sdds::wordStats()
{
    Word words[MAX_NO_OF_WORDS] = {{"", 0}};
    char word[MAX_WORD_LEN];
    char lowerCaseWord[MAX_WORD_LEN];
    int NoOfWords = 0;
    int maxLen = 0;
    int foundIndex = 0;
    int wordCount = 0;

    while (std::cin >> word)
    {
        utils.trim(word);
        utils.toLowerCaseAndCopy(lowerCaseWord, word);
        if (lowerCaseWord[0] != 0)
        {
            wordCount++;
            if (maxLen < utils.StrLen(lowerCaseWord))
            {
                maxLen = utils.StrLen(lowerCaseWord);
            }
            if (NoOfWords == 0)
            {
                addWord(words, &NoOfWords, lowerCaseWord);
            }
            else
            {
                foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                if (foundIndex < 0)
                { // word not found in list; so word is new and never read before
                    foundIndex = NoOfWords;
                    addWord(words, &NoOfWords, lowerCaseWord);
                }
                else
                {
                    words[foundIndex].count++;
                }
            }
        }
    }

    std::cout << "---------------------------------------------------" << std::endl
              << "Read " << wordCount << " words!" << std::endl
              << "---------------------------------------------------" << std::endl;

    sort(words, NoOfWords, 1);
    listWords(words, NoOfWords, "List of words Sorted by occurance");
    sort(words, NoOfWords, 0);
    listWords(words, NoOfWords, "List of words Sorted alphabetically");
    totalWordsStat(NoOfWords, totalCount(words, NoOfWords), maxLen);
}

void sdds::programTitle()
{
    std::cout << "This program reads a text file from the standard input and analyzes and reports" << std::endl
              << "the number of words and their occurrences in the text file." << std::endl;
}