/**
 * Programm: Es wird ein Datum eingegeben, es soll herausgefunden werden der wievielte Tag des Jahres das Datum ist
 * Autor: Lukas Alte-Bornholt
 * Datum: 18.12.2018
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "timelib.h"


int day_of_the_year(int day, int month, int year)
{   ///Es wird herausgefunden, den wievielten Tag in dem eingegeben Jahr das Datum hat
    int sum = 0;

    if(!exists_date(day, month, year))
    {
        return 0;
    }
    ///getdaysformonth(month, year);
    for(int i = 1; i < month; i++)
    {
        sum += getdaysformonth(i, year);
    }
    sum+= day;

    return sum;///Zur�ckgeben des Ergebnisses;
}

int getdaysformonth(int month, int year)
{   ///Es werden die Anzahl der Tage zur�ckgegeben, die der jeweilige Monat hat
    int daysofmonth[13];///Definition der Tage im Monat

    daysofmonth[1] = 31;
    daysofmonth[2] = 28;
    daysofmonth[3] = 31;
    daysofmonth[4] = 30;
    daysofmonth[5] = 31;
    daysofmonth[6] = 30;
    daysofmonth[7] = 31;
    daysofmonth[8] = 31;
    daysofmonth[9] = 30;
    daysofmonth[10] = 31;
    daysofmonth[11] = 30;
    daysofmonth[12] = 31;

    if(is_leapyear(year) && month == 2)
        daysofmonth[2]++;

    return daysofmonth[month];
}

bool exists_date(int day, int month, int year)
{   ///Es wird �berpr�ft, ob das eingegebene Datum existiert
    if(day <= 31 && day >= 1)
    {
        if(month <= 12 && month >= 1)
        {
            if(year >= 1582 && year <= 2400)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool is_leapyear(int year)
{   ///Es wird gepr�ft, ob es sich bei dem eingegebenen Datum um ein Schaltjahr handelt
    if(year < 1582 || year > 2400)
    {
        return -1;
    }
    if(year%4 == 0)
    {
        if(year%100 == 0)
        {
            if(year%400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
           return true;
        }
    }
    else
    {
        return false;
    }
}