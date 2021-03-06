/*
 * TMoney.h
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#ifndef TMONEY_H_
#define TMONEY_H_

#include <string>
class TMoney {
public:
	TMoney(double amount, char* currency = "EUR");
	virtual ~TMoney();
	void setAmount(double amount);
	double getAmount();
	void setCurrency(char* currency);
	char* getCurrency();
	std::string toString();
	//Geldbetrag manipulieren
	void addValue(double value);

	void print();

private:
	double amount;
	char* currency;
};

#endif /* TMONEY_H_ */
