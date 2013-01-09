/*
 * TTime.cpp
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */

#include "TTime.h"
#include <time.h>
#include <stdio.h>

TTime::TTime() {
	time_t rawTime;
	struct tm *ts;

	rawTime = time(NULL);
	ts = localtime(&rawTime);

	int res = setTime(ts->tm_hour, ts->tm_min, ts->tm_sec);
}

TTime::TTime(int hour, int min, int sec) {
	int res = setTime(hour, min, sec);

	if (res != 0){
		setTime(00, 00, 00);
		printf("Eingegebene Uhrzeit ist invalide, Eingabe wurde auf 00:00:00 gesetzt.\n");
	}
}

TTime::~TTime() {
}

int TTime::setTime(int hour, int min, int sec){

	if (hour > 24 || min > 59 || sec > 59) return -1;

	this->hour = hour;
	this->min = min;
	this->sec = sec;

	return 0;
}

int TTime::getHour() const {
	return hour;
}

int TTime::getMin() const {
	return min;
}

int TTime::getSec() const {
	return sec;
}

std::string TTime::toString(){
	char buffer [8];
	sprintf (buffer, "%.2i:%.2i:%.2i", getHour(), getMin(), getSec());

	std::string ret = buffer;
	return ret;
}


void TTime::print() {
	printf("%.2i:%.2i:%.2i", getHour(), getMin(), getSec());
}
