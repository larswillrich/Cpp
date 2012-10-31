/*
 * TDate.h
 *
 *  Created on: 05.10.2012
 *      Author: Lars Willrich
 */

#ifndef TDATE_H_
#define TDATE_H_

class TDate {
public:
	TDate();
	TDate(int day, int month, int year);
	virtual ~TDate();

    int setDate(int day, int month, int year);
    int getDay() const;
    //void setDay(int day);
    int getMonth() const;
    //void setMonth(int month);
    int getYear() const;
    //void setYear(int year);
    void print();

private:
    int day;
    int month;
    int year;
};

#endif /* TDATE_H_ */
