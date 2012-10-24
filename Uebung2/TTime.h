/*
 * TTime.h
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */

#ifndef TTIME_H_
#define TTIME_H_

class TTime {
public:
	TTime();
	TTime(int hour, int min, int sec);
	virtual ~TTime();

	int setTime(int hour, int min, int sec);
	int getHour() const;
	//void setHour(int hour);
	int getMin() const;
	//void setMin(int min);
	int getSec() const;
	//void setSec(int sec);
	void print();

private:
	int sec;
	int min;
	int hour;
};

#endif /* TTIME_H_ */
