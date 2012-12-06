/*
 * TDate.cpp
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */
#include "TDate.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
TDate::TDate() {
	time_t rawTime;
	struct tm *ts;

	rawTime = time(NULL);
	ts = localtime(&rawTime);

	setDate(ts->tm_mday, ts->tm_mon + 1, ts->tm_year + 1900);
}

TDate::TDate(int day, int month, int year) {
	int res = setDate(day, month, year);

	if (res != 0) {
		setDate(01, 01, 1990);
		printf(
				"Eingegebenes Datum ist invalide, Eingabe wurde auf 01.01.1990 gesetzt.\n");
	}
}

int TDate::setDate(int day, int month, int year) {

	//Schaltjahr? Ja
	if (year % 4 == 0) {
		if (month == 2 && day > 29)
			return -1;
	}

	//Schaltjahr? Nein
	else if (month == 2 && day > 28)
		return -1;

	if (month > 12)
		return -1;
	//Monate bis einschl. Juli
	if (month < 8) {
		if (month % 2 == 0 && day > 30)
			return -1;
		if (month % 2 != 0 && day > 31)
			return -1;
	}

	//Monate von einschl. August
	if (month > 7) {
		if (month % 2 == 0 && day > 31)
			return -1;
		if (month % 2 != 0 && day > 30)
			return -1;
	}

	this->year = year;
	this->month = month;
	this->day = day;

	return 0;
}

int TDate::getDay() const {
	return day;
}

int TDate::getMonth() const {
	return month;
}

int TDate::getYear() const {
	return year;
}

std::string TDate::toString() {
	char buffer[10];
	sprintf(buffer, "%02i.%02i.%04i", getDay(), getMonth(), getYear());

	std::string ret = buffer;
	return ret;
}

void TDate::print() {
	printf("%02i.%02i.%04i", getDay(), getMonth(), getYear());
}

TDate::~TDate() {
}

std::ostream& operator<<(std::ostream & out, TDate m) {
	out << std::fixed << std::setprecision(0) << std::setw(2) << m.getDay()
	<< std::setw(2) << m.getMonth()
	<< std::setw(4) << m.getYear();
	return out;
}
