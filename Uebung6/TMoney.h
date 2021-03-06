/*
 * TMoney.h
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#ifndef TMONEY_H_
#define TMONEY_H_

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class TMoney {
public:
	TMoney(double amount, const char* currency = "EUR");
	virtual ~TMoney();
	void setAmount(double amount);
	double getAmount();
	void setCurrency(const char* currency);
	const char* getCurrency();
	std::string toString();
	//Geldbetrag manipulieren
	void addValue(double value);
	friend ostream& operator<<(ostream & out, TMoney m);
	void print();

private:
	double amount;
	const char* currency;
};

#endif /* TMONEY_H_ */
