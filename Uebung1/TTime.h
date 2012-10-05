/*
 * TTime.h
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */

#ifndef TTIME_H_
#define TTIME_H_
#include <string>

class TTime {
public:
	TTime();
	virtual ~TTime();

	int second;
	int minute;
	int hour;

	int getHour() const {
		return hour;
	}

	void setHour(int hour) {
		this->hour = hour;
	}

	int getMinute() const {
		return minute;
	}

	void setMinute(int minute) {
		this->minute = minute;
	}

	int getSecond() const {
		return second;
	}

	void setSecond(int second) {
		this->second = second;
	}
};

#endif /* TTIME_H_ */
