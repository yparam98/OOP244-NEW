/****************************************/
/*  Student:    Yathavan Parameshwaran  */
/*  Assignment: Workshop 1.1: Utils.cpp */
/*  Course:     OOP244 (retake)         */
/*  Professor:  Nathan Misener          */
/*  Date:       May 24, 2020            */
/****************************************/

#include <iostream>
#include "Utils.h"

char sdds::Utils::ToLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += ('a' - 'A');
    }

    return ch;
}

int sdds::Utils::StrCmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++)
        ;

    return s1[i] - s2[i];
}

void sdds::Utils::StrCpy(char *des, const char *src)
{
    int i;

    for (i = 0; src[i]; i++)
    {
        des[i] = src[i];
    }

    des[i] = 0;
}

int sdds::Utils::StrLen(const char *str)
{
    int len;

    for (len = 0; str[len]; len++)
        ;

    return len;
}

bool sdds::Utils::isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void sdds::Utils::trim(char word[])
{
    int i;

    while (word[0] && !isAlpha(word[0]))
    {
        StrCpy(word, word + 1);
    }

    i = StrLen(word);

    while (i && !isAlpha(word[i - 1]))
    {
        word[i-- - 1] = 0;
    }
}

void sdds::Utils::toLowerCaseAndCopy(char des[], const char src[])
{
    int i = 0, j = 0;

    for (; src[i] != 0; i++)
    {
        des[j++] = ToLower(src[i]);
    }

    des[j] = 0;
}