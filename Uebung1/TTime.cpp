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

	setHour(ts->tm_hour);
	setMin(ts->tm_min);
	setSec(ts->tm_sec);
}

TTime::TTime(int hour, int min, int sec) {

	setHour(hour);
	setMin(min);
	setSec(sec);
}

TTime::~TTime() {
}

int TTime::getHour() const {
	return hour;
}

void TTime::setHour(int hour) {
	this->hour = hour;
}

int TTime::getMin() const {
	return min;
}

void TTime::setMin(int minute) {
	this->min = min;
}

int TTime::getSec() const {
	return sec;
}

void TTime::setSec(int sec) {
	this->sec = sec;
}

void TTime::print() {
	printf("%.2i:%.2i:%.2i", getHour(), getMin(), getSec());
}
