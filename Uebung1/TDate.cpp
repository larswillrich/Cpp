/*
 * TDate.cpp
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */
#include "TDate.h"
#include <time.h>
#include <stdio.h>

TDate::TDate() {
	time_t rawTime;
	struct tm *ts;

	rawTime = time(NULL);
	ts = localtime(&rawTime);

	setDay(ts->tm_mday);
	setMonth(ts->tm_mon + 1);
	setYear(ts->tm_year + 1900);
}

TDate::TDate(int day, int month, int year){
	setDay(day);
	setMonth(month);
	setYear(year);
}

int TDate::getDay() const
{
    return day;
}

void TDate::setDay(int day)
{
    this->day = day;
}

int TDate::getMonth() const
{
    return month;
}

void TDate::setMonth(int month)
{
    this->month = month;
}

int TDate::getYear() const
{
    return year;
}

void TDate::setYear(int year)
{
    this->year = year;
}

void TDate::print(){
	printf("%.2i.%.2i.%.2i", getDay(), getMonth(), getYear());
}

TDate::~TDate() {
}
