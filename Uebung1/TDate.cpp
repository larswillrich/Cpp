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

	TDate(ts->tm_mday,ts->tm_mon,ts->tm_year);
}

TDate::TDate(int day, int month, int year){
	this->day = day;
	this->month = month;
	this->year = year;

	printf("Aktuelles Datum: %.2i.%.2i.%.2i", day, month+1, 1900+year);
}

TDate::~TDate() {
}


int main(){
	new TDate();
}
